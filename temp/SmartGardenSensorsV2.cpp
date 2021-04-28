// -------------------------------------- //
//              Smart Garden              //
// -------------------------------------- //

// By El Jose & El Kike (JK Inc.)
// Last update: 28/06/2020

#define VERSION            "1.0.0"

#include "time.h"
// General libs
#include "Debugging.h"

// GSM module libs
#include <sstream>
#include <vector>
#include <string>

const int SAMPLING_N = 10;

bool BF_BMP_1 = false;
bool BF_SOILM_1 = false;
bool BF_SOILM_2 = false;
bool BF_ANEMO_1 = false;
bool BF_DS_EXT_TEMP_1 = false;
bool BF_SDCARD = false;
bool BF_GSM_AT = false;
bool BF_GSM_TIME = false;
bool BF_GSM_GPS = false;



// -------------------------------------- //
//               Time events              //
// -------------------------------------- //

// Duration values for the different events
const long SECOND_MS = 1000;        // Real value: 1k
const long MINUTE_MS = 10000;       // Real value: 60k
const long HOUR_MS   = 600000000;   // Real value: 3.6M

unsigned long previousMillisMinute = 0, previousMillisHour = 0, previousMillisSec = 0;
bool minutePassedEvent, hourPassedEvent, secPassedEvent;

const int SIZE_STACK_SENSORS = 60;
float minuteValuesTempInt[SIZE_STACK_SENSORS];      //Create one for every sensor that we want to store
float minuteValuesTempExt[SIZE_STACK_SENSORS];      //Create one for every sensor that we want to store
float minuteValuesAnemo[SIZE_STACK_SENSORS];        //Create one for every sensor that we want to store
float minuteValuesSoilMoist1[SIZE_STACK_SENSORS];   //Create one for every sensor that we want to store
float minuteValuesSoilMoist2[SIZE_STACK_SENSORS];   //Create one for every sensor that we want to store
float minuteValuesPressure[SIZE_STACK_SENSORS];     //Create one for every sensor that we want to store
int indexCount = 0;


// -------------------------------------- //
//              SMS logging               //
// -------------------------------------- //

// Serial Serial2(5, 6); //The sim card is connected to here
String data, timestamp, timeToWrite, stringToWriteSD, smsToWrite; //Do I really need all of them?

int hourAverageAnem, hourMaxAnem;
int hourAverageTempExt, hourMaxTempExt;
int hourAverageTempInt, hourMaxTempInt;

// Temporary solution for time acquisition via ntp server

bool B0_GNS = false;

// const String numberSMS = "+33620337258";

#define SerialAT Serial2

#define TINY_GSM_MODEM_SIM808      // Modem is SIM800
// #define TINY_GSM_RX_BUFFER   1024  // Set RX buffer to 1Kb
#define MODEM_TX             17
#define MODEM_RX             16




float getSensorData(int pin, String type) //Need to account for other sensors that may require several pins
{
  float sensorValue;

  if (type == "ANALOG")
  {
    sensorValue = analogRead(pin);
  }
  else if (type == "DIGITAL")
  {
    sensorValue = digitalRead(pin);
  }
  else if (type == "DS")
  {
    sensorDS18B20.requestTemperatures();
    sensorValue = sensorDS18B20.getTempCByIndex(0); // problem with pin variables (if we have several sensors)
  }
  else if (type == "ANEM")
  {
    sensorValue = readAnemometer(pin);
  }
  else if (type == "SOILM")
  {
    sensorValue = readSoilMoisturePercetage(pin);
  }
  else if (type == "BMP_TEMP")
  {
    sensorValue = bmp.readTemperature();
  }
  else if (type == "BMP_PRES")
  {
    sensorValue = bmp.readPressure();
  }
  else
  {
    Serial.println("Error: Type unknown");
    return -1;
  }
  /*
    Serial.println();
    Serial.print("Final sensor value in getSensorValue: ");
    Serial.println(sensorValue);
  */

  DEEPDPRINTLN("");
  DEEPDPRINT("Value read for '");
  DEEPDPRINT(type);
  DEEPDPRINT("' = ");
  DEEPDPRINTLN(sensorValue);

  return sensorValue;
}

float approximateValues(int pin, String type, int sampling, bool bFailure) //USED ONCE A SECOND into minuteValues[]
{
  if (bFailure){
    ERRORPRINTLN("");
    ERRORPRINT("Reading of type '");
    ERRORPRINT(type);
    ERRORPRINT("' in pin ");
    ERRORPRINT(pin);
    ERRORPRINTLN(" not available.");
    return 0;
  }

  float sensorValues[sampling]; // TODO: NOT NECESSARY! But it works now. For later we can rewrite
  float sum = 0;
  float rawValue;

  for (int i = 0; i < sampling; i++)
  {
    rawValue = getSensorData(pin, type);
    sum += rawValue;
  }

  DPRINTLN("");
  DPRINT("Value read for '");
  DPRINT(type);
  DPRINT("' = ");
  DPRINT(sum / sampling);
  DPRINT(" (sampling=");
  DPRINT(sampling);
  DPRINT(")");

  return sum / sampling ;
}

