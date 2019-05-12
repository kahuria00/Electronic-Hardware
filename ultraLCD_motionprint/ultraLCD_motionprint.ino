#include <LiquidCrystal.h>
LiquidCrystal lcd (7,8,9,10,11,12);

int echo=3;
int trig=5;
float distance;
float duration;

void setup() {
  lcd.begin(16,2);// initialize the LCD 
                lcd.clear();

                pinMode(echo,INPUT);
                pinMode(trig,OUTPUT);


}

void loop() {
              digitalWrite(trig,LOW);
              delayMicroseconds(2);
              digitalWrite(trig,HIGH);
              delayMicroseconds(10);
              digitalWrite(trig,LOW);

              duration= pulseIn(echo,HIGH);
              distance=(duration/2)*0.0343 ;

  
              lcd.setCursor(0,0);// first row
              lcd.print("The distance is    "); //displays on LCD
              lcd.print(analogRead(distance)); //print the read value from the ultrasonic sensor

              delay(500);
 

}
