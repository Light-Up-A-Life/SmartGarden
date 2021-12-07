#include "Anemometer.h"

bool Anemometer::setUp() { 
    Serial.println(Sensor::getPins().begin()->first);
    return true; }

float Anemometer::mapFloat (float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float Anemometer::getSensorData() {
  float digital_value = analogRead(Sensor::getPins().begin()->first);
  float analog_value_output = mapFloat(digital_value, 0, 4095, 0, 3.3); 
  float analog_value_input = analog_value_output /  gain_wind_direction;
  float cal_direction = mapFloat(analog_value_input, 0, vol_max_input, 0, 360) + offset;

  if (cal_direction > 360)
    cal_direction = cal_direction - 360;

  if (cal_direction < 0)
    cal_direction = cal_direction + 360;

    return cal_direction;
}