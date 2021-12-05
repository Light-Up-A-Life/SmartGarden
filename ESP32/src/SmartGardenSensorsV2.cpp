// -------------------------------------- //
//              Smart Garden              //
// -------------------------------------- //

// By El Jose & El Kike & El Alejo (JKA Inc.)
// Last update: 15/11/2020

#define VERSION "1.0.1"
// -------------------------------------- //
//                Libraries               //
// -------------------------------------- //
#include <SD.h>
#include <SPI.h>
#include "time.h"

// #include <Vcc.h>

#include <OneWire.h>           // For the DS18B20 (External temp sensor)
#include <DallasTemperature.h> // For the DS18B20 (External temp sensor)

#include <Wire.h>            // For the BMP180 (Internal temp sensor & pressure)
#include <Adafruit_BMP085.h> // For the BMP180 (Internal temp sensor & pressure)

#include <WiFi.h>       // For WiFi connection
#include <HTTPClient.h> // For WiFi connection
#include <WebServer.h>
#include "HTMLSite.h" // For Webpage Interface(HTML)
#include "Debugging.h"
#include <sstream>
#include <vector>
#include <string>

// -------------------------------------- //
//              Constants                 //
// -------------------------------------- //
const int SAMPLING_N = 10;
const int MAX_ITER_GSM = 1;

// -------------------------------------- //
//              Anemometer                //
// -------------------------------------- //
const int PIN_ANEMO = 32;

// Anemometer data
const float VccCorrection = 5.03 / 5.05; // Measured Vcc by multimeter divided by reported Vcc
// Vcc vcc(VccCorrection);
int internalVcc = 5; // in Volts
float windSpeedCalib = 1.0;
float windM = 1 + 0 * 0.1406;
float windC = 0 * 11.312;
float anemometerVoltageMin = 0.42;

// -------------------------------------- //
// External temperature sensor (DS18B20)  //
// -------------------------------------- //

// Pin selection
const int PIN_DS18B20_ONEWIRE = 25;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(PIN_DS18B20_ONEWIRE);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensorDS18B20(&oneWire);

// ------------------------------------------------- //
// Internal temperature & preasure sensor (BMP180)   //
// ------------------------------------------------- //

const int PIN_BMP180_SDA = 21;
const int PIN_BMP180_SCL = 22;

Adafruit_BMP085 bmp;

// ------------------------------------------------- //
//              Soil Moisture sensor                 //
// ------------------------------------------------- //

// Pin selection
const int PIN_SOIL_MOIST1 = 34;
const int PIN_SOIL_MOIST2 = 35;
const float MOIST_RAW_MIN = 3500; // Air value
const float MOIST_RAW_MAX = 1280; // Very very wet soil. Storm simulation

// -------------------------------------- //
//        Current & Voltage sensor        //
// -------------------------------------- //

// TODO: NOT DEVELOPED YET
const int PIN_CURRENT_SENSOR = 0;
const int PIN_VOLTAGE_SENSOR = 0;
const int PIN_VIBRATION_SENSOR = 0;

// -------------------------------------- //
//           Sensors' booleans            //
// -------------------------------------- //

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
//               GSM MODULE               //
// -------------------------------------- //

struct GSM
{
  int sec;
  int min;
  int hour;
  int day;
  int mon;
  int year;
  float longitude;
  float latitude;
} gsmModule;

// -------------------------------------- //
//               Time events              //
// -------------------------------------- //

// Duration values for the different events
const long SECOND_MS = 1000;
const long MINUTE_MS = 10000;   // Real value: 60k
const long HOUR_MS = 600000000; // Real value: 3.6M

unsigned long previousMillisMinute = 0, previousMillisHour = 0, previousMillisSec = 0;
bool minutePassedEvent, hourPassedEvent, secPassedEvent;

const int SIZE_STACK_SENSORS = 60;
float minuteValuesTempInt[SIZE_STACK_SENSORS];    //Create one for every sensor that we want to store
float minuteValuesTempExt[SIZE_STACK_SENSORS];    //Create one for every sensor that we want to store
float minuteValuesAnemo[SIZE_STACK_SENSORS];      //Create one for every sensor that we want to store
float minuteValuesSoilMoist1[SIZE_STACK_SENSORS]; //Create one for every sensor that we want to store
float minuteValuesSoilMoist2[SIZE_STACK_SENSORS]; //Create one for every sensor that we want to store
float minuteValuesPressure[SIZE_STACK_SENSORS];   //Create one for every sensor that we want to store
int indexCount = 0;

