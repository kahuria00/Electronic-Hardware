
#include <LiquidCrystal.h>
LiquidCrystal lcd (7,8,9,10,11,12);
int PIR=3;
int motion;

void setup() {

                lcd.begin(16,2);// initialize the LCD 
                lcd.clear();
                pinMode(PIR,INPUT);
 

}

void loop() {
              motion=analogRead(PIR);
                if(motion==HIGH){
                
              lcd.setCursor(0,0);// first row
              lcd.print("Motion detected   "); //displays on Lcd
              delay(500);
              }
 
  
  
}





  
  


