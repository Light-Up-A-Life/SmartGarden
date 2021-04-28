#ifndef ANEMOMETER_H
#define ANEMOMETER_H

const int  PIN_ANEMO = 32;
const float VccCorrection = 5.03 / 5.05; // Measured Vcc by multimeter divided by reported Vcc
const int internalVcc = 5; // in Volts
const float windM = 1 + 0 * 0.1406;
const float windC = 0 * 11.312;

float readAnemometer();

#endif