// -------------------------------------- //
//                SD card                 //
// -------------------------------------- //

File file; //Our text file
const int SDCARD_INIT_MAX_ITER = 5;

#define SDCARD_CS_PIN 5
// const int SDCARD_CS_PIN =  5;      // white
const int SDCARD_MOSI_PIN = 23; // blue
const int SDCARD_MISO_PIN = 19; // green
const int SDCARD_SCK_PIN = 18;  // yellow (or CLK)

// -------------------------------------- //
//              SMS logging               //
// -------------------------------------- //

// Serial Serial2(5, 6); //The sim card is connected to here
String data, timestamp, timeToWrite, stringToWriteSD, smsToWrite; //Do I really need all of them?

int hourAverageAnem, hourMaxAnem;
int hourAverageTempExt, hourMaxTempExt;
int hourAverageTempInt, hourMaxTempInt;

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;

bool B0_SMS = false;
// const String numberSMS = "+33620337258";
const String numberSMS = "+33770451126";

#define SerialAT Serial2

#define TINY_GSM_MODEM_SIM808 // Modem is SIM800
// #define TINY_GSM_RX_BUFFER   1024  // Set RX buffer to 1Kb
#define MODEM_TX 17
#define MODEM_RX 16

#include <TinyGsmClient.h>

// Pins: TO BE REDEFINED
//GSM : Purple 5: RX Aruino-TX GSM Modue, green 6: TX Arduino - RX GSM Module
// Anemometer: Blue = Analog signal(ex: A0), Brown = Voltage(7-12V) -> Red cable for arduino, Black = Ground

/************************************/
/*****         Web Server        ****/
/************************************/

WebServer server(80); //Defining HTTP Port 80

// TODO: OTA (Over The Air)  !!

/************************************/
/*****      WiFi connection      ****/
/************************************/

// SmartConfig
#define SmartConfigOn false

#define WLAN_HOSTNAME "SmartGarden-MainController"

#define WLAN_MAX_COUNT 10

#define WLAN_LIB_N 3
String WLAN_NAME_LIB[] = {"Jose's House", "Kike's House", "Jose's House"};
String WLAN_SSID_LIB[] = {"SFR-5538", "SFR_6608", "SFR-5538"};
String WLAN_PASS_LIB[] = {"VHYWP9A2PVDU", "2cwt45yriv2urm57trbx", "VHYWP9A2PVDU"};

WiFiClientSecure client;

/************************************/
/*****      WiFi functions       ****/
/************************************/

