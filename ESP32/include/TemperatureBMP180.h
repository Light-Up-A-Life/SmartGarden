#ifndef TEMPERATUREBMP180_H
#define TEMPERATUREBMP180_H
#include "Sensor.h"
#include <Adafruit_BMP085.h> 


class TempBmp180 : public Sensor{
  public:
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
  private:
    Adafruit_BMP085 bmp;
    std::string data_;
};
  
#endif


