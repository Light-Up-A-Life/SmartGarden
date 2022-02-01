#ifndef TEMPERATUREBMP280_H
#define TEMPERATUREBMP280_H
#include "Sensor.h"
#include <Adafruit_BMP280.h> 


class TempBmp280 : public Sensor{
  public:
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
  private:
    Adafruit_BMP280 bmp;
    std::string data_;
};
#endif