void connectToWiFi(char *WLAN_SSID, char *WLAN_PASS)
{

  WiFi.mode(WIFI_STA);
  WiFi.begin(WLAN_SSID, WLAN_PASS);

  WiFi.setHostname(WLAN_HOSTNAME);
  while (WiFi.status() != WL_CONNECTED)
  {
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

void WiFiConnectSmartConfig()
{

  WiFi.mode(WIFI_AP_STA);
  WiFi.beginSmartConfig();
  // Wait for SmartConfig packet from mobile
  Serial.println("Waiting for SmartConfig.");
  while (!WiFi.smartConfigDone())
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("SmartConfig done.");

  Serial.println("Connecting to WiFi ");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("GatewayIP address: ");
  Serial.println(WiFi.gatewayIP());
  Serial.println("");
}

void WiFiConnectFromLib()
{

  // Setting host name ...
  WiFi.setHostname(WLAN_HOSTNAME);

  // For every WiFi network in the library...
  for (int i = 0; i < WLAN_LIB_N; i++)
  {

    WiFi.begin(WLAN_SSID_LIB[i].c_str(), WLAN_PASS_LIB[i].c_str());

    Serial.print("Trying to connect to ");
    Serial.print(WLAN_NAME_LIB[i]);
    Serial.print(" (");
    Serial.print(WLAN_SSID_LIB[i]);
    Serial.println(")");

    int counter = 0;
    while (WiFi.status() != WL_CONNECTED && counter < WLAN_MAX_COUNT)
    {
      delay(500);
      Serial.print(".");
      counter++;
    }
    Serial.println();

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.print("WiFi connected after ");
      Serial.print(counter);
      Serial.println(" attempts");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
      Serial.println("GatewayIP address: ");
      Serial.println(WiFi.gatewayIP());
      Serial.println("");
      return;
    }
    else
    {
      Serial.println("Failed to connect to ");
      Serial.print(WLAN_NAME_LIB[i]);
      Serial.print(" (");
      Serial.print(WLAN_SSID_LIB[i]);
      Serial.println(")");
    }
  }

  Serial.println("No WiFi successful connection AT ALL!! ");
}

/************************************/
/*****   Google API connection   ****/
/************************************/

String GOOGLE_SCRIPT_ID = "AKfycbwBxSvzfL3I2FONMZ5PMsvOz3tepmNEdXYv-K5YEiMN3g7jf51akX43cNY2YheowQYvPQ"; // Replace by your GAS service id



// Updated 04.12.2019
const char *root_ca =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIDujCCAqKgAwIBAgILBAAAAAABD4Ym5g0wDQYJKoZIhvcNAQEFBQAwTDEgMB4G\n"
    "A1UECxMXR2xvYmFsU2lnbiBSb290IENBIC0gUjIxEzARBgNVBAoTCkdsb2JhbFNp\n"
    "Z24xEzARBgNVBAMTCkdsb2JhbFNpZ24wHhcNMDYxMjE1MDgwMDAwWhcNMjExMjE1\n"
    "MDgwMDAwWjBMMSAwHgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMjETMBEG\n"
    "A1UEChMKR2xvYmFsU2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjCCASIwDQYJKoZI\n"
    "hvcNAQEBBQADggEPADCCAQoCggEBAKbPJA6+Lm8omUVCxKs+IVSbC9N/hHD6ErPL\n"
    "v4dfxn+G07IwXNb9rfF73OX4YJYJkhD10FPe+3t+c4isUoh7SqbKSaZeqKeMWhG8\n"
    "eoLrvozps6yWJQeXSpkqBy+0Hne/ig+1AnwblrjFuTosvNYSuetZfeLQBoZfXklq\n"
    "tTleiDTsvHgMCJiEbKjNS7SgfQx5TfC4LcshytVsW33hoCmEofnTlEnLJGKRILzd\n"
    "C9XZzPnqJworc5HGnRusyMvo4KD0L5CLTfuwNhv2GXqF4G3yYROIXJ/gkwpRl4pa\n"
    "zq+r1feqCapgvdzZX99yqWATXgAByUr6P6TqBwMhAo6CygPCm48CAwEAAaOBnDCB\n"
    "mTAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUm+IH\n"
    "V2ccHsBqBt5ZtJot39wZhi4wNgYDVR0fBC8wLTAroCmgJ4YlaHR0cDovL2NybC5n\n"
    "bG9iYWxzaWduLm5ldC9yb290LXIyLmNybDAfBgNVHSMEGDAWgBSb4gdXZxwewGoG\n"
    "3lm0mi3f3BmGLjANBgkqhkiG9w0BAQUFAAOCAQEAmYFThxxol4aR7OBKuEQLq4Gs\n"
    "J0/WwbgcQ3izDJr86iw8bmEbTUsp9Z8FHSbBuOmDAGJFtqkIk7mpM0sYmsL4h4hO\n"
    "291xNBrBVNpGP+DTKqttVCL1OmLNIG+6KYnX3ZHu01yiPqFbQfXf5WRDLenVOavS\n"
    "ot+3i9DAgBkcRcAtjOj4LaR0VknFBbVPFd5uRHg5h6h+u/N5GJG79G+dwfCMNYxd\n"
    "AfvDbbnvRG15RjF+Cv6pgsH/76tuIMRQyV+dTZsXjAzlAcmgQWpzU/qlULRuJQ/7\n"
    "TBj0/VLZjmmx6BEP3ojY+x1J96relc8geMJgEtslQIxq/H5COEBkEveegeGTLg==\n"
    "-----END CERTIFICATE-----\n";

void sendDataToGoogle(String params)
{

  HTTPClient http;

  DPRINTLN("");
  DPRINT("Making a request to Google => ");
  String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + params;
  DPRINTLN(url);

  http.begin(url, root_ca); //Specify the URL and certificate
  int httpJSONobjString = http.GET();
  http.end();
  Serial.println(": done "+httpJSONobjString);
}

/************************************/
/*****       GSM SETUP           ****/
/************************************/

bool initGNSModule()
{
  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  Serial.println("\n Initializing GSM module ...");
  //delay(3000);
  Serial.println("Communication AT check ...");
  String res = "";
  int countAT = 0;
  do
  {
    Serial2.println("AT"); //Send commands AT to module GSM
    res = Serial2.readString();
    Serial.println("res AT:" + res);
    countAT++;
  } while (res.indexOf("OK") < 0 && countAT < MAX_ITER_GSM);

  if (countAT == MAX_ITER_GSM)
  {
    Serial.printf("Failure after %d times  \n", countAT);
    return false;
  }
  else
  {
    BF_GSM_AT = true;
    Serial.printf("Successful after %d times  \n", countAT);
    //Power on GNS
    Serial.println("\n Getting the CGNSPWR");
    Serial2.println("AT+CGNSPWR=1");
    res = Serial2.readString();
    Serial.println("res AT+CGNSPWR:" + res);

    //Getting message
    Serial.println("\n Getting the CGNSINF");
    countAT = 0;
    do
    {
      Serial2.println("AT+CGNSINF");
      res = Serial2.readString();
      Serial.println("res AT+CGNSINF" + res);
      countAT++;
      //Split message
      std::stringstream ss(res.c_str());
      std::vector<std::string> v;
      while (ss.good())
      {
        std::string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
      }

      String timeStamp = v[2].c_str();
      String lat = v[3].c_str();
      String lon = v[4].c_str();
      gsmModule.latitude = lat.toFloat();
      gsmModule.longitude = lon.toFloat();
      gsmModule.year = timeStamp.substring(0, 4).toInt();
      gsmModule.mon = timeStamp.substring(4, 6).toInt();
      gsmModule.day = timeStamp.substring(6, 8).toInt();
      gsmModule.hour = timeStamp.substring(8, 10).toInt();
      gsmModule.min = timeStamp.substring(10, 12).toInt();
      gsmModule.sec = timeStamp.substring(12, 14).toInt();

      Serial.printf("Time GNS Module %d:%d:%d %d-%d-%d \n", gsmModule.hour, gsmModule.min, gsmModule.sec, gsmModule.day, gsmModule.mon, gsmModule.year);
      Serial.printf("GPS GNS Module  Latitude %.2f, Longitude %.2f \n", gsmModule.latitude, gsmModule.longitude);
      //Example msg +CGNSINF: 1,1,20201025145004.000,43.613070,1.440523,137.600,0.39,148.6,1,,1.2,1.5,0.9,,8,7,,,36,,
      if (gsmModule.year > 2015)
      {
        BF_GSM_TIME = true;
        Serial.printf("Successful time after %d times  \n", countAT);
      }
      else
      {
        Serial.printf("Faillure time after %d times  \n", countAT);
      }
      if (gsmModule.latitude > 0)
      {
        BF_GSM_GPS = true;
        Serial.printf("Successful after %d times  \n", countAT);
      }
      else
      {
        Serial.printf("Faillure GPS after %d times  \n", countAT);
      }
    } while ((!BF_GSM_TIME || !BF_GSM_GPS) && countAT < MAX_ITER_GSM);
    return true;
  }
}

bool gsmModuleStatus()
{
  Serial2.println("AT"); //Send commands AT to module GSM
  String res = Serial2.readString();
  DPRINTLN("res AT:" + res);
  return res.indexOf("OK") < 0;
}
void updateGSMStatus()
{
}

void printLocalTime()
{

  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.println(&timeinfo, "%d %m %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");

  Serial.println("Time variables");
  char timeHour[3];
  strftime(timeHour, 3, "%H", &timeinfo);
  Serial.println(timeHour);
  char timeWeekDay[10];
  strftime(timeWeekDay, 10, "%A", &timeinfo);
  Serial.println(timeWeekDay);
  Serial.println();
}

String extractTimestamp()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    return "null";
  }
  else
  {
    char timeBuffer[20];
    strftime(timeBuffer, 20, "%d-%m-%Y %H:%M:%S", &timeinfo);
    return String(timeBuffer);
  }
}

