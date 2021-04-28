#include "SdCard.h"

bool initSD()
{

  Serial.println(F("Initializing SD card ..."));
  int counter = 0;
  bool statusSD = false;

  do{
    statusSD = SD.begin();// SDCARD_CS_PIN

    // Checking the output of the initialization
    if (statusSD){
       Serial.println("SD card initiliazed");
      // Check if there is a card
      uint8_t cardType = SD.cardType();
      if(cardType == CARD_NONE) {
        Serial.println("No SD card attached");
        return false;
      }

       return true;
    }
    else{
      Serial.println("Initialization failed ! Trying again... ");
      counter++;
      delay(1000);
    }

  }while (!statusSD & (counter < SDCARD_INIT_MAX_ITER));

  Serial.println("SDcard not available AT ALL");
  return statusSD;

}
void writeSD(String fileToWrite, String textToWrite){
  file = SD.open(fileToWrite, FILE_WRITE);
  if (file){
    DPRINTLN(F("Writing on "));
    DPRINTLN(fileToWrite);

    // Writing on file 
    if (file.println(textToWrite)){
      DPRINTLN("Writing on SD card successful");
    }
    else{
      ERRORPRINTLN("Unable to write on SD card");
    }
    file.close();
  }
  else{
    Serial.println(F("Error opening the file"));
  }
}
void appendSD(String fileToWrite, String textToWrite){
  file = SD.open(fileToWrite, FILE_APPEND);
  if (file){
    DPRINTLN(F("Writing on "));
    DPRINTLN(fileToWrite);

    // Appending on file 
    if (file.println(textToWrite)){
      DPRINTLN("Writing on SD card successful");
    }
    else{
      ERRORPRINTLN("Unable to write on SD card");
    }
    file.close();
  }
  else{
    Serial.println(F("Error opening the file"));
  }
}
String readSD(String fileToRead){
  // Initializing variables 
  String fileText = "";
  file = SD.open(fileToRead);

  // Reading file
  if (file){
    DPRINTF("Reading '%s'", fileToRead.c_str()); 

    while (file.available()){
      char byteRead = (char)file.read()
      DEEPDPRINT(byteRead);
      fileText += byteRead;
    }
    file.close();
  }
  else{
    Serial.print(F("Error opening "));
    Serial.print(fileToRead);
  }
  return fileText;
}
void testSDcard(){
  String fileForTest= "/testSmartGarden.txt";
  String textToWrite= "Hola! I'm a test for the SD card !";
  String textToWrite2= "\n\nI'm a second test for the SD card !";
  
  writeSD(fileForTest,textToWrite);
  appendSD(fileForTest,textToWrite2);

  String fileRead =  readSD(fileForTest);
  Serial.print("File read:\nSTART\n");
  Serial.print(fileRead);
  Serial.print("\nEND");
}
