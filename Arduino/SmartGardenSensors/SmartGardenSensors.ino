

// -------------------------------------- //
//              Smart Garden              //
// -------------------------------------- //

// By El Jose & El Kike
// Last update: 28/06/2020

#define VERSION            "1.0.0"

// -------------------------------------- //
//                Libraries               //
// -------------------------------------- //
#include "FS.h"
#include "SD.h"
#include "SPI.h"

// #include <Vcc.h> 

#include <OneWire.h>            // For the DS18B20 (External temp sensor)
#include <DallasTemperature.h>  // For the DS18B20 (External temp sensor)


#include <Wire.h>               // For the BMP180 (Internal temp sensor & pressure)
#include <Adafruit_BMP085.h>    // For the BMP180 (Internal temp sensor & pressure)

#include <WiFi.h>               // For WiFi connection
#include <HTTPClient.h>         // For WiFi connection

#include "Debugging.h"

// -------------------------------------- //
//              Anemometer                //
// -------------------------------------- //
  const int  PIN_ANEMO = 0; // TO BE CHANGED!

  // Anemometer data
  const float VccCorrection = 5.03/5.05;  // Measured Vcc by multimeter divided by reported Vcc
  // Vcc vcc(VccCorrection);
  int internalVcc = 5; // in Volts
  float windSpeedCalib=1.0;
  float windM = 1+0*0.1406;
  float windC = 0*11.312;
  float anemometerVoltageMin = 0.42;

  
// -------------------------------------- //
// External temperature sensor (DS18B20)  //
// -------------------------------------- //

  // Pin selection
  const int PIN_DS18B20_ONEWIRE = 9;

  // Setup a oneWire instance to communicate with any OneWire devices
  OneWire oneWire(PIN_DS18B20_ONEWIRE);

  // Pass our oneWire reference to Dallas Temperature sensor 
  DallasTemperature sensorDS18B20(&oneWire);

// ------------------------------------------------- //
// Internal temperature & preasure sensor (BMP180)   //
// ------------------------------------------------- //

  const int PIN_BMP180_SDA =  21;
  const int PIN_BMP180_SCL =  22;

  Adafruit_BMP085 bmp;

// ------------------------------------------------- //
//              Soil Moisture sensor                 //
// ------------------------------------------------- //

  // Pin selection
  const int   PIN_SOIL_MOIST  = 34;
  const float MOIST_RAW_MIN   = 2080;
  const float MOIST_RAW_MAX   = 1040;
  
  
// -------------------------------------- //
//        Current & Voltage sensor        //
// -------------------------------------- //

  // NOT DEVELOPED YET
  const int PIN_CURRENT_SENSOR    = 0;
  const int PIN_VOLTAGE_SENSOR    = 0;
  const int PIN_VIBRATION_SENSOR  = 0;


// -------------------------------------- //
//               Time events              //
// -------------------------------------- //

  // Duration values for the different events 
  const long SECOND_MS = 1000; 
  const long MINUTE_MS = 600000;
  const long HOUR_MS   = 120000; 
  
  unsigned long previousMillisMinute = 0, previousMillisHour = 0, previousMillisSec = 0;
  bool minutePassedEvent, hourPassedEvent, secPassedEvent;

  const int SIZE_STACK_SENSORS = 31;
  float minuteValuesTempInt[SIZE_STACK_SENSORS];    //Create one for every sensor that we want to store
  float minuteValuesTempExt[SIZE_STACK_SENSORS];    //Create one for every sensor that we want to store
  float minuteValuesAnemo[SIZE_STACK_SENSORS];      //Create one for every sensor that we want to store
  float minuteValuesSoilMoist[SIZE_STACK_SENSORS];  //Create one for every sensor that we want to store
  float minuteValuesPressure[SIZE_STACK_SENSORS];   //Create one for every sensor that we want to store
  int indexCount = 0;

// -------------------------------------- //
//                SD card                 //
// -------------------------------------- //

  File file; //Our text file
  const int PIN_SD_CARD = 4;
  const int SDCARD_INIT_MAX_ITER = 5;
  
// -------------------------------------- //
//              SMS logging               //
// -------------------------------------- //

  // Serial Serial2(5, 6); //The sim card is connected to here
  String data, timestamp, timeToWrite, stringToWriteSD, smsToWrite; //Do I really need all of them?


int hourAverageAnem, hourMaxAnem,hourAverageTemp, hourMaxTemp;;


// Pins: TO BE REDEFINED
//SD card : blue 11, green 12, yellow 13, white 10
//GSM : Purple 5: RX Aruino-TX GSM Modue, green 6: TX Arduino - RX GSM Module 
// Anemometer: Blue = Analog signal(ex: A0), Brown = Voltage(7-12V) -> Red cable for arduino, Black = Ground
//5V and GND top both


