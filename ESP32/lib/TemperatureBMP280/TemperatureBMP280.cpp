#include "TemperatureBMP280.h"

bool TempBmp280::setUp(){
  if (!bmp.begin()){
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    bFailure = true;
    return false;
  }
  return true;
}

float TempBmp280::getSensorData(){
  if(magnitude_type== "Temperature")
    return bmp.readTemperature();
  else
    return bmp.readPressure();
}