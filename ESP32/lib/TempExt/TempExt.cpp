#include "TempExt.h"

bool TempExt::setUp(){
    const int pin = Sensor::getPins().begin()->first;
    Serial.printf("Pin sensor DS18B20 %d \n", pin);
    
    wire = OneWire(pin);
    sensor = DallasTemperature (&wire);
    sensor.begin();
  return true;
}

float TempExt::getSensorData(){
    sensor.requestTemperatures(); 
    return sensor.getTempCByIndex(0);
}