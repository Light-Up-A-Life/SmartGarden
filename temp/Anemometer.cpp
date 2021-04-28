// -------------------------------------- //
//              Anemometer                //
// -------------------------------------- //
#include "Anemometer.h"

float readAnemometer() {
  float anemometerVoltage = analogRead(PIN_ANEMO);//*internalVcc/1024;
  float windSpeed = windSpeed = (windM * anemometerVoltage) - windC;
  return windSpeed;
}
