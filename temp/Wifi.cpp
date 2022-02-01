#include "Wifi.h"


void connectToWiFi(char* WLAN_SSID, char* WLAN_PASS) {


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
void WiFiConnectSmartConfig(){

  WiFi.mode(WIFI_AP_STA);
  WiFi.beginSmartConfig();
    // Wait for SmartConfig packet from mobile
  Serial.println("Waiting for SmartConfig.");
  while (!WiFi.smartConfigDone()) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("SmartConfig done.");


  Serial.println("Connecting to WiFi ");
  while (WiFi.status() != WL_CONNECTED) {
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
void WiFiConnectFromLib() {

  // Setting host name ...
  WiFi.setHostname(WLAN_HOSTNAME);

  // For every WiFi network in the library...
  for(int i=0; i<WLAN_LIB_N; i++){

    WiFi.begin(WLAN_SSID_LIB[i].c_str(), WLAN_PASS_LIB[i].c_str());

    Serial.print("Trying to connect to ");
    Serial.print(WLAN_NAME_LIB[i]);
    Serial.print(" (");
    Serial.print(WLAN_SSID_LIB[i]);
    Serial.println(")");

    int counter = 0;
    while (WiFi.status() != WL_CONNECTED && counter < WLAN_MAX_COUNT) {
      delay(500);
      Serial.print(".");
      counter++;
    }
    Serial.println();

    if (WiFi.status() == WL_CONNECTED){
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
    else{
      Serial.println("Failed to connect to ");
      Serial.print(WLAN_NAME_LIB[i]);
      Serial.print(" (");
      Serial.print(WLAN_SSID_LIB[i]);
      Serial.println(")");
    }
  }

  Serial.println("No WiFi successful connection AT ALL!! ");
}
void sendDataToGoogle(String params) {

  HTTPClient http;

  DPRINTLN("");
  DPRINT("Making a request to Google => ");
  String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + params;
  DPRINTLN(url);

  // Making connection ...
  http.begin(url, root_ca); //Specify the URL and certificate
  int httpCode = http.GET();
  String httpJSONobjString = http.getString();
  http.end();
}



/************************************/
/*****      HTTP/HTML       ****/
/************************************/

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML(minuteValuesSoilMoist1[indexCount], minuteValuesTempInt[indexCount], minuteValuesPressure[indexCount], extractTimestamp()));
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

void serverInit() {
  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");
}
