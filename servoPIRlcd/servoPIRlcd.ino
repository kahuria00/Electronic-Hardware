#include <Servo.h>
Servo myservo;  
#include <LiquidCrystal.h>
LiquidCrystal lcd (7,8,9,10,11,12);



int pir= 10; 
int readValue;

void setup() {
                lcd.begin(16,2);// initialize the LCD 
                lcd.clear();
  
                
                  myservo.attach(6); 
                  pinMode(pir, INPUT);
                  
}
void loop() {
  readValue = analogRead(pir);
  
  if(readValue==HIGH){
  myservo.write(90);
  delay(1000);
  
  }
  
  
  else {
  myservo.write(0);
  delay(10);

}

              lcd.setCursor(0,0);// first row
              lcd.print("Motion  dectected   "); //displays on LCD
              lcd.print(analogRead(pir)); //print the read value from the ultrasonic sensor

              delay(500);

}



