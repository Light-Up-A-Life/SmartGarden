 /*  PINOUT ARDUINO NANO
 CS   -->  D10
 SCK  -->  D13
 MOSI -->  D12
 MISO -->  D11
*/
#include <SD.h>
#include <SPI.h>

int CS_PIN = 4;

File file;

void setup()
{

  Serial.begin(115200);
  Serial.println("Initializing SD Card . . .");

  if(!SD.begin()){
      Serial.println("Initializing SD Card failed");
      return;
  }

  Serial.println("Initializing succesfull");

  file = SD.open("testlog.txt",FILE_WRITE);
  file.close();

  Serial.println("File created!");
}

void loop()
{
  if(SD.exists("testlog.txt")){
    Serial.println("File Exist");

    file = SD.open("testlog.txt", FILE_WRITE);

    if(file){
        Serial.println("Writing");
        file.println("Time: " + String(millis()));
        file.close();
    }
    else{
      Serial.println("No Writing..");
    }
  }
  else{
    Serial.println("File not exist");
  }
  delay(1000);
}

/* bool initializeSD()
{
  Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);

  /*
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
    return true;
  } else
  {
    Serial.println("SD card initialization failed");
    return false;
  }
  //
  int count = 1;
  while(!SD.begin(CS_PIN)){
    Serial.print("Trying to mount the sd card: Attempt no.");
    Serial.println(count);
    delay(1000);
    count ++;
  }
}

int createFile(char filename[])
{
  file = SD.open(filename, FILE_WRITE);

  if (file)
  {
    Serial.println("File created successfully.");
    return 1;
  } else
  {
    Serial.println("Error while creating file.");
    return 0;
  }
}

int writeToFile(char text[])
{
  if (file)
  {
    file.println(text);
    Serial.println("Writing to file: ");
    Serial.println(text);
    return 1;
  } else
  {
    Serial.println("Couldn't write to file");
    return 0;
  }
}

void closeFile()
{
  if (file)
  {
    file.close();
    Serial.println("File closed");
  }
}

int openFile(char filename[])
{
  file = SD.open(filename);
  if (file)
  {
    Serial.println("File opened with success!");
    return 1;
  } else
  {
    Serial.println("Error opening file...");
    return 0;
  }
}

String readLine()
{
  String received = "";
  char ch;
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
    {
      received += ch;
    }
  }
  return "";
}*/
