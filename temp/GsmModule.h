#ifndef GSMMODULE_H
#define GSMMODULE_H

#include <TinyGsmClient.h>
TinyGsm modem(SerialAT);
const String numberSMS = "+33770451126";
#include <string>
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

const int MAX_ITER_GSM = 5; //60

bool initGNSModule();
void printLocalTime();
void sendMessage(String);
void receiveMessage();
bool gsmModuleStatus();
std::string extractTimestamp();
std::string extractTimestamp2(String);
#endif
