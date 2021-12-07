#ifndef TEMPEXT_H
#define TEMPEXT_H
#include "Sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class TempExt : public Sensor{
  public:
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
  private:
    std::string data_;
    OneWire wire;
    DallasTemperature sensor;

}; // sensor DS18B20

#endif