struct report reportFunc(float values[], int indexCount)
{
  report myReport;
  myReport.rmax = values[0];
  myReport.rmin = values[0];
  myReport.average = values[0];
  for (int i = 1 ; i < indexCount ; i++) {
    if (values[i] > myReport.rmax) {
      myReport.rmax = values[i];
    }
    if (values[i] < myReport.rmin) {
      myReport.rmin = values[i];
    }
    myReport.average += values[i];
  }
  myReport.average = round(myReport.average / indexCount);

  return myReport;
}
/************************************/
/*****   Time events functions   ****/
/************************************/

void timeCount() //Counts real time from start and triggers time based events
{
  unsigned long currentMillis = millis();
  minutePassedEvent = false;
  hourPassedEvent = false;
  secPassedEvent = false;

  if (currentMillis - previousMillisSec >= SECOND_MS)
  {

    DPRINTLN("/************************************/");
    DPRINTLN("        One second has passed         ");
    DPRINTLN("/************************************/");
    previousMillisSec = currentMillis;
    secPassedEvent = true;
  }

  if (currentMillis - previousMillisMinute >= MINUTE_MS)
  {
    DPRINTLN("/************************************/");
    DPRINTLN("        One minute has passed         ");
    DPRINTLN("/************************************/");
    previousMillisMinute = currentMillis;
    minutePassedEvent = true;
  }

  if (currentMillis - previousMillisHour >= HOUR_MS)
  {
    DPRINTLN("/************************************/");
    DPRINTLN("         One hour has passed          ");
    DPRINTLN("/************************************/");
    previousMillisHour = currentMillis;
    hourPassedEvent = true;
  }
}

