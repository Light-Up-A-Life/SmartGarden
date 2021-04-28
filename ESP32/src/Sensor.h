#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include <map>

class Sensor{
  public:
    Sensor(std::string name, std::map<int,std::string> pins, int size_stack);
    float read(int sampling);
    float virtual getSensorData() = 0;
    bool bFailure;
    const std::string name;
  private:
    std::map<int, std::string> pins_;
    std::vector<float> mesures_sec_ {};
    std::vector<float> mesures_min_ {};
    int it_mes_sec_;
    int it_mes_min_;
};

#endif

