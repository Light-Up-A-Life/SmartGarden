#ifndef SDCARD_H
#define SDCARD_H

#include "SD.h"
#include <SPI.h>

#include "Sensor.h"

class SdCard : public Sensor{
  public:
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
  private:
    const int MAX_ITER = 10;
};

#endif

