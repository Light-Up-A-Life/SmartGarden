#ifndef VOLTAGE_SENSOR_H
#define VOLTAGE_SENSOR_H

#include "Sensor.h"

class VoltageSensor : public Sensor{
  public:
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
  private:
    std::string data_;
    float alpha_;
};

#endif
