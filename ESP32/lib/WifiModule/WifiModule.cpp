#include "WifiModule.h"

void WifiModule::connectToWiFi(const std::string WLAN_SSID, const std::string WLAN_PASS) {
  // Setting host name ...
  WiFi.mode(WIFI_STA);
  //WiFi.setHostname(WLAN_HOSTNAME);

  WiFi.begin(WLAN_SSID.c_str(), WLAN_PASS.c_str());

  Serial.print("Trying to connect to ");
  Serial.print(" (");
  Serial.print(WLAN_SSID.c_str());
  Serial.println(")");

  int counter = 0;
  while (WiFi.status() != WL_CONNECTED && counter < WLAN_MAX_COUNT) {
    delay(500);
    Serial.print(".");
    counter++;
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("WiFi connected after ");
    Serial.print(counter);
    Serial.println(" attempts");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("GatewayIP address: ");
    Serial.println(WiFi.gatewayIP());
    Serial.println("");
    return;
  } else {
    Serial.println("Failed to connect to ");
    Serial.print(WLAN_SSID.c_str());
  }
  Serial.println("No WiFi successful connection AT ALL!! ");
}

void WifiModule::sendDataToGoogle(String params){
  Serial.print("");
  Serial.print("Making a request to Google => ");
  String url_req = url + params;
  Serial.print(url_req);

  http.begin(url_req, root_ca); //Specify the URL and certificate
  int httpJSONobjString = http.GET();
  http.end();

}

bool WifiModule::connectToServer(const char* host, const uint16_t port){
  if (!client.connect(host, port)) {
      return false;
    }
  return true;
}