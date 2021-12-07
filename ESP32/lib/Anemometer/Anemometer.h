#ifndef ANEMOMETER_H
#define ANEMOMETER_H

#include "Sensor.h"


class Anemometer : public Sensor{
  public:
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
    float mapFloat(float x, float in_min, float in_max, float out_min, float out_max);
  private:
    std::string data_;
    float offset = 1.0;
    float gain_wind_direction = 1.665/2.697;
    float vol_max_output = 3.18;
    float vol_max_input = 5.0;
};

#endif
