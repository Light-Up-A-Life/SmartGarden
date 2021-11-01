#include "Display.h"
#include "LogoMinka.h"


using std::string;


Display::Display(void){
    // myDisplay.begin();
}

bool Display::setup(){
    
    try{
        
        myDisplay.begin();
        myDisplay.sleepOff();
        
        // Flip screen, if required
        if (FLIP_MODE)
            Serial.println("Flipping the screen ");
        myDisplay.setFlipMode(FLIP_MODE);

        // Set up of the default font
        myDisplay.setFont(u8g2_font_6x10_tf);

        // Other display set-ups
        myDisplay.setFontRefHeightExtendedText();
        myDisplay.setFontPosTop();

        bFailure = false;
        return true;
    }
    catch(int e){
        Serial.println("Not possible to activate the display");
        bFailure = true;
        return false ;
    }
    

}

void Display::displayImage(const unsigned char * u8g_image_bits){
   myDisplay.firstPage();
   do {
       myDisplay.drawXBMP( 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, u8g_image_bits);
   } while( myDisplay.nextPage() );

}

void Display::showInitialDisplay(){
    displayImage(logoMinka);
}

void Display::showMainDisplay(std::vector<Sensor *> listSensor){

    char buffer[20];

    do {
        myDisplay.setFont(u8g2_font_6x10_tf);
        myDisplay.setFontPosBottom(); // setFontPosTop()
        
        int xCursor = 5 ;
        int yCursor = 5 ;   
        int deltaX = 15;

        // Going thru all the sensors
        for (Sensor *s : listSensor) {
            float v = s->read(10);
            sprintf(buffer, "%0.3f", v);

            // Displaying the name of the sensor 
            myDisplay.setCursor(xCursor, yCursor); // (width,height) => (x, y)
            myDisplay.print(s->name.c_str());

            // Displaying the value of the sensor 
            myDisplay.setCursor(xCursor + deltaX, yCursor); // (width,height) => (x, y)
            myDisplay.print(buffer);
            
            // Serial.printf("value %0.3f \n", v);
        }
        // true? myDisplay.print("???"): myDisplay.print(int(val), 10);

    } while(myDisplay.nextPage());
}

void Display::displayLoop(std::vector<Sensor *> listSensor){

    switch(status){
        case 0:
            Serial.println("");
            Serial.println("*------------------------------*");
            Serial.println("*       Initial display !!!    *");
            Serial.println("*------------------------------*");
            Serial.println("");

            showInitialDisplay();
            status++;
            break;

        case 1:
            Serial.println("");
            Serial.println("*------------------------------*");
            Serial.println("*         Main display !!!     *");
            Serial.println("*------------------------------*");
            Serial.println("");

            showMainDisplay(listSensor);
            break;

        default:
            Serial.println("ERROR: Problem with the display status");
            bFailure = true;

    }
}