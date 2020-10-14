#include <WiFi.h>
#include <HTTPClient.h>



/* For HTTPSRedirect */ 
#include "HTTPSRedirect.h"
#include "DebugMacros.h"

HTTPSRedirect* clientRedirect = nullptr;
const int httpsPort = 443;
const char* host = "script.google.com";
/* *********** */ 

//Things to change

#define WLAN_HOSTNAME   "SmartGarden-MainController"

// Jose's house:
#define WLAN_SSID       "SFR-5538"
#define WLAN_PASS       "VHYWP9A2PVDU"

// Kike's house:
/*
#define WLAN_SSID       "SFR_6608"
#define WLAN_PASS       "2cwt45yriv2urm57trbx"
*/


String GOOGLE_SCRIPT_ID = "AKfycby6m-J7Nof2ULsI72HIgboaE3o9nXXvW46crG2_IOePWZplCblh"; // Replace by your GAS service id

const int sendInterval = 1996 * 5; // in millis, 996 instead of 1000 is adjustment, with 1000 it jumps ahead a minute every 3-4 hours

//-------------

int firstTime = 1 ;

//updated 04.12.2019
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

void setup() {
  Serial.begin(115200);
  delay(10);


  Serial.println("Welcome to Smart Garden! ");
  connectToWiFi();

  Serial.println("Connecting to server with HTTPSredirect ... ");
  setupHTTPSRedirect();

  Serial.println("Ready to go");

}

//**********************************//
//**    HTPPSRedirect functions   **//
//**********************************//

void setupHTTPSRedirect() {
  // Use HTTPSRedirect class to create a new TLS connection
  clientRedirect = new HTTPSRedirect(httpsPort);
  // clientRedirect->setInsecure();
  clientRedirect->setPrintResponseBody(true);
  clientRedirect->setContentTypeHeader("application/json");

  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    int retval = clientRedirect->connect(host, httpsPort);
    if (retval == 1) {
      flag = true;
      break;
    }
    else
      Serial.println("Connection failed. Retrying...");
  }

  if (!flag) {
    Serial.print("Could not connect to server: ");
    Serial.println(host);
    Serial.println("Exiting...");
    return;
  }
}

//**********************************//
//**      Sensors functions       **//
//**********************************//

float getFakeTemperature() {
  return micros() % 20;
}

String fakeFunc1()
{
  return "Test";
}
float fakeFunc2()
{
  return millis() % 100;
}


void sandBoxSerialPort() {
  
  if (Serial.available())
  {
    char temp = Serial.read();
    switch (temp) {
      case 's':
      case 'S': sendData("info1=" + fakeFunc1() + "&info2=" + String(fakeFunc2()) + "&temp=" + String(getFakeTemperature()));
        break;
      case 'a':
        break;
      case 'z':
        break;
      case 't':
        break;
      default:
        break;
    }

  }

}


void loop() {

  if (firstTime == 1){
    Serial.print("Waiting ...");
    firstTime = 0;
  }

  
  sandBoxSerialPort();
  /*
    sendData("info1=" + fakeFunc1() + "&info2=" + String(fakeFunc2()) + "&temp=" + String(getFakeTemperature()));

    delay(sendInterval);
  */
}

void SendAlarm() {
  //use this function to notify if something wrong (example sensor says -128C)
  // don't forget to set true for enableSendingEmails in google script
  sendData("alarm=fixme");
}

void sendData(String params) {

  HTTPClient http;
  String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + params;
  Serial.println(url);

  Serial.println("Making a request");
  http.begin(url, root_ca); //Specify the URL and certificate
  int httpCode = http.GET();
  String httpJSONobjString = http.getString();
  http.end();

  Serial.println("HTTP Code");
  Serial.println(httpCode);

  Serial.println("HTTP String: ");
  Serial.println(httpJSONobjString);

  int i1 = httpJSONobjString.indexOf("<A HREF=\"");
  int i2 = httpJSONobjString.indexOf("\">here</A>");



  String urlRedirect = httpJSONobjString.substring(i1+9,i2);
  String urlKike = "http://www.google.com/";
  Serial.println("HTTP Redirect: ");
  Serial.println(urlRedirect);

  HTTPClient httpRedirect;
  Serial.println("Making a redirect");
  httpRedirect.begin(urlKike); //Specify the URL and certificate
  int httpCodeRedirect = httpRedirect.GET();
  String httpJSONobjStringRedirect = httpRedirect.getString();
  httpRedirect.end();

  Serial.println("HTTP Code redirect");
  Serial.println(httpCodeRedirect);
  
  Serial.println("HTML Redirect: ");
  Serial.println(httpJSONobjStringRedirect);



  
/*
  // Try with HTTPRedirect Library //
  String url3 = String("/macros/s/") + GOOGLE_SCRIPT_ID + "/exec?read";
  clientRedirect->GET(url3, host);
*/

}
