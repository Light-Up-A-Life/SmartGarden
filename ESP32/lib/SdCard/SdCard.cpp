#include "SdCard.h"

bool SdCard::setUp(){
  Serial.println(F("Initializing SD card ..."));
  int counter = 0;
  bool bFailure = false;
  do{
    if (SD.begin()){
       Serial.println("SD card initiliazed");
      // Check if there is a card
      uint8_t cardType = SD.cardType();
      if(cardType == CARD_NONE) {
        Serial.println("No SD card attached");
        bFailure = true;
        return false;
      }
      bFailure = false;
      return true;
    }
    else{
      Serial.println("Initialization failed ! Trying again... ");
      counter++;
      bFailure = true;
      delay(1000);
    }

  }while (bFailure & (counter < MAX_ITER));
  Serial.println("SDcard not available AT ALL");
  return false;
}
float SdCard::getSensorData(){
  return 0.0;
}
bool SdCard::writeSD(String textToWrite){
  File file = SD.open(file_name, FILE_WRITE);
  if (file){
    file.println(textToWrite);
    file.close();
    return true;
  }
  else{
    Serial.println(F("Error opening the file"));
    return false;
  }
}

bool SdCard::appendSD(String textToWrite){
  File file = SD.open(file_name, FILE_APPEND);
  if (file){
    if (file.println(textToWrite)){
      file.close();
      return true;
    }
    else{
      Serial.println(F("Error appending message"));
    }
  }
  else{
    Serial.println(F("Error opening the file"));
    return false;
  }
  file.close();
  return false;
}
/*
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
*/