/************************************/
/*****      WiFi connection      ****/
/************************************/

#define WLAN_HOSTNAME   "SmartGarden-MainController"

// TODO !! 
#define SmartConfigOn   false

#define WLAN_MAX_COUNT  10
#define WLAN_LIB_N      3
String WLAN_NAME_LIB[]  = {"Jose's House" , "Kike's House"        , "Jose's House"};
String WLAN_SSID_LIB[]  = {"SFR-5538"     , "SFR_6608"            , "SFR-5538"};
String WLAN_PASS_LIB[]  = {"VHYWP9A2PVDU" , "2cwt45yriv2urm57trbx", "VHYWP9A2PVDU"};


WiFiClientSecure client;

void connectToWiFi() {
  

  WiFi.mode(WIFI_STA);
  WiFi.begin(WLAN_SSID, WLAN_PASS);

  WiFi.setHostname(WLAN_HOSTNAME);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("GatewayIP address: ");
  Serial.println(WiFi.gatewayIP());
  Serial.println("");

}


/************************************/
/*****   Google API connection   ****/
/************************************/

String GOOGLE_SCRIPT_ID = "AKfycby6m-J7Nof2ULsI72HIgboaE3o9nXXvW46crG2_IOePWZplCblh"; // Replace by your GAS service id

// Updated 04.12.2019
const char * root_ca = \
                       "-----BEGIN CERTIFICATE-----\n" \
                       "MIIDujCCAqKgAwIBAgILBAAAAAABD4Ym5g0wDQYJKoZIhvcNAQEFBQAwTDEgMB4G\n" \
                       "A1UECxMXR2xvYmFsU2lnbiBSb290IENBIC0gUjIxEzARBgNVBAoTCkdsb2JhbFNp\n" \
                       "Z24xEzARBgNVBAMTCkdsb2JhbFNpZ24wHhcNMDYxMjE1MDgwMDAwWhcNMjExMjE1\n" \
                       "MDgwMDAwWjBMMSAwHgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMjETMBEG\n" \
                       "A1UEChMKR2xvYmFsU2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjCCASIwDQYJKoZI\n" \
                       "hvcNAQEBBQADggEPADCCAQoCggEBAKbPJA6+Lm8omUVCxKs+IVSbC9N/hHD6ErPL\n" \
                       "v4dfxn+G07IwXNb9rfF73OX4YJYJkhD10FPe+3t+c4isUoh7SqbKSaZeqKeMWhG8\n" \
                       "eoLrvozps6yWJQeXSpkqBy+0Hne/ig+1AnwblrjFuTosvNYSuetZfeLQBoZfXklq\n" \
                       "tTleiDTsvHgMCJiEbKjNS7SgfQx5TfC4LcshytVsW33hoCmEofnTlEnLJGKRILzd\n" \
                       "C9XZzPnqJworc5HGnRusyMvo4KD0L5CLTfuwNhv2GXqF4G3yYROIXJ/gkwpRl4pa\n" \
                       "zq+r1feqCapgvdzZX99yqWATXgAByUr6P6TqBwMhAo6CygPCm48CAwEAAaOBnDCB\n" \
                       "mTAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUm+IH\n" \
                       "V2ccHsBqBt5ZtJot39wZhi4wNgYDVR0fBC8wLTAroCmgJ4YlaHR0cDovL2NybC5n\n" \
                       "bG9iYWxzaWduLm5ldC9yb290LXIyLmNybDAfBgNVHSMEGDAWgBSb4gdXZxwewGoG\n" \
                       "3lm0mi3f3BmGLjANBgkqhkiG9w0BAQUFAAOCAQEAmYFThxxol4aR7OBKuEQLq4Gs\n" \
                       "J0/WwbgcQ3izDJr86iw8bmEbTUsp9Z8FHSbBuOmDAGJFtqkIk7mpM0sYmsL4h4hO\n" \
                       "291xNBrBVNpGP+DTKqttVCL1OmLNIG+6KYnX3ZHu01yiPqFbQfXf5WRDLenVOavS\n" \
                       "ot+3i9DAgBkcRcAtjOj4LaR0VknFBbVPFd5uRHg5h6h+u/N5GJG79G+dwfCMNYxd\n" \
                       "AfvDbbnvRG15RjF+Cv6pgsH/76tuIMRQyV+dTZsXjAzlAcmgQWpzU/qlULRuJQ/7\n" \
                       "TBj0/VLZjmmx6BEP3ojY+x1J96relc8geMJgEtslQIxq/H5COEBkEveegeGTLg==\n" \
                       "-----END CERTIFICATE-----\n";


