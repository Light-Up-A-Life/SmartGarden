#include "VoltageSensor.h"

bool VoltageSensor::setUp() { 
    Serial.println(Sensor::getPins().begin()->first);
    return true; }

float VoltageSensor::getSensorData() {
  float digital_value = analogRead(Sensor::getPins().begin()->first);
  return digital_value*alpha_;
}