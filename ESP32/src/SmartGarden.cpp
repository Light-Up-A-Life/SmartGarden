#include "Anemometer.h"
#include "Display.h"
#include "GsmModule.h"
#include "SdCard.h"
#include "Sensor.h"
#include "SoilMoisture.h"
#include "TempExt.h"
#include "TemperatureBMP180.h"
#include "WifiModule.h"

#include "time.h"
#include <SPI.h>
#include <queue>

// Const Wifi
/*
const std::string wlan_ssid = "SFR_6608";
const std::string wlan_pass = "2cwt45yriv2urm57trbx";
*/
const std::string wlan_ssid = "AlejoPhone";
const std::string wlan_pass = "youdonthaveinternet";
const uint16_t port = 10026;
const char *host = "91.68.60.139";

// Duration values for the different events
const long SECOND_MS = 1000;           // Real value: 1k
const long MINUTE_MS = 60000; // Real value: 60k
const long HOUR_MS = 3600000;     // Real value: 3.6M
const int size_stack = MINUTE_MS / 1000;

std::vector<Sensor *> listSensor;

TempBmp180 t1 =
    TempBmp180("temp180_temperature", "Temp1", "Temperature",
               {{21, "bmp180_sda"}, {22, "bmp180_scl"}}, size_stack);
TempBmp180 t2 =
    TempBmp180("temp180_pressure", "Press", "Pressure",
               {{21, "bmp180_sda"}, {22, "bmp180_scl"}}, size_stack);
SoilMoisture s1 = SoilMoisture("soil_moisture_1", "Soil1", "Moisture level",
                               {{34, "soil_moisture_avot"}}, size_stack);
SdCard sd =
    SdCard("SdCard0", "Storage", "Storage",
           {{5, "sd_cs"}, {18, "sd_clk"}, {23, "sd_mosi"}, {19, "sd_miso"}},
           size_stack);

GsmModule gsm = GsmModule("GsmModule", "GsmModule", "Time",
                          {{16, "gsm_tx"}, {17, "gsm_rx"}}, size_stack);

TempExt t_ext = TempExt("tempDS18B20_ext", "TempE", "Temperature_extern",
                        {{33, "temp_DS18B20_ext"}}, size_stack);

Anemometer anem = Anemometer("anemometer_wind", "Wind", "Wind_direction",
                             {{32, "wind_direction"}}, size_stack);

QueueHandle_t queue;

Display disp;

WifiModule wifiModule;

String sd_msg = "";
String server_msg = "";
unsigned long previousMillisMinute = 0, previousMillisHour = 0,
              previousMillisSec = 0;

bool minutePassedEvent, hourPassedEvent, secPassedEvent;
int sec = 0;
int minute = 0;
int hours = 0;

void timeCount(void *parameter) {
  for (;;) {
    // Counts real time from start and triggers time based events
    unsigned long currentMillis = millis();
    int eventCallback;

    if (currentMillis - previousMillisSec >= SECOND_MS) {
      previousMillisSec = currentMillis;
      eventCallback = 1;
      // Serial.printf("millisSec %ld \n", previousMillisSec);
      // Serial.println(xPortGetCoreID());
      xQueueSend(queue, &eventCallback, portMAX_DELAY);
    }

    if (currentMillis - previousMillisMinute >= MINUTE_MS) {
      previousMillisMinute = currentMillis;
      sd_msg = (String)++minute;
      server_msg = "Time(min)=" + (String)minute;
      eventCallback = 2;
      xQueueSend(queue, &eventCallback, portMAX_DELAY);
    }

    if (currentMillis - previousMillisHour >= HOUR_MS) {
      previousMillisHour = currentMillis;
      eventCallback = 3;
      server_msg = "Time(hours)=" + (String)++hours;
      xQueueSend(queue, &eventCallback, portMAX_DELAY);
    }
    vTaskDelay(25 / portTICK_PERIOD_MS);
  }
}

