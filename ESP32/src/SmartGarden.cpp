#include "Anemometer.h"
#include "Display.h"
#include "GsmModule.h"
#include "SdCard.h"
#include "Sensor.h"
#include "SoilMoisture.h"
#include "TempExt.h"
#include "TemperatureBMP180.h"
#include "WifiModule.h"
#include "VoltageSensor.h"

#include "time.h"
#include <SPI.h>
#include <queue>

// Const Wifi
const std::string wlan_ssid = "SFR_6608";
const std::string wlan_pass = "2cwt45yriv2urm57trbx";
/*
const std::string wlan_ssid = "AlejoPhone";
const std::string wlan_pass = "youdonthaveinternet";
*/
const uint16_t port = 10026;
const char *host = "91.68.60.139";

// Duration values for the different events
const long SECOND_MS = 1000;           // Real value: 1k
const long MINUTE_MS = 60000; // Real value: 60k
const long HOUR_MS =   3600000;     // Real value: 3.6M
const int size_stack = MINUTE_MS / 1000;

std::vector<Sensor *> listSensor;


// ------------------------------ //
//   Sensor objects creation      //
// ------------------------------ //

// function inputs: string name, string nameDisplay, string magn_type, ... 

TempBmp180 t1 =
    TempBmp180("temp180_temp", "Temp1", "Temperature",
               {{21, "bmp180_sda"}, {22, "bmp180_scl"}}, size_stack);
TempBmp180 t2 =
    TempBmp180("temp180_pressure", "Press", "Pressure",
               {{21, "bmp180_sda"}, {22, "bmp180_scl"}}, size_stack);

TempExt t_ext = TempExt("tempDS18B20_ext", "TempE", "Temperature_extern",
                        {{33, "temp_DS18B20_ext"}}, size_stack);

Anemometer anem = Anemometer("anemometer_speed", "WindS", "Wind_speed",
                             {{32, "wind_speed"}}, size_stack);

Anemometer anem_dir = Anemometer("anemometer_dir", "WindD", "Wind_dir",
                             {{35, "wind_direction"}}, size_stack);

VoltageSensor bat_volt = VoltageSensor("bat_voltage", "BatVo", "Voltage_bat",
                             {{34, "bat_voltage"}}, size_stack);

VoltageSensor panel_volt = VoltageSensor("panel_voltage", "PanVo", "Voltage_panel",
                             {{39, "panel_voltage"}}, size_stack);

VoltageSensor panel_current = VoltageSensor("panel_current", "PanCurr", "Current_panel",
                             {{4, "panel_current"}}, size_stack);


// ------------------------------ //
//  Communication means creation  //
// ------------------------------ //

SdCard sd =
    SdCard("SdCard0", "Storage", "Storage",
           {{5, "sd_cs"}, {18, "sd_clk"}, {23, "sd_mosi"}, {19, "sd_miso"}},
           size_stack);

GsmModule gsm = GsmModule("GsmModule", "GsmModule", "Time",
                          {{16, "gsm_tx"}, {17, "gsm_rx"}}, size_stack);

Display disp;

WifiModule wifiModule;

// ------------------------------ //

QueueHandle_t queue;

String sd_msg = "";
String server_msg = "";

unsigned long previousMillisMinute = 0, previousMillisHour = 0,
              previousMillisSec = 0;

bool minutePassedEvent, hourPassedEvent, secPassedEvent;
unsigned long  sec = 0;
unsigned long  minute = 0;
unsigned long  hours = 0;

/*
String createJSON() {

  // Sending data to SD card & to server 
  String server_msg_JSON = "{\"Time\": " + (String)minute;
  for (Sensor *s : listSensor) {
    float v = s->callbackMinute();
    server_msg_JSON =
          server_msg_JSON + ",\"" + String(s->name.c_str()) + "\": " + String(v);
  }
  server_msg_JSON = server_msg_JSON + "}";
  return server_msg_JSON;
}
*/ 

