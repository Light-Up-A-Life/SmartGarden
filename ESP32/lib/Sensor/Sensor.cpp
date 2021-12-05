#include "Sensor.h"

using std::string;

Sensor::Sensor(string name, string nameDisplay, string magn_type, std::map<int,string> pins,int size_stack):
  bFailure(false),
  name(name),
  nameDisplay(nameDisplay),
  magnitude_type(magn_type),
  pins_(pins),
  it_mes_sec_(0),
  it_mes_min_(0)
  { 
    mesures_sec_.reserve(size_stack);
    mesures_min_.reserve(size_stack);
    mesures_sec_[size_stack] = {0};
  }

float Sensor::read(int sampling)
{
  float sum = 0;
  float rawValue;
  for (int i = 0; i < sampling; i++)
  {
    rawValue = getSensorData();
    sum += rawValue;
  }
  float value = sum / sampling;
  //store the value into the vector
  if(it_mes_sec_ < mesures_sec_.capacity()){
    mesures_sec_[it_mes_sec_] = value;  
    it_mes_sec_++;
  }
  else{
    it_mes_sec_= 0;
    mesures_sec_[it_mes_sec_] = value;
  }
   
  return value;
}

float Sensor::getValue(){
  return mesures_sec_[it_mes_sec_-1];
}

float Sensor::callbackMinute(){
  float sum = 0;
  for(int i = 0; i < mesures_sec_.capacity()-1; i++){
    sum += mesures_sec_[i];
  }
  float avg = sum/float(mesures_sec_.capacity());
  if(it_mes_min_ < mesures_min_.capacity()){
    mesures_min_[it_mes_min_] = avg;
    it_mes_min_++;
  }
  else{
    it_mes_min_= 0;
  }
  return avg;
}

const std::map<int, string> Sensor::getPins(){
  return pins_;
}


