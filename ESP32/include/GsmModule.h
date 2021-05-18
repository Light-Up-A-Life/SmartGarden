#ifndef GSMMODULE_H
#define GSMMODULE_H
#define TINY_GSM_MODEM_SIM808
#include "TinyGsmClient.h"
#include "Sensor.h"
#include <string>
#include <sstream>
#include <vector>
struct GSM {
   int sec;   
   int min;   
   int hour;  
   int day;  
   int mon;   
   int year;
   float longitude;
   float latitude;  
};

class GsmModule : public Sensor{
  public:
    GsmModule(std::string name, int size_stack, std::map<int,std::string> pins, std::string data);
    bool setUp();
    float getSensorData() override;
    /*void printLocalTime();
    void sendMessage(String);
    void receiveMessage();
    bool gsmModuleStatus();
    std::string extractTimestamp();
    std::string extractTimestamp2(String);*/
  private:
    std::string data_;
    GSM gsmModule;
    const std::string numberSMS_ = "+33770451126";
    const int MAX_ITER = 25;
};
#endif
