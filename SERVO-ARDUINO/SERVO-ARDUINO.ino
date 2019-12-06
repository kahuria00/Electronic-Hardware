#include<Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
Servo servopin;

int Readvalue;
void setup() {
 lcd.init();
lcd.init();
lcd.backlight();
lcd.setCursor(3,0);
servopin.attach(9);
pinMode(PIR,INPUT);
}
void loop() {
Readvalue=digitalRead(PIR);
if(Readvalue==HIGH){
   lcd.setCursor(0,0);
   lcd.print("25c");
servopin.write(80);
delay(1000);
lcd.print("value 1=30c ");
lcd.print(analogRead(Readvalue));
}
else{
  lcd.setCursor(0,0);
  lcd.print("40c");
  servopin.write(0);
delay(100);
}
}


