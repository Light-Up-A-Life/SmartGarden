// Variadic macros used to print information in de-bugging mode
// from LarryD, Arduino forum

#pragma once
// un-comment this line to print the debugging statements
#define DEBUG

#ifdef DEBUG
  #define DPRINT(...)    Serial.print(__VA_ARGS__)
  #define DPRINTLN(...)  Serial.println(__VA_ARGS__)
  #define DPRINTF(...)   Serial.printf(__VA_ARGS__)
#else
  // define blank line
  #define DPRINT(...)
  #define DPRINTLN(...)
#endif


// un-comment this line to print the debugging statements
// #define DEEPDEBUG

#ifdef DEEPDEBUG
  #define DEEPDPRINT(...)    Serial.print(__VA_ARGS__)
  #define DEEPDPRINTLN(...)  Serial.println(__VA_ARGS__)
#else
  // define blank line
  #define DEEPDPRINT(...)
  #define DEEPDPRINTLN(...)
#endif

#define ERRORPRINT

#ifdef ERRORPRINT
  #define ERRORPRINTLN(...)  Serial.printf("\x1b[31m %s \x1b[0m \n", __VA_ARGS__)
  #define ALERTPRINTLN(...)  Serial.printf("\x1b[32m %s \x1b[0m \n", __VA_ARGS__)
#else
  // define blank line
  #define ERRORPRINT(...)
  #define ERRORPRINTLN(...)
#endif



#define SerialGSM Serial2