void eventCheck(void *parameter) {
  int option = 0;
  for (;;) {
    xQueueReceive(queue, &option, portMAX_DELAY);
    if (option == 1) {
      Serial.printf("Second passing %d \n", ++sec % 60);
      for (Sensor *s : listSensor) {
        s->read(1);
        /*
        float v = s->getValue();
        Serial.printf("name %s \t", s->name.c_str());
        Serial.printf("value %0.3f \n", v);
        */
      }
    } else if (option == 2) {
      Serial.printf("Minute passing \n");

      for (Sensor *s : listSensor) {
        float v = s->callbackMinute();
        Serial.printf("name %s \t", s->name.c_str());
        Serial.printf("value %0.3f \n", v);
        sd_msg = sd_msg + "," + String(v);
        server_msg = 
             server_msg + "&" + String(s->name.c_str()) + "=" + String(v);
        // clientS.msg_tx[s->name.c_str()]= v;
      }
      sd.appendSD(sd_msg);
      Serial.println(sd_msg);
      Serial.println(server_msg);
      gsm.sendToServer(server_msg);

      /*
      if (wifiModule.connectToServer(host,port)){
        wifiModule.client.print(server_msg);
        wifiModule.client.stop();
      }
      */

      // wifiModule.sendDataToGoogle(server_msg);
    } else if (option == 3) {
      for (Sensor *s : listSensor) {
        float v = s->callbackMinute();
        Serial.printf("name %s \t", s->name.c_str());
        Serial.printf("value %0.3f \n", v);
        server_msg =
            server_msg + "&" + String(s->name.c_str()) + "=" + String(v);
      }
      gsm.sendSMS(server_msg);

    }
    else{
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void mainDisplay(void *parameter) {

  for (;;) {
    /*
    for (Sensor *s : listSensor) {
      float v = s->read(10);
      Serial.printf("Display for sensor %s \n", s->name.c_str());
      //
      // Serial.printf("name %s \t", s->name.c_str());
      // Serial.printf("value %0.3f \n", v);
    }
    */
    disp.displayLoop(listSensor);
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);

  if (gsm.setUp()) {
    Serial.println("setup done gsm");
  } else {
    Serial.println("setup not done gsm");
  }
  if (t1.setUp()) {
    listSensor.push_back(&t1);
    Serial.println("setup done t1");
  } else {
    Serial.println("setup not done t1");
  }
  if (t2.setUp()) {
    listSensor.push_back(&t2);
    Serial.println("setup done t2");
  } else {
    Serial.println("setup not done t2");
  }
  if (t_ext.setUp()) {
    listSensor.push_back(&t_ext);
    Serial.println("setup done t_ext");
  } else {
    Serial.println("setup not done t_ext");
  }
  if (anem.setUp()) {
    listSensor.push_back(&anem);
    Serial.println("setup done anem");
  } else {
    Serial.println("setup not done anem");
  }
  if (s1.setUp()) {
    listSensor.push_back(&s1);
    Serial.println("setup done s1");
  } else {
    Serial.println("setup not done s1");
  }

  if (sd.setUp()) {
    Serial.println("setup done sd card");
  } else {
    Serial.println("setup not done sd card");
  }
  String encabezado = "time,";
  for (Sensor *s : listSensor) {
    encabezado = encabezado + String(s->name.c_str()) + ",";
  }
  Serial.println(sd.writeSD(encabezado));
  Serial.println("Welcome to Smart Garden");
  /*
  if (disp.setup()){
    Serial.println("setup done main display");
  } else{
    Serial.println("setup not done main display");
  }

  wifiModule.connectToWiFi(wlan_ssid,wlan_pass);
  if (wifiModule.connectToServer(host,port)){
    Serial.println("Connection to host success");
  } else{
    Serial.println("Connection to host failed");
  }
  */

  Serial.println("");
  Serial.println("*------------------------------*");
  Serial.println("*    Welcome to Smart Garden   *");
  Serial.println("*------------------------------*");
  Serial.println("");

  // gsm.setUp();
  queue = xQueueCreate(100, sizeof(int));

  if (queue == NULL) {
    Serial.println("Error creating the queue");
  }

  TaskHandle_t ClockTask;
  TaskHandle_t CheckTask;
  TaskHandle_t DisplayTask;

  xTaskCreatePinnedToCore(
      timeCount,   // Task function.
      "TimeCount", // String with name of task.
      10000,       // Stack size in words.
      NULL,        // Parameter passed as input of the task
      1,           // Priority of the task.
      &ClockTask,  // Task handle to keep track of created task
      0);          // pin task to core 0
  xTaskCreatePinnedToCore(
      eventCheck,   // Task function.
      "EventCheck", // String with name of task.
      10000,        // Stack size in words.
      NULL,         // Parameter passed as input of the task
      2,            // Priority of the task.
      &CheckTask,   // Task handle to keep track of created task
      1);           // pin task to core 1
                    /*
                xTaskCreatePinnedToCore(
                    mainDisplay,   // Task function.
                    "MainDisplay", // String with name of task.
                    10000,        // Stack size in words.
                    NULL,         // Parameter passed as input of the task
                    1,            // Priority of the task.
                    &DisplayTask, // Task handle to keep track of created task
                    1);           // pin task to core 1
                    */
}

void loop() { vTaskDelete(NULL); }

/*
TODO:
GPS as service
Data each second
enum queue option
SD save
GSM get/request
*/
