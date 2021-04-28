#ifndef TEMPERATUREEXTERNAL_H
#define TEMPERATUREEXTERNAL_H
#include <OneWire.h> 
#include <DallasTemperature.h>
const int PIN_DS18B20_ONEWIRE = 4;
OneWire oneWire(PIN_DS18B20_ONEWIRE);
DallasTemperature sensorDS18B20(&oneWire);
void testDSSensor(){

  float testTempDS = approximateValues(PIN_DS18B20_ONEWIRE,  "DS",         SAMPLING_N, BF_DS_EXT_TEMP_1); //For every sensor
  Serial.printf("Temp (DS): %.2f", testTempDS);
  delay(2000);

}
#endif
