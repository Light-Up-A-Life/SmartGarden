#include "Display.h"
#include "LogoMinka.h"


using std::string;


Display::Display(void){
    // myDisplay.begin();
    // status = 0;
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

        status = 0;

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

void Display::showTestDisplay(){
    
    myDisplay.firstPage();
    do {
        //myDisplay.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2); 
        //myDisplay.print("I AM A TEST !");
        myDisplay.setFont(u8g2_font_ncenB14_tr);
        myDisplay.drawStr(0,24,"Light Up");
        myDisplay.drawStr(0,44,"a Life");

    } while( myDisplay.nextPage() );
}


void Display::showMainDisplay(std::vector<Sensor *> listSensor){

    char buffer[20];
    myDisplay.firstPage();
    

    do {
        myDisplay.setFont(u8g2_font_6x10_tf);
        myDisplay.setFontPosTop(); // setFontPosBottom()
        
        int xCursor = 5 ;
        int yCursor = 5 ;   
        int deltaX = 45;
        int deltaY = 12;

        // Going thru all the sensors
        for (Sensor *s : listSensor) {
            float v = s->getValue();
            
            // Serial.printf("\nValue for display: %.2f\n", v);
            sprintf(buffer, "%.2f", v);

            // Displaying the name of the sensor 
            myDisplay.setFontPosTop();
            myDisplay.setCursor(xCursor, yCursor); // (width,height) => (x, y)
            myDisplay.print(s->nameDisplay.c_str());
            
            
            // Displaying the value of the sensor 
            myDisplay.setFontPosTop();
            myDisplay.setCursor(xCursor + deltaX, yCursor); // (width,height) => (x, y)
            myDisplay.print(buffer);
             

            yCursor = yCursor + deltaY;
            // Serial.printf("value %0.3f \n", v);
        }
        // true? myDisplay.print("???"): myDisplay.print(int(val), 10);

    } while(myDisplay.nextPage());
}

void Display::displayLoop(std::vector<Sensor *> listSensor){

    switch(status){
        case 0:
            /*
            Serial.println("");
            Serial.println("*------------------------------*");
            Serial.println("*         Test display !!!     *");
            Serial.println("*------------------------------*");
            Serial.println("");
            */
           
            showTestDisplay();
            status++;

            vTaskDelay(1000 / portTICK_PERIOD_MS);
            break;
            
        case 1:
            /*
            Serial.println("");
            Serial.println("*------------------------------*");
            Serial.println("*       Initial display !!!    *");
            Serial.println("*------------------------------*");
            Serial.println("");
            */

            showInitialDisplay();
            status++;

            vTaskDelay(1000 / portTICK_PERIOD_MS);
            break;

        case 2:
            /*
            Serial.println("");
            Serial.println("*------------------------------*");
            Serial.println("*         Main display !!!     *");
            Serial.println("*------------------------------*");
            Serial.println("");
            */

            showMainDisplay(listSensor);

            vTaskDelay(2000 / portTICK_PERIOD_MS);
            break;

        default:
            Serial.println("ERROR: Problem with the display status");
            bFailure = true;

    }
}
