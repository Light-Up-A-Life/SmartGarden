 /*  PINOUT ARDUINO NANO
 CS   -->  D10
 SCK  -->  D13
 MOSI -->  D12
 MISO -->  D11
*/
#include <SD.h>
#include <SPI.h>


void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}

void setup()
{

  Serial.begin(115200);
  Serial.println("Initializing SD Card . . .");

  if(!SD.begin()){
      Serial.println("Initializing SD Card failed");
      return;
  }

  Serial.println("Initializing succesfull");
  delay(1000);
  File file = SD.open("testlog2.txt",FILE_WRITE);
  file.close();

  Serial.println("File created!");
}

void loop()
{
  String dataString = "Time:";
  dataString += String(millis());
  appendFile(SD, "/testlog2.txt", dataString.c_str());
  delay(1000);
}
