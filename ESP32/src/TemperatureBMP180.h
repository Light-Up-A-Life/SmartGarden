#ifndef TEMPERATUREBMP180_H
#define TEMPERATUREBMP180_H
#include "Sensor.h"
#include <Adafruit_BMP085.h> 


class TempBmp180 : public Sensor{
  public:
    TempBmp180(std::string name, int size_stack, std::map<int,std::string> pins, std::string data);
    bool setUp();
    float getSensorData() override;
  private:
    Adafruit_BMP085 bmp;
    std::string data_;
};
  
#endif