void handleEvents() //Checks the time-based events and acts consequently (can add others)
{

  if (secPassedEvent == true) //Get the values from ALL the sensors
  {
    DPRINTLN("Reacting to second passed");


    minuteValuesTempExt[indexCount]   =   approximateValues(PIN_DS18B20_ONEWIRE,  "DS",         SAMPLING_N, BF_DS_EXT_TEMP_1); //For every sensor
    minuteValuesAnemo[indexCount]     =   approximateValues(PIN_ANEMO,            "ANEM",       SAMPLING_N, BF_ANEMO_1); //For every sensor
    minuteValuesSoilMoist1[indexCount] =  approximateValues(PIN_SOIL_MOIST1,      "SOILM",      SAMPLING_N, BF_SOILM_1); //For every sensor
    minuteValuesSoilMoist2[indexCount] =  approximateValues(PIN_SOIL_MOIST2,      "SOILM",      SAMPLING_N, BF_SOILM_2); //For every sensor
    minuteValuesTempInt[indexCount]   =   approximateValues(0,                    "BMP_TEMP",   SAMPLING_N, BF_BMP_1); //For every sensor
    minuteValuesPressure[indexCount]  =   approximateValues(0,                    "BMP_PRES",   SAMPLING_N, BF_BMP_1); //For every sensor

    /*
      DPRINTLN();
      DPRINT("Averaged value of Temp : ");
      DPRINTLN(minuteValuesTempInt[indexCount]);
      DPRINT("Averaged value of Anemo : ");
      DPRINTLN(minuteValuesAnemo[indexCount]);
    */

    // Publishing to Google
    String params = "SoilMois1=" + String(minuteValuesSoilMoist1[indexCount]) + "&"
                    "SoilMois2=" + String(minuteValuesSoilMoist2[indexCount]) + "&"
                    "TempInt=" + String(minuteValuesTempInt[indexCount])   + "&"
                    "Pressure=" + String(minuteValuesPressure[indexCount]) ;

    sendDataToGoogle(params);

    // Value for HTTP Server
   // handle_OnConnect(minuteValuesSoilMoist1[indexCount], minuteValuesTempInt[indexCount], minuteValuesPressure[indexCount])
    server.handleClient();
    //

    indexCount++;
  }

  if (minutePassedEvent == true) //Store the average + timestamp in SD card
  {
    //DPRINTLN("Test for ONLY getClock()");
    //DPRINTLN(getClock());

    timeToWrite = extractTimestamp();
    int maximum = 0, minimum = 1024, average = 0, sum = 0;
    stringToWriteSD = "";

    DPRINTLN("Reacting to minute passed");
    DPRINT("indexCount = ");
    DPRINTLN(indexCount);

    // Creation of reports (avg, max, min)
    report reportTempExt =    reportFunc(minuteValuesTempExt , indexCount);
    report reportAnemo =      reportFunc(minuteValuesAnemo, indexCount);


    // Updating info for HOURS report
    hourAverageTempExt += reportTempExt.average; //Increments 2 values for the hour recap'
    if (reportTempExt.rmax >= hourMaxTempExt)
    {
      hourMaxTempExt = reportTempExt.rmax;
    }

    hourAverageAnem += reportAnemo.average; //Increments 2 values for the hour recap'
    if (reportAnemo.rmax >= hourMaxAnem)
    {
      hourMaxAnem = reportAnemo.rmax;
    }

    // Creation of the string for SD card
    DPRINT("Timestamp for SD: ");
    DPRINTLN(timeToWrite);

    //stringToWrite = (String)timeToWrite + " : Last minute, " + (String)indexCount + " values recorded with an average of : " + (String)average + " (max = " + (String)maximum + " and min = " + (String)minimum + ")";
    stringToWriteSD = timeToWrite; //Have to do it this way, dunno why
    stringToWriteSD += '/';
    stringToWriteSD += reportTempExt.average;
    stringToWriteSD += '/';
    stringToWriteSD += reportTempExt.rmax;
    stringToWriteSD += '/';
    stringToWriteSD += reportTempExt.rmin;
    stringToWriteSD += '/';
    stringToWriteSD += reportAnemo.average;
    stringToWriteSD += '/';
    stringToWriteSD += reportAnemo.rmax;
    stringToWriteSD += '/';
    stringToWriteSD += reportAnemo.rmin;

    DPRINT("String to write on SD: ");
    DPRINTLN(stringToWriteSD);
    writeSD("RMS_Test.txt", stringToWriteSD);

    // Reinitialization of MINUTES arrays and variables
    indexCount = 0;
    memset(minuteValuesTempExt,  0, indexCount); //Important : free memory for local variables
    memset(minuteValuesAnemo, 0, indexCount); //Important : free memory for local variables

  }

  if (hourPassedEvent == true) //Sends an SMS to a phone number with a recap' over the last hour
  {
    timeToWrite = extractTimestamp();
    Serial.println(F("Reacting to hour passed")); //Need to incorporate other sensors as well
    hourAverageAnem = round(hourAverageAnem / 60);
    hourAverageTempExt = round(hourAverageTempExt / 60);
    smsToWrite = "";
    smsToWrite += timeToWrite;
    smsToWrite += ", last hour : ";
    smsToWrite += hourAverageAnem;
    smsToWrite += '/';
    smsToWrite += hourMaxAnem;
    smsToWrite += '/';
    smsToWrite += hourAverageTempExt;
    smsToWrite += '/';
    smsToWrite += hourMaxTempExt;

    DPRINTLN("SMS to be sent: ");
    DPRINTLN(smsToWrite);
    sendMessage(smsToWrite);

    hourAverageAnem = 0;
    hourMaxAnem = 0;
    hourAverageTempExt = 0;
    hourMaxTempExt = 0;
  }
}


bool computeValues(int threshold, int value, int pinSensor)
{
  if (value >= threshold)
  {
    Serial.println(F("The value is too high"));
    sendAlert(pinSensor, "MEDIUM");
  }
}


/************************************/
/*****          setup()          ****/
/************************************/

void setup()
{
  // Common setup
  Serial.begin(115200);

  Serial.println("Welcome to Smart Garden! ");

  // DS18B20 sensor
  Serial.printf("Setting up external temp sensor (DS18B20)... \n");
  sensorDS18B20.begin();


  // BMP085 sensor
  Serial.printf("Setting up preasure sensor (BMP180)... ");
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    BF_BMP_1 = true;
  }

  // SD setup
  Serial.printf("Setting up SD card ... ");
  BF_SDCARD = initSD();

  // WiFi connection
  Serial.printf("Setting up WiFi connection ... ");
  if (SmartConfigOn){
   WiFiConnectSmartConfig();
  }
  else{
    WiFiConnectFromLib();
  }

  // Server initialization for local Web page and OTA
  Serial.printf("Setting up OTA and Web server ... ");
  serverInit();

  // Initialization GSM module
  Serial.println("Initializing GSM module ...");
  Serial2.begin(115200);
  B0_GNS = initGNSModule();


  // Init and get the time .. machete!
  // configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // printLocalTime();
  

  Serial.println("Ready to garden! ");


  // Tests  - 
  testSDcard();

}


void loop()
{
  timeCount();
  handleEvents();
}


