#ifndef SDCARD_H
#define SDCARD_H

#include "SD.h"
#include <SPI.h>

#include "Sensor.h"

class SdCard : public Sensor{
  public:
    SdCard(std::string name, int size_stack, std::map<int,std::string> pins);
    bool setUp();
    float getSensorData() override;
  private:
    const int MAX_ITER = 10;
};

#endif

