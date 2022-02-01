#include "VoltageSensor.h"


bool VoltageSensor::setUp() {
  Serial.println(Sensor::getPins().begin()->first);
  return true;
}

float VoltageSensor::mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float VoltageSensor::genericVoltageRead (){
  float valueInvoltsfromBytes = analogRead(Sensor::getPins().begin()->first) ;
  return mapFloat(valueInvoltsfromBytes, 0, 4095, 0, 3.3);
}

float VoltageSensor::getBatteryVoltage() { 
  return gainBatteryVoltage*genericVoltageRead();
}

float VoltageSensor::getSolarPanelVoltage() {
  return gainSolarPanelVoltage*genericVoltageRead();
}

float VoltageSensor::getSolarPanelCurrent() {
  return mapFloat(genericVoltageRead(), 0, 5.0, -5, 5) ;
}


float VoltageSensor::getSensorData() {

  if (magnitude_type == "Voltage_bat")
    return getBatteryVoltage();
  else if (magnitude_type == "Voltage_panel")
    return getSolarPanelVoltage();
  else if (magnitude_type == "Current_panel")
    return getSolarPanelCurrent();
  else
    return -1.0;
  }