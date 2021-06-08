#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include <map>

using std::string;

class Sensor{
  public:
    bool bFailure;
    const string name;
    const string magnitude_type;

    Sensor(string name, string magn_type, std::map<int,string> pins, int size_stack);
    float read(int sampling);
    float virtual getSensorData() = 0;
    bool virtual setUp() = 0;

  private:
    std::map<int, string> pins_;
    std::vector<float> mesures_sec_ {};
    std::vector<float> mesures_min_ {};
    int it_mes_sec_;
    int it_mes_min_;
};

#endif

