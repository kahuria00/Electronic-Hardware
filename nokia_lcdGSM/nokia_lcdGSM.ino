
// Include Libraries
#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"


// Pin Definitions
#define NOKIALCD_PIN_CS  2
#define NOKIALCD_PIN_RST  5
#define NOKIALCD_PIN_DC 4
#define SIM800L_SOFTWARESERIAL_PIN_TX 10
#define SIM800L_SOFTWARESERIAL_PIN_RX 3



// Global variables and defines
//define Nokia LCD contrast and dimentions(in pixels)
#define LCD_CONTRAST 60
#define LCD_SIZE_COL 84
#define LCD_SIZE_ROW 48
int nokiaLcdCounter = 0;
// object initialization
Adafruit_PCD8544 nokiaLcd(NOKIALCD_PIN_DC,NOKIALCD_PIN_CS,NOKIALCD_PIN_RST);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    //Initialize Nokia instance
    nokiaLcd.begin(LCD_SIZE_COL, LCD_SIZE_ROW);
    nokiaLcd.setContrast(LCD_CONTRAST); //Adjust display contrast
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // Graphic LCD 84x48 - Nokia 5110 - Test Code
    nokiaLcd.clearDisplay();             //Erase & clear display buffer
    nokiaLcd.setTextColor(BLACK);        //Set text color to black, background is white by default
    nokiaLcd.setTextSize(1);             //set text size
    nokiaLcd.println("circuito.io");     //print to screen
    nokiaLcd.println();                  
    nokiaLcd.setTextColor(WHITE, BLACK); //set text color to white and backgroung to black
    nokiaLcd.setTextSize(2);             //set text size
    nokiaLcd.println(nokiaLcdCounter++);          //print to screen
    nokiaLcd.display();                  //display on screen
    }
    else if(menuOption == '2')
    {
    // Disclaimer: The QuadBand GPRS-GSM SIM800L is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Graphic LCD 84x48 - Nokia 5110"));
    Serial.println(F("(2) QuadBand GPRS-GSM SIM800L"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
          Serial.println(F("Now Testing Graphic LCD 84x48 - Nokia 5110"));
        else if(c == '2') 
          Serial.println(F("Now Testing QuadBand GPRS-GSM SIM800L - note that this component doesn't have a test code"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
