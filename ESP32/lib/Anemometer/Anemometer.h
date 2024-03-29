#ifndef ANEMOMETER_H
#define ANEMOMETER_H

#include "Sensor.h"

class Anemometer : public Sensor {
public:
  using Sensor::Sensor;
  bool setUp() override;
  float getSensorData() override;
  float mapFloat(float x, float in_min, float in_max, float out_min,
                 float out_max);
  volatile unsigned long Rotations =
      0; // cup rotation counter used in interrupt routine
  volatile unsigned long
      ContactBounceTime; // Timer to avoid contact bounce in interrupt routine
private:
  float getWindSpeedMph();
  float getWindSpeedMpers();
  float getWindDirection();

  std::string data_;

  
  
  //OLD
  float offset = 0;
  float gain_wind_direction = 1.665 / 2.697;
  float vol_max_output = 3.18;
  float vol_max_input = 5.0;

  // SPEED
  float TperiodWindSpeed = 0.5; // seconds

  //DIRECTION
  int Offset = 180;
};

#endif
