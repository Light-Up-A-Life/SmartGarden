#include <SPI.h>
#include "time.h"
#include "Sensor.h"
#include "TemperatureBMP180.h"

std::vector<Sensor*> listSensor;
TempBmp180  t1 = TempBmp180("temp180_temperature",60,{{21,"bmp180_sda"},{22,"bmp180_scl"}},"Temperature");
TempBmp180  t2 = TempBmp180("temp180_pressure",60,{{21,"bmp180_sda"},{22,"bmp180_scl"}},"Pressure");



// Duration values for the different events
const long SECOND_MS = 1000;        // Real value: 1k
const long MINUTE_MS = 10000;       // Real value: 60k
const long HOUR_MS   = 600000000;   // Real value: 3.6M

unsigned long previousMillisMinute = 0,
              previousMillisHour = 0,
              previousMillisSec = 0;

bool minutePassedEvent,
     hourPassedEvent,
     secPassedEvent;

void timeCount() {
  //Counts real time from start and triggers time based events
  unsigned long currentMillis = millis();
  minutePassedEvent = false;
  hourPassedEvent = false;
  secPassedEvent = false;

  if (currentMillis - previousMillisSec >= SECOND_MS)
  {
    previousMillisSec = currentMillis;
    secPassedEvent = true;
    for(Sensor * s: listSensor){
      float v = s->read(20);
      Serial.printf("name %s \t",s->name);
      Serial.printf("value %0.3f \n",v);
    }
  }

  if (currentMillis - previousMillisMinute >= MINUTE_MS)
  {
    previousMillisMinute = currentMillis;
    minutePassedEvent = true;
  }

  if (currentMillis - previousMillisHour >= HOUR_MS)
  {
    previousMillisHour = currentMillis;
    hourPassedEvent = true;
  }
}
void setup (){
  Serial.begin(115200);
  if(t1.setUp()){
      listSensor.push_back(&t1);
    Serial.println("setup done t1");
  }
  else{
      Serial.println("setup not done t1");
  }
  if(t2.setUp()){
    listSensor.push_back(&t2);
    Serial.println("setup done t2");
  }
  else{
      Serial.println("setup not done t2");
  }
  Serial.println("Welcome to Smart Garden");
}
void loop(){
  delay(1000);
  timeCount();
  //Serial.println(listSensor.size());
}