String extractTimestamp2(String clockData)
{
  DPRINT("Raw data : ");
  DPRINTLN(clockData);

  timestamp = clockData.substring(19, 36); //Indexes of starting and finishing point in the raw String

  DPRINT("Timestamp data : ");
  DPRINTLN(timestamp);

  return timestamp;
}

void sendMessage(String message) //Check if there is an error (or timeout) and store the values to send it next hour (care about memory)
{
  if (B0_SMS)
  {
    DPRINTLN("Sending the SMS ...");
    Serial2.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
    delay(1000);
    Serial2.println("AT+CMGS=\"+33770451126\"\r"); // Replace x with mobile number
    delay(1000);
    Serial2.println(message); // The SMS text you want to send
    delay(100);
    Serial2.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
  else
  {
    DPRINTLN("SMS messages have been deactivated. Check BO_SMS");
  }
}

void receiveMessage()
{
  Serial2.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}

/************************************/
/*****      HTTP/HTML       ****/
/************************************/

void handle_OnConnect()
{
  server.send(200, "text/html", SendHTML(minuteValuesSoilMoist1[indexCount], minuteValuesTempInt[indexCount], minuteValuesPressure[indexCount], extractTimestamp()));
}

void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}

void serverInit()
{
  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");
}

/*************************************/
/*****     Anemometer functions    ***/
/*************************************/

