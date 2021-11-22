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
    bool writeSD(String textToWrite);
    bool appendSD(String textToWrite);
  private:
    const int MAX_ITER = 10;
    const String file_name = "/logger.txt";
};

#endif

