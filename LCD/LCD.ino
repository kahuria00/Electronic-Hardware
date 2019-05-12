# include<LiquidCrystal.h>
LiquidCrystal lcd (7,8,9,10,11,12);

int pinpot=A0;



void setup() {
                lcd.begin(16,2);// initialize the LCD 
                lcd.clear();

                pinMode(pinpot,INPUT);

           
                
  
  
}

void loop() {
              lcd.setCursor(0,0);// first row
              lcd.print("Value 1=    "); //displays on LCD
              lcd.print(analogRead(pinpot)); //print the read value from the potentiometer
 
}
