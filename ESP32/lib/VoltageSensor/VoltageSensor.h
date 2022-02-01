#ifndef VOLTAGE_SENSOR_H
#define VOLTAGE_SENSOR_H

#include "Sensor.h"

class VoltageSensor : public Sensor {
public:
  using Sensor::Sensor;
  bool setUp() override;
  float getSensorData() override;

private:
  float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) ;
  float genericVoltageRead();
  float getBatteryVoltage();
  float getSolarPanelVoltage();
  float getSolarPanelCurrent();

  float gainSolarPanelVoltage = 1.0; 
  float gainSolarPanelCurrent = 1.0;

  float gainBatteryVoltage = 12.39/2.746; // 12.63/2.15; 

  std::string data_;
  float alpha_;
};

#endif
