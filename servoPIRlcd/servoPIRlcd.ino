#include <Servo.h>
Servo myservo;  
#include <LiquidCrystal.h>
LiquidCrystal lcd (7,8,9,10,11,12);



int pir= 6; 
int readValue;

void setup() {
                lcd.begin(16,2);// initialize the LCD 
                lcd.clear();
  
                
                  myservo.attach(5); 
                  pinMode(pir, INPUT);
                  
}
void loop() {
  readValue = digitalRead(pir);
  lcd.setCursor(0,0);
  if(readValue==HIGH){
  myservo.write(90);
  delay(1000);

  lcd.print("Value =  "); 
 lcd.print(analogRead(readValue)); 
  
  }
  
  
  else {
  myservo.write(0);
  delay(10);

}

              

}



