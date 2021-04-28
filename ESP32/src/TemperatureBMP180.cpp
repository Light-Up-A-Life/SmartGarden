#include "TemperatureBMP180.h"

TempBmp180::TempBmp180(std::string name, int size_stack, std::map<int,std::string> pins, std::string data):
  Sensor::Sensor(name,pins,size_stack),
  data_(data){}
  
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