float readAnemometer(int pin)
{

  float anemometerVoltage = analogRead(pin); //*internalVcc/1024;

  float windSpeed;
  /*if( anemometerVoltage <= 0.42 ){  //0.4 is the minimum voltage for Anemometer
    windSpeed = -500; // Check if voltage is below minimum, if so, set wind speed to zero
    }
    else{*/
  windSpeed = (windM * anemometerVoltage) - windC;
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

int readSoilMoistureRaw(int pin)
{
  return analogRead(pin); // Returns measurement in 12 bits coding
}

float readSoilMoistureVolts(int pin)
{
  return readSoilMoistureRaw(pin) * 3.3 / 4095; // Returns mesurement in voltage. NodeMCU works ar 3.3V. For a 5V system, equation shall change.
}

float readSoilMoisturePercetage(int pin)
{
  return constrain((readSoilMoistureRaw(pin) - MOIST_RAW_MIN) * (100) / (MOIST_RAW_MAX - MOIST_RAW_MIN), -100, 200); // MIN/MAX values are according to test measurements in Joses garden. A dryer or wetter day can occure, therefore % above 100 are possible.
}

/************************************/
/***** Sensors: generic functions ***/
/************************************/

struct report
{
  int rmax;
  int rmin;
  int average;
};

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
  if (bFailure)
  {
    /*ERRORPRINTLN("");
    ERRORPRINT("Reading of type '");
    ERRORPRINT(type);
    ERRORPRINT("' in pin ");
    ERRORPRINT(pin);
    ERRORPRINTLN(" not available.");*/
    return 0;
  }

  //float sensorValues[sampling]; // TODO: NOT NECESSARY! But it works now. For later we can rewrite
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

  return sum / sampling;
}

struct report reportFunc(float values[], int indexCount)
{
  report myReport;
  myReport.rmax = values[0];
  myReport.rmin = values[0];
  myReport.average = values[0];
  for (int i = 1; i < indexCount; i++)
  {
    if (values[i] > myReport.rmax)
    {
      myReport.rmax = values[i];
    }
    if (values[i] < myReport.rmin)
    {
      myReport.rmin = values[i];
    }
    myReport.average += values[i];
  }
  myReport.average = round(myReport.average / indexCount);

