#ifndef SDCARD_H
#define SDCARD_H

#include "FS.h"
#include "SD.h"
#include <SPI.h>

#include "Sensor.h"

class SdCard : public Sensor::Sensor{
  public:
    
  
};
File file; //Our text file
const int SDCARD_INIT_MAX_ITER = 5;

#define SDCARD_CS_PIN 5
// const int SDCARD_CS_PIN =  5;      // white
const int SDCARD_MOSI_PIN =  23;      // blue
const int SDCARD_MISO_PIN =  19;      // green
const int SDCARD_SCK_PIN =  18;       // yellow (or CLK)
bool initSD();
void writeSD(String fileToWrite, String textToWrite);
void appendSD(String fileToWrite, String textToWrite);
String readSD(String fileToRead);
void testSDcard();
#endif

