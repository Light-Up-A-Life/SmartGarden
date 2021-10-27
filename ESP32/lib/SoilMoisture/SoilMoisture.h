#ifndef SOILMOISTURE_H
#define SOILMOISTURE_H
#include "Sensor.h"


class SoilMoisture : public Sensor{
  public:
  
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;

    int readSoilMoistureRaw();
    float readSoilMoistureVolts();
    float readSoilMoisturePercetage();

  private:
    std::string data_;
    const int air_value = 3500;
    const int water_value = 1280; 
};
#endif