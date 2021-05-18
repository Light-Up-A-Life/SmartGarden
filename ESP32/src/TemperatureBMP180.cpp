#include "TemperatureBMP180.h"

bool TempBmp180::setUp(){
  if (!bmp.begin()){
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    bFailure = true;
    return false;
  }
  return true;
}

float TempBmp180::getSensorData(){
  if(data_== "Temperature")
    return bmp.readTemperature();
  else
    return bmp.readPressure();
} 

