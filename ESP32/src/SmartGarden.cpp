#include "GsmModule.h"
#include "SdCard.h"
#include "Sensor.h"
#include "TemperatureBMP180.h"
#include "SoilMoisture.h"

#include "time.h"
#include <SPI.h>

std::vector<Sensor *> listSensor;
TempBmp180 t1 = TempBmp180("temp180_temperature", "Temperature",
                           {{21, "bmp180_sda"}, {22, "bmp180_scl"}}, 60);
TempBmp180 t2 = TempBmp180("temp180_pressure", "Pressure",
                           {{21, "bmp180_sda"}, {22, "bmp180_scl"}}, 60);
SoilMoisture s1 = SoilMoisture("soil_moisture_1","Moisture level",{{34,"soil_moisture_avot"}},60);
SdCard sd = SdCard(
    "SdCard0", "Storage",
    {{5, "sd_cs"}, {18, "sd_clk"}, {23, "sd_mosi"}, {19, "sd_miso"}}, 60);
GsmModule gsm =
    GsmModule("GsmModule", "Time", {{16, "gsm_tx"}, {17, "gsm_rx"}}, 60);


QueueHandle_t queue;

// Duration values for the different events
const long SECOND_MS = 1000;    // Real value: 1k
const long MINUTE_MS = 10000;   // Real value: 60k
const long HOUR_MS = 600000000; // Real value: 3.6M

unsigned long previousMillisMinute = 0, previousMillisHour = 0,
              previousMillisSec = 0;

bool minutePassedEvent, hourPassedEvent, secPassedEvent;

void timeCount(void *parameter) {
  for (;;) {
    // Counts real time from start and triggers time based events
    unsigned long currentMillis = millis();
    int eventCallback;

    if (currentMillis - previousMillisSec >= SECOND_MS) {
      previousMillisSec = currentMillis;
      eventCallback = 1;
      xQueueSend(queue, &eventCallback, portMAX_DELAY);
    }

    if (currentMillis - previousMillisMinute >= MINUTE_MS) {
      previousMillisMinute = currentMillis;
      eventCallback = 2;
    }

    if (currentMillis - previousMillisHour >= HOUR_MS) {
      previousMillisHour = currentMillis;
      eventCallback = 3;
    }
  }
}

void setup() {
  Serial.begin(115200);
  if (t1.setUp()) {
    listSensor.push_back(&t1);
    Serial.println("setup done t1");
  } 
  else {
    Serial.println("setup not done t1");
  }

  if(t2.setUp()){
    listSensor.push_back(&t2);
    Serial.println("setup done t2");
  }
  else{
      Serial.println("setup not done t2");
  }
  if(s1.setUp()){
    listSensor.push_back(&s1);
    Serial.println("setup done s1");
  } 
  else {
    Serial.println("setup not done s1");
  }

  /*if(sd.setUp()){
    listSensor.push_back(&t2);
    Serial.println("setup done sd card");
  }
  else{
    Serial.println("setup not done sd card");
  }
  Serial.println("Welcome to Smart Garden");*/
  // gsm.setUp();
  queue = xQueueCreate(10, sizeof(int));

  if (queue == NULL) {
    Serial.println("Error creating the queue");
  }

  xTaskCreate(timeCount,    /* Task function. */
              "TimeCount", /* String with name of task. */
              10000,        /* Stack size in words. */
              NULL,         /* Parameter passed as input of the task */
              1,            /* Priority of the task. */
              NULL);
}
void loop() {
  int timerCallback = 0;
  xQueueReceive(queue, &timerCallback, portMAX_DELAY);
  if (timerCallback == 1) {
    for (Sensor *s : listSensor) {
      float v = s->read(20);
      Serial.printf("name %s \t", s->name.c_str());
      Serial.printf("value %0.3f \n", v);
    }
  }
}
/*
TODO:
GPS as service
Data each second
enum queue option
SD save 
GSM get/request
*/
