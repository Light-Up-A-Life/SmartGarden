#include <SoftwareSerial.h>

String Arsp, Grsp;
SoftwareSerial gsm(0, 1); // RX, TX

void setup() {
  // put your setup code here, to run once:

  Serial.begin(4800);
  Serial.println("Testing GSM SIM800L");
  gsm.begin(4800);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(gsm.available())
  {
    Grsp = gsm.readString();
    Serial.println(Grsp);
  }

  if(Serial.available())
  {
    Arsp = Serial.readString();
    gsm.println(Arsp);
  }

}
