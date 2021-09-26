#include "SoilMoisture.h"

bool SoilMoisture::setUp()
{
  
  Serial.printf("Pin Moisture %d \n", Sensor::getPins().begin()->first);
  return true;
}

int SoilMoisture::readSoilMoistureRaw()
{
  // Returns measurement in 12 bits coding
  return analogRead(34); 
}

float SoilMoisture::readSoilMoistureVolts()
{
  // Returns mesurement in voltage. NodeMCU works ar 3.3V. For a 5V system, equation shall change.
  return readSoilMoistureRaw() * 3.3 / 4095; 
}

float SoilMoisture::readSoilMoisturePercetage()
{
  // MIN/MAX values are according to test measurements in Joses garden. A dryer or wetter day can occure, therefore % above 100 are possible.
  return constrain((SoilMoisture::readSoilMoistureRaw() - air_value) * (100) / (water_value - air_value), -100, 200); 
}
float SoilMoisture::getSensorData()
{
    return SoilMoisture::readSoilMoisturePercetage();
}