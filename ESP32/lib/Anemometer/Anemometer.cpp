#include "Anemometer.h"

bool Anemometer::setUp() {
  int WindSpeedPin = Sensor::getPins().begin()->first;
  pinMode(WindSpeedPin, INPUT);
  // attachInterrupt(digitalPinToInterrupt(WindSpeedPin), isr_rotation,
  // FALLING);
  return true;
}

float Anemometer::mapFloat(float x, float in_min, float in_max, float out_min,
                           float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
/* OLD
float Anemometer::getSensorData() {
  float digital_value = analogRead(Sensor::getPins().begin()->first);
  float analog_value_output = mapFloat(digital_value, 0, 4095, 0, 3.3);
  float analog_value_input = analog_value_output /  gain_wind_direction;
  float cal_direction = mapFloat(analog_value_input, 0, vol_max_input, 0, 360) +
offset;

  if (cal_direction > 360)
    cal_direction = cal_direction - 360;

  if (cal_direction < 0)
    cal_direction = cal_direction + 360;

    return cal_direction;
}
*/

float Anemometer::getWindSpeedMph() {
  // Reading of the wind speed
  // Serial.println("Reading wind speed");
  // isr_rotation();
  Rotations = 0; // Set Rotations count to 0 ready for calculations

  sei();                               // Enables interrupts
  delay(int(TperiodWindSpeed * 1000)); // Wait 3 seconds to average
  cli();                               // Disable interrupts

  // convert to mp/h using the formula V=P(2.25/T)
  // V = P(2.25/3) = P * 0.75

  float WindSpeed = Rotations * 2.25 / TperiodWindSpeed; // in mph
  return WindSpeed;
}

float Anemometer::getWindSpeedMpers() {
  return 0.447*getWindSpeedMph();
}

float Anemometer::getWindDirection() {
  float VaneValue = analogRead(Sensor::getPins().begin()->first);
  

  int Direction = map(VaneValue, 0, 4095, 0, 360);
  // Direction = VaneValue;
  int CalDirection = Direction + Offset;

  if (CalDirection > 360)
    CalDirection = CalDirection - 360;

  if (CalDirection < 0)
    CalDirection = CalDirection + 360;

  return CalDirection;
}

float Anemometer::getSensorData() {
  if (magnitude_type == "Wind_speed")
    return getWindSpeedMpers();
  else 
    return getWindDirection();
}
