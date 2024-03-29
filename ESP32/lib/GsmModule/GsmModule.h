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
    using Sensor::Sensor;
    bool setUp() override;
    float getSensorData() override;
    bool sendSMS(String msg);
    bool sendToServer(String msg);
    String getClock();
    String getPosition();

    /*void printLocalTime();
    void sendMessage(String);
    void receiveMessage();
    bool gsmModuleStatus();
    std::string extractTimestamp();
    std::string extractTimestamp2(String);*/
  private:
    String sendATCmd(String msg);
    std::string data_;
    GSM gsmModule;
    const std::string numberSMS_ = "+33770451126";
    const int MAX_ITER = 25;
};
#endif