void isr_rotation() {
  if ((millis() - anem.ContactBounceTime) > 15 ) { // debounce the switch contact.
  anem.Rotations++;
  anem.ContactBounceTime = millis();
  // Serial.print(Rotations);
  //Serial.print(" ... ");
  }
}

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
      server_msg = "{\"Time\": " + (String)minute;
      eventCallback = 2;
      sec = 0;
      xQueueSend(queue, &eventCallback, portMAX_DELAY);
    }

    if (currentMillis - previousMillisHour >= HOUR_MS) {
      previousMillisHour = currentMillis;
      eventCallback = 3;
<<<<<<< HEAD
      server_msg = "Time(hours)=" + (String)++hours;
      minute = 0;
=======
      server_msg = "{\"Time\": " + (String)minute;
>>>>>>> 3342d1d43e785f494de1ffd331562d24b31ef248
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
      Serial.printf("Time: %02d:%02d:%02d\n", hours, minute ,sec );
      // Serial.printf("Time GSM: %s\n", gsm.getClock());
      // String pos = gsm.getPosition();
      // Serial.printf("Position GSM: %s\n", pos);

      for (Sensor *s : listSensor) {
        s->read(1);
        /*
        float v = s->getValue();
        Serial.printf("name %s \t", s->name.c_str());
        Serial.printf("value %0.3f \n", v);
        */
      }
      Serial.println("");
      
    } else if (option == 2) {
      Serial.printf("Minute passing \n");
      server_msg = "{\"Time\": \"" + (String)hours + ":" + (String)minute + ":" + (String)sec + "\"";

      for (Sensor *s : listSensor) {
        float v = s->callbackMinute();
        Serial.printf("name %s \t", s->name.c_str());
        Serial.printf("value %0.3f \n", v);
        sd_msg = sd_msg + "," + String(v);
<<<<<<< HEAD
        
        server_msg =
             server_msg + ",\"" + String(s->name.c_str()) + "\": " + String(v);

        /*server_msg = 
             server_msg + "&" + String(s->name.c_str()) + "=" + String(v);
        */
=======
        server_msg =
             server_msg + ",\"" + String(s->name.c_str()) + "\": " + String(v);
>>>>>>> 3342d1d43e785f494de1ffd331562d24b31ef248
        // clientS.msg_tx[s->name.c_str()]= v;
      }
      server_msg = server_msg + "}";
      sd.appendSD(sd_msg);
      Serial.println(sd_msg);
      Serial.println(server_msg);
      gsm.sendToServer(server_msg);
<<<<<<< HEAD

      // Sending a I'm alive message every x minutes
      /*
      if (minute % 30 == 0){
        server_msg = "Minka logger alive (" +  (String)hours + ":" + (String)minute + ":" + (String)sec + ")";
        gsm.sendSMS(server_msg);
      }
      */ 
     
=======
>>>>>>> 3342d1d43e785f494de1ffd331562d24b31ef248
      /*
      if (wifiModule.connectToServer(host,port)){
        wifiModule.client.print(server_msg);
        wifiModule.client.stop();
      }
      */
    } else if (option == 3) {
      
      Serial.printf("Hour passing \n");
      server_msg = "Minka logger alive (" +  (String)hours + ":" + (String)minute + ":" + (String)sec + ")";
      gsm.sendSMS(server_msg);
      /*
      
      for (Sensor *s : listSensor) {
        float v = s->callbackMinute();
        Serial.printf("name %s \t", s->name.c_str());
        Serial.printf("value %0.3f \n", v);
        server_msg =
             server_msg + ",\"" + String(s->name.c_str()) + "\": " + String(v);
      }
      */
      

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

  /*
  while(1){
    Serial.println("-----Message------");
    server_msg = "Minka logger alive";
    gsm.sendSMS(server_msg);
    delay(5000);
    
    Serial.println("-------------------");
    Serial.println("");
  }
  */

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
    attachInterrupt(digitalPinToInterrupt(32), isr_rotation, FALLING);

    Serial.println("setup done anem");
  } else {
    Serial.println("setup not done anem");
  }
  if (anem_dir.setUp()) {
    listSensor.push_back(&anem_dir);
    Serial.println("setup done anem direction");
  } else {
    Serial.println("setup not done anem direction");
  }
  if (panel_volt.setUp()) {
    listSensor.push_back(&panel_volt);
    Serial.println("setup done panel voltage");
  } else {
    Serial.println("setup not done panel voltage");
  }
  if (panel_current.setUp()) {
    listSensor.push_back(&panel_current);
    Serial.println("setup done panel current");
  } else {
    Serial.println("setup not done panel current");
  }

  if (bat_volt.setUp()) {
    listSensor.push_back(&bat_volt);
    Serial.println("setup done battery voltage");
  } else {
    Serial.println("setup not done battery voltage");
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
  
  if (disp.setup()){
    Serial.println("setup done main display");
  } else{
    Serial.println("setup not done main display");
  }

  /*
  wifiModule.connectToWiFi(wlan_ssid,wlan_pass);
  if (wifiModule.connectToServer(host,port)){
    Serial.println("Connection to host success");
  } else{
    Serial.println("Connection to host failed");
  }
  */
<<<<<<< HEAD

  queue = xQueueCreate(100, sizeof(int));

  if (queue == NULL) {
    Serial.println("Error creating the queue");
  }

=======
>>>>>>> 3342d1d43e785f494de1ffd331562d24b31ef248
  Serial.println("");
  Serial.println("*------------------------------*");
  Serial.println("*    Welcome to Smart Garden   *");
  Serial.println("*------------------------------*");
  Serial.println("");

<<<<<<< HEAD
  // Final reset before launch 
  /*
  previousMillisSec = 0;
  previousMillisMinute = 0;
  previousMillisHour = 0;
=======
  queue = xQueueCreate(100, sizeof(int));
>>>>>>> 3342d1d43e785f494de1ffd331562d24b31ef248

  secPassedEvent = false;
  minutePassedEvent = false;
  hourPassedEvent = false;

  sec = 0;
  minute = 0;
  hours = 0;
  */

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
                    
  xTaskCreatePinnedToCore(
      mainDisplay,  // Task function.
      "MainDisplay",// String with name of task.
      10000,        // Stack size in words.
      NULL,         // Parameter passed as input of the task
      1,            // Priority of the task.
      &DisplayTask, // Task handle to keep track of created task
      1);           // pin task to core 1
      
}

void loop() { vTaskDelete(NULL); }