  return myReport;
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

bool initSD()
{

  Serial.println(F("Initializing SD card ..."));
  int counter = 0;
  bool statusSD = false;

  do
  {
    statusSD = SD.begin();

    // Checking the output of the initialization
    if (statusSD)
    {
      Serial.println("SD card initiliazed");
      // Check if there is a card
      uint8_t cardType = SD.cardType();
      if (cardType == CARD_NONE)
      {
        Serial.println("No SD card attached");
        return false;
      }

      return true;
    }
    else
    {
      Serial.println("Initialization failed ! Trying again... ");
      counter++;
      delay(1000);
    }

  } while (!statusSD & (counter < SDCARD_INIT_MAX_ITER));

  Serial.println("SDcard not available AT ALL");
  return statusSD;
}

void writeSD(String fileToWrite, String textToWrite)
{
  file = SD.open(fileToWrite, FILE_APPEND);
  if (file)
  {
    Serial.print(F("Writing on "));
    Serial.println(fileToWrite);
    if (file.println(textToWrite))
    {
      ALERTPRINTLN("Append message done");
    }
    else
    {
      ERRORPRINTLN("Message dont append");
    }
    file.close();
  }
  else
  {
    Serial.println(F("Error opening the file RMS_Test.txt"));
  }
}

void readSD(String fileToRead)
{
  file = SD.open(fileToRead);
  if (file)
  {
    Serial.println(F("RMS_Test.txt : ")); //Change the name of the file (if new name, arduino will create the file on the SD)

    while (file.available())
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

    minuteValuesTempExt[indexCount] = approximateValues(PIN_DS18B20_ONEWIRE, "DS", SAMPLING_N, BF_DS_EXT_TEMP_1); //For every sensor
    minuteValuesAnemo[indexCount] = approximateValues(PIN_ANEMO, "ANEM", SAMPLING_N, BF_ANEMO_1);                 //For every sensor
    minuteValuesSoilMoist1[indexCount] = approximateValues(PIN_SOIL_MOIST1, "SOILM", SAMPLING_N, BF_SOILM_1);     //For every sensor
    minuteValuesSoilMoist2[indexCount] = approximateValues(PIN_SOIL_MOIST2, "SOILM", SAMPLING_N, BF_SOILM_2);     //For every sensor
    minuteValuesTempInt[indexCount] = approximateValues(0, "BMP_TEMP", SAMPLING_N, BF_BMP_1);                     //For every sensor
    minuteValuesPressure[indexCount] = approximateValues(0, "BMP_PRES", SAMPLING_N, BF_BMP_1);                    //For every sensor

    /*
      DPRINTLN();
      DPRINT("Averaged value of Temp : ");
      DPRINTLN(minuteValuesTempInt[indexCount]);
      DPRINT("Averaged value of Anemo : ");
      DPRINTLN(minuteValuesAnemo[indexCount]);
    */

    // Publishing to Google
    String params = "SoilMois1=" + String(minuteValuesSoilMoist1[indexCount]) + "&"
                                                                                "SoilMois2=" +
                    String(minuteValuesSoilMoist2[indexCount]) + "&"
                                                                 "TempInt=" +
                    String(minuteValuesTempInt[indexCount]) + "&"
                                                              "Pressure=" +
                    String(minuteValuesPressure[indexCount]);

    sendDataToGoogle(params);

    // Value for HTTP Server
    // handle_OnConnect(minuteValuesSoilMoist1[indexCount], minuteValuesTempInt[indexCount], minuteValuesPressure[indexCount])
    server.handleClient();
    //

    indexCount++;
  }

  if (minutePassedEvent == true) //Store the average + timestamp in SD card
  {
    updateGSMStatus();
    //DPRINTLN("Test for ONLY getClock()");
    //DPRINTLN(getClock());

    timeToWrite = extractTimestamp();
    stringToWriteSD = "";

    DPRINTLN("Reacting to minute passed");
    DPRINT("indexCount = ");
    DPRINTLN(indexCount);

    // Creation of reports (avg, max, min)
    report reportTempExt = reportFunc(minuteValuesTempExt, indexCount);
    report reportAnemo = reportFunc(minuteValuesAnemo, indexCount);

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
    writeSD("/RMS_Test.txt", stringToWriteSD);

    // Reinitialization of MINUTES arrays and variables
    indexCount = 0;
    memset(minuteValuesTempExt, 0, indexCount); //Important : free memory for local variables
    memset(minuteValuesAnemo, 0, indexCount);   //Important : free memory for local variables
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

void computeValues(int threshold, int value, int pinSensor)
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
  sensorDS18B20.begin();

  // BMP085 sensor
  if (!bmp.begin())
  {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    BF_BMP_1 = true;
  }

  // SD setup
  BF_SDCARD = initSD();

  // WiFi connection
  if (SmartConfigOn)
  {
    WiFiConnectSmartConfig();
  }
  else
  {
    WiFiConnectFromLib();
  }

  // Server initialization for local Web page and OTA
  serverInit();

  // Initialization GSM module
  Serial2.begin(115200);
  if (Serial2.available())
  {
    Serial.println("GSM module active");
  }
  else
  {
    Serial.println("GSM module NOT active");
  }

  bool B0_GNS = initGNSModule();
  DPRINTLN("B0_GNS flag"+ B0_GNS);
  // Init and get the time by server
  // configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // printLocalTime();

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