#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>
#include <map>
#include <Arduino.h>
#include <U8g2lib.h>    // By Olivier   

#include "Sensor.h"

using std::string;



class Display{
  private:
    U8G2_SH1106_128X64_NONAME_F_HW_I2C myDisplay = U8G2_SH1106_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
    
    // For ESP32:
    // U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
  public:
    
    bool bFailure;
    const int DISPLAY_WIDTH = 128;
    const int DISPLAY_HEIGHT = 64;
    const int FLIP_MODE = false;
    int status=0;
    //Display();

   
    // Display() : myDisplay(U8X8_PIN_NONE) {     }
    Display();
    // Display();
    // Display() : myDisplay(U8X8_PIN_NONE) {} 
    // Display() { myDisplay.begin(); }

    bool setup();
    void displayImage(const unsigned char * u8g_image_bits);
    void showInitialDisplay();
    void showMainDisplay(std::vector<Sensor *> listSensor);
    void displayLoop(std::vector<Sensor *> listSensor);

};

#endif

