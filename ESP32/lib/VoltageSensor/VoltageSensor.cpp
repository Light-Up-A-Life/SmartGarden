#include "VoltageSensor.h"

bool VoltageSensor::setUp() {
  Serial.println(Sensor::getPins().begin()->first);
  return true;
}
float VoltageSensor::getBatteryVoltage() { return 0.0; }
float VoltageSensor::getSolarPanelVoltage() { return 0.0; }
float VoltageSensor::getSensorData() {
  float digital_value = analogRead(Sensor::getPins().begin()->first);
  if (magnitude_type == "battery_voltage")
    return getBatteryVoltage();
  else if (magnitude_type == "solarpanel_voltage")
    return getSolarPanelVoltage();
  else
    return -1.0;
  }