void sendDataToGoogle(String params) {

  HTTPClient http;
  
  DPRINT("Making a request to Google");
  String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + params;
  DPRINT(url);

  http.begin(url, root_ca); //Specify the URL and certificate
  int httpCode = http.GET();
  String httpJSONobjString = http.getString();
  http.end();
}


/************************************/
/***** Sensors: generic functions ***/
/************************************/

struct report{
  int rmax;
  int rmin;
  int average;
};

float getSensorData(int pin, String type) //Need to account for other sensors that may require several pins
{
  float sensorValue;
  
  if(type == "ANALOG")
  {
    sensorValue = analogRead(pin);
  }
  else if(type == "DIGITAL")
  { 
    sensorValue = digitalRead(pin);
  }
  else if(type == "DS")
  {
    sensorValue = sensorDS18B20.getTempCByIndex(0); // problem with pin variables (if we have several sensors)
  }
  else if(type == "ANEM")
  {
    sensorValue = readAnemometer(pin);
  }
  else if(type == "SOILM")
  {
    sensorValue = readSoilMoistureRaw(pin);
  }
  else if(type == "BMP_TEMP")
  {
    sensorValue = bmp.readTemperature();
  }
  else if(type == "BMP_PRES")
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


float approximateValues(int pin, String type, int sampling) //USED ONCE A SECOND into minuteValues[]
{
  float sensorValues[sampling]; // NOT NECESSARY! 
  float sum = 0;
  float rawValue;
 
  for(int i = 0; i < sampling; i++)
  {
    rawValue = getSensorData(pin, type);
    sum += rawValue;
  }
  
  DPRINTLN("");
  DPRINT("Value read for '");
  DPRINT(type);
  DPRINT("' = ");
  DPRINT(sum/sampling);
  DPRINT(" (sampling=");  
  DPRINT(sampling);  
  DPRINT(")");  
  
  return sum/sampling ;
}


struct report reportFunc(float values[], int indexCount)
{
  report myReport;
  myReport.rmax = values[0];
  myReport.rmin = values[0];
  myReport.average = values[0];
  for(int i = 1 ; i < indexCount ; i++){
         if(values[i] > myReport.rmax){
            myReport.rmax = values[i];
         }
         if(values[i] < myReport.rmin) {
            myReport.rmin = values[i];
         }
         myReport.average += values[i];
  }
  myReport.average = round(myReport.average/indexCount);
  
  return myReport;
}


/*************************************/
/*****     Anemometer functions    ***/
/*************************************/

float readAnemometer(int pin){
    
    float anemometerVoltage = analogRead(pin);//*internalVcc/1024;
    
    float windSpeed;
    /*if( anemometerVoltage <= 0.42 ){  //0.4 is the minimum voltage for Anemometer
      windSpeed = -500; // Check if voltage is below minimum, if so, set wind speed to zero
    }
    else{*/
      windSpeed = (windM*anemometerVoltage) - windC;
    //}
    
    DEEPDPRINT("Voltage: ");
    DEEPDPRINT(anemometerVoltage);
    DEEPDPRINT(" V  -  Wind speed: ");
    DEEPDPRINT(windSpeed);
    DEEPDPRINTLN(" ??");
    
    return windSpeed;
}


/*************************************/
/*****   Soil moisture functions   ***/
/*************************************/


int readSoilMoistureRaw(int pin){
  return analogRead(pin);
}

float readSoilMoistureVolts(int pin){
  return readSoilMoistureRaw(pin)*3.3/4095;
}

float readSoilMoisturePercetage(int pin) {
  return constrain((readSoilMoistureRaw(pin) - MOIST_RAW_MIN) * (100) / (MOIST_RAW_MAX - MOIST_RAW_MIN), -100, 200);
}

/************************************/
/***** . Time events functions . ****/
/************************************/

void timeCount() //Counts real time from start and triggers time based events
{
  unsigned long currentMillis = millis();
  minutePassedEvent = false;
  hourPassedEvent = false;
  secPassedEvent = false;

  if(currentMillis - previousMillisSec >= SECOND_MS)
  {
    Serial.println(F("\nOne second has passed"));
    previousMillisSec = currentMillis;
    secPassedEvent = true;
  }
  
  if(currentMillis - previousMillisMinute >= MINUTE_MS)
  {
    Serial.println(F("\nA minute has passed"));
    previousMillisMinute = currentMillis;
    minutePassedEvent = true;
  }
  
  if(currentMillis - previousMillisHour >= HOUR_MS)
  {
    Serial.println(F("\nAn hour has passed"));
    previousMillisHour = currentMillis;
    hourPassedEvent = true;
  }
}


void handleEvents() //Checks the time-based events and acts consequently (can add others)
{
  if(secPassedEvent == true) //Get the values from ALL the sensors
  {
    DPRINTLN("Reacting to second passed");
    
    
    minuteValuesTempExt[indexCount]   = approximateValues(PIN_DS18B20_ONEWIRE,"DS",         1); //For every sensor
    minuteValuesAnemo[indexCount]     = approximateValues(PIN_ANEMO,          "ANEM",       1); //For every sensor
    minuteValuesSoilMoist[indexCount] = approximateValues(PIN_SOIL_MOIST,     "SOILM",      1); //For every sensor
    minuteValuesTempInt[indexCount]   = approximateValues(0,                  "BMP_TEMP",   1); //For every sensor
    minuteValuesPressure[indexCount]  = approximateValues(0,                  "BMP_PRES",   10); //For every sensor

    /*
    DPRINTLN();
    DPRINT("Averaged value of Temp : ");
    DPRINTLN(minuteValuesTempInt[indexCount]);
    DPRINT("Averaged value of Anemo : ");
    DPRINTLN(minuteValuesAnemo[indexCount]);
    */

    // Publishing to Google
    String params = "SoilMois=" + String(minuteValuesSoilMoist[indexCount]) + "&" 
             "TempInt=" + String(minuteValuesTempInt[indexCount])   + "&" 
             "Pressure=" + String(minuteValuesPressure[indexCount]) ;
             
    sendDataToGoogle(params);
    
    indexCount++;
  }
  
  if(minutePassedEvent == true) //Store the average + timestamp in SD card
  {
    timeToWrite = extractTimestamp(getClock());
    int maximum = 0, minimum = 1024, average = 0, sum = 0;
    stringToWriteSD = "";
    
    DPRINTLN("Reacting to minute passed");
    DPRINT("indexCount = ");
    DPRINTLN(indexCount);

    report reportTemp;
    //= reportFunc(minuteValuesTempInt , indexCount);
    report reportAnemo = reportFunc(minuteValuesAnemo, indexCount);
        
   /*hourAverage += average; //Increments 2 values for the hour recap'
    if(maximum >= hourMax)
    {
      hourMax = maximum;
    }
*/
        
    hourAverageTemp += reportTemp.average; //Increments 2 values for the hour recap'
    if(reportTemp.rmax >= hourMaxTemp)
    {
      hourMaxTemp = reportTemp.rmax;
    }

    hourAverageAnem += reportAnemo.average; //Increments 2 values for the hour recap'
    if(reportAnemo.rmax >= hourMaxAnem)
    {
      hourMaxAnem = reportAnemo.rmax;
    }
    Serial.println(F("It is : "));
    Serial.print(timeToWrite);
    //stringToWrite = (String)timeToWrite + " : Last minute, " + (String)indexCount + " values recorded with an average of : " + (String)average + " (max = " + (String)maximum + " and min = " + (String)minimum + ")";
    stringToWriteSD = timeToWrite; //Have to do it this way, dunno why
    stringToWriteSD += '/';
    stringToWriteSD += reportTemp.average;
    stringToWriteSD += '/';
    stringToWriteSD += reportTemp.rmax;
    stringToWriteSD += '/';
    stringToWriteSD += reportTemp.rmin;
    stringToWriteSD += '/';
    stringToWriteSD += reportAnemo.average;
    stringToWriteSD += '/';
    stringToWriteSD += reportAnemo.rmax;
    stringToWriteSD += '/';
    stringToWriteSD += reportAnemo.rmin;
    
    Serial.println(stringToWriteSD);
    indexCount = 0;
    memset(minuteValuesTempInt,  0, indexCount); //Important : free memory for local variables
    memset(minuteValuesAnemo, 0, indexCount); //Important : free memory for local variables
    
    writeSD("RMS_Test.txt", stringToWriteSD);
  }
  
  if(hourPassedEvent == true) //Sends an SMS to a phone number with a recap' over the last hour
  {
    Serial.println(F("Reacting to hour passed")); //Need to incorporate other sensors as well
    hourAverageAnem = round(hourAverageAnem / 60);
    hourAverageTemp = round(hourAverageTemp / 60);
    smsToWrite = "";
    smsToWrite += timeToWrite;
    smsToWrite += ", last hour : ";
    smsToWrite += hourAverageAnem;
    smsToWrite += '/';
    smsToWrite += hourMaxAnem;
    smsToWrite += '/';
    smsToWrite += hourAverageTemp;
    smsToWrite += '/';
    smsToWrite += hourMaxTemp;
    Serial.println(smsToWrite);
    sendMessage(smsToWrite);
    hourAverageAnem = 0;
    hourMaxAnem = 0;
    hourAverageTemp = 0;
    hourMaxTemp = 0;
  }
}


/************************************/
/***** .        Alerts         . ****/
/************************************/

void sendAlert(int pinSensor, String priority) //LOW, MEDIUM, HIGH
{
//  if(priority == "LOW")
//  {
//    If alert LED is connected
//    digitalWrite(alertLedPin, HIGH);
//  }
//  if(priority == "MEDIUM")
//  {
//    
//  }
//  if(priority == "HIGH")
//  {
//    if(pinSensor == vibrationSensor) //Add more cases if there are more alert to be adressed
//    {
//      sendMessage("Too much vibration on the tower recorded !");
//    }  
//  }
}

bool computeValues(int threshold, int value, int pinSensor)
{
  if(value >= threshold)
  {
    Serial.println(F("The value is too high"));
    sendAlert(pinSensor, "MEDIUM");
  }
}


/************************************/
/*****        SMS logging        ****/
/************************************/


String getClock()
{
  //Serial2.println("AT+CLTS=1;&W"); //Sets the mode on a new module (UNCOMMENT IF YOU'RE USING IT ON A NEW MODULE)
  //delay(100);
  //Serial2.println("AT+CLTS?");
  //delay(100);
  //Serial2.println("AT+CLTS=?");
  //delay(100);
  Serial2.println("AT+CCLK?");
  delay(100);
  return Serial2.readStringUntil('\r'); //After the OK that finishes the command
}

String extractTimestamp(String clockData)
{
  Serial.println(F("Raw data : "));
  Serial.print(clockData);
  timestamp = clockData.substring(19, 36); //Indexes of starting and finishing point in the raw String
  Serial.println(F("Timestamp data : "));
  Serial.print(timestamp);
  return timestamp;
}

void sendMessage(String message) //Check if there is an error (or timeout) and store the values to send it next hour (care about memory)
{
  Serial.println(F("I will send the SMS"));
  Serial2.println("AT+CMGF=1");  //Sets the GSM Module in Text Mode
  delay(1000);
  Serial2.println("AT+CMGS=\"+33620337258\"\r"); // Replace x with mobile number
  delay(1000);
  Serial2.println(message);// The SMS text you want to send 
  delay(100);
  Serial2.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void receiveMessage()
{
  Serial2.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}



/************************************/
/*****          SD card          ****/
/************************************/

/*
uint16_t freeMem()
{
  char top;
  extern char *__brkval;
  extern char __bss_end;
  Serial.println(__brkval ? &top - __brkval : &top - &__bss_end);
}
*/

void initSD()
{
 
  Serial.println(F("Initializing SD card ..."));
  
  Serial2.begin(9600);
  Serial2.setTimeout(1000);


  if(!SD.begin(PIN_SD_CARD))
  {
    Serial.println(F("Initialization failed !"));
    int counter=0;
    while (!SD.begin(PIN_SD_CARD) & (counter < SDCARD_INIT_MAX_ITER)){
      Serial.println(F("Trying again..."));
      Serial2.begin(9600);
      Serial2.setTimeout(1000);
      delay(1000);
      counter++;
    }
    Serial.println(F("Initialization finally done !"));
  }

}

void writeSD(String fileToWrite, String textToWrite)
{
  file = SD.open(fileToWrite, FILE_WRITE);
  if(file)
  {
    Serial.println(F("Writing on "));
    Serial.print(fileToWrite);
    file.println(textToWrite);
    file.close();
    Serial.println(F("Done !"));
  }
  else
  {
    Serial.println(F("Error opening the file RMS_Test.txt"));
  }
}

void readSD(String fileToRead)
{
  file = SD.open(fileToRead);
  if(file)
  {
    Serial.println(F("RMS_Test.txt : ")); //Change the name of the file (if new name, arduino will create the file on the SD)

    while(file.available())
    {
      Serial.write(file.read());
    }

    file.close();
  }
  else
  {
    Serial.println(F("Error opening "));
    Serial.print(fileToRead);
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
  sensorDS18B20.begin();


  // BMP085 sensor
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
  }
  
  // SD setup 
  initSD();

  // WiFi connection 
  connectToWiFi();
 
  
  Serial.println("Ready to garden! ");
}

/************************************/
/*****          loop()           ****/
/************************************/
void loop()
{
  timeCount();
  handleEvents();
}
