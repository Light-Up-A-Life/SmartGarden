#include "GsmModule.h"

float GsmModule::getSensorData() { return 0.0; }

bool GsmModule::setUp() {
  Serial2.begin(115200, SERIAL_8N1, 16, 17); // TODO: Use pins variable
  // delay(3000);

  Serial.println("Communication AT check ...");
  String res = "";
  int countAT = 0;
  do {
    res = GsmModule::sendATCmd("AT");
    countAT++;
  } while (res.indexOf("OK") < 0 && countAT < MAX_ITER);

  if (countAT == MAX_ITER) {
    Serial.printf("Failure after %d times  \n", countAT);
    return false;
  } else {
    Serial.printf("Successful after %d times  \n", countAT);
    // Unlock pin
    GsmModule::sendATCmd("AT+CPIN=\"0000\"");
    // Send sms
    GsmModule::sendSMS("Smart garden set up");
    // Send to server
    GsmModule::sendToServer("hola");
  }
  return true;
}

bool GsmModule::sendSMS(String msg) {
  // Enable SMS
  GsmModule::sendATCmd("AT+CMGF=1");
  //Send sms
  Serial2.print("AT+CMGS=\"+33770451126\"\r");
  delay(50);
  Serial2.print(msg);
  delay(50);
  Serial2.print((char)26);
  delay(50);
  Serial2.println();
  Serial.println("SentMessage");
  String res = Serial2.readString();
  Serial.println("res sms:" + res);
  return true;
}

bool GsmModule::sendToServer(String msg){
  GsmModule::sendATCmd("AT+NETCLOSE");

  GsmModule::sendATCmd("AT+CSOCKSETPN=1");
  GsmModule::sendATCmd("AT+CIPMODE=0");
  GsmModule::sendATCmd("AT+NETOPEN");
  GsmModule::sendATCmd("AT+IPADDR");
  GsmModule::sendATCmd("AT+CIPOPEN=0,\"TCP\",\"91.68.60.139\",10026");
  Serial2.print("AT+CIPSEND=0,\r");
  delay(100);
  Serial2.print(msg);
  delay(10);
  Serial2.print((char)26);
  delay(100);
  Serial2.println();
  Serial.println("SentMessage");
  String res = Serial2.readString();
  Serial.println("res sms:" + res);
  GsmModule::sendATCmd("AT+NETCLOSE");

  return true;
}

String GsmModule::sendATCmd(String msg){
// Enable SMS
  String res ="";
  Serial2.println(msg);
  res = Serial2.readString();
  Serial.println("res:" + res);
  return res;
}
/*

bool GsmModule::setUp(){
  Serial2.begin(115200, SERIAL_8N1, 16, 17); //TODO: Use pins variable
  //delay(3000);

  Serial.println("Communication AT check ...");
  String res = "";
  int countAT = 0;
  bool BF_GSM_TIME = false;
  bool BF_GSM_GPS = false;
  do{
    Serial2.println("AT"); //Send commands AT to module GSM
    res = Serial2.readString();
    Serial.println("res AT:" + res);
    countAT++;
  }while(res.indexOf("OK")<0 && countAT < MAX_ITER);

  if (countAT==MAX_ITER){
    Serial.printf("Failure after %d times  \n",countAT);
    return false;
  }
  else{
    Serial.printf("Successful after %d times  \n",countAT);
    //Power on GNS
    Serial.println("\n Getting the CGNSPWR");
    Serial2.println("AT+CGNSPWR=1");
    res = Serial2.readString();
    Serial.println("res AT+CGNSPWR:" + res);

    //Getting message
    Serial.println("\n Getting the CGNSINF");
    countAT = 0;
    do{
      Serial2.println("AT+CGNSINF");
      res = Serial2.readString();
      Serial.println("res AT+CGNSINF" + res);
      countAT++;
      //Split message
      std::stringstream ss(res.c_str());
      std::vector<std::string> v;
      while (ss.good()) {
        std::string substr;
        getline(ss, substr,',');
        v.push_back(substr);
      }
      String timeStamp = v[2].c_str();
      String lat = v[3].c_str();
      String lon = v[4].c_str();
      gsmModule.latitude = lat.toFloat();
      gsmModule.longitude = lon.toFloat();
      gsmModule.year = timeStamp.substring(0,4).toInt();
      gsmModule.mon = timeStamp.substring(4,6).toInt();
      gsmModule.day = timeStamp.substring(6,8).toInt();
      gsmModule.hour = timeStamp.substring(8,10).toInt();
      gsmModule.min = timeStamp.substring(10,12).toInt();
      gsmModule.sec = timeStamp.substring(12,14).toInt();

      Serial.printf( "Time GNS Module %d:%d:%d %d-%d-%d \n",
gsmModule.hour,gsmModule.min, gsmModule.sec, gsmModule.day,  gsmModule.mon,
gsmModule.year); Serial.printf( "GPS GNS Module  Latitude %.2f, Longitude %.2f
\n", gsmModule.latitude,gsmModule.longitude);
     //Example msg +CGNSINF:
1,1,20201025145004.000,43.613070,1.440523,137.600,0.39,148.6,1,,1.2,1.5,0.9,,8,7,,,36,,
      if(gsmModule.year>2015){
        BF_GSM_TIME = true;
        Serial.printf("Successful time after %d times  \n",countAT);
      }
      else{
        Serial.printf("Faillure time after %d times  \n",countAT);
      }
      if(gsmModule.latitude>0){
        BF_GSM_GPS = true;
        Serial.printf("Successful after %d times  \n",countAT);
      }
      else{
        Serial.printf("Faillure GPS after %d times  \n",countAT);
      }
    }while((!BF_GSM_TIME || !BF_GSM_GPS) && countAT < MAX_ITER);
    return true;
  }
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
void sendMessage(String message)
{
 //Check if there is an error (or timeout) and store the values to send it next
hour (care about memory) if (B0_SMS)
  {
    DPRINTLN("Sending the SMS ...");
    Serial2.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
    delay(1000);
    Serial2.println("AT+CMGS=\"+33770451126\"\r"); // Replace x with mobile
number delay(1000); Serial2.println(message); // The SMS text you want to send
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

bool gsmModuleStatus()
{
    Serial2.println("AT"); //Send commands AT to module GSM
    String res = Serial2.readString();
    DPRINTLN("res AT:" + res);
    return res.indexOf("OK")<0;
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

  timestamp = clockData.substring(19, 36); //Indexes of starting and finishing
point in the raw String

  DPRINT("Timestamp data : ");
  DPRINTLN(timestamp);

  return timestamp;
}*/
