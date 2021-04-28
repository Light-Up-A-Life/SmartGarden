#include "Sensor.h"

Sensor::Sensor(std::string name, std::map<int,std::string> pins,int size_stack):
  bFailure(false),
  name(name),
  pins_(pins),
  it_mes_sec_(0),
  it_mes_min_(0){ 
    mesures_sec_.reserve(size_stack);
    mesures_min_.reserve(size_stack);
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
    mesures_sec_[it_mes_min_] = value;
    it_mes_min_++;
  }
  else{
    it_mes_min_= 0;
  }
  return value; ;
}


