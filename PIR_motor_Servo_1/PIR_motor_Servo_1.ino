#include <Servo.h> 
Servo myservo; 

int pir= 10; 
int state = LOW; 
int readValue;

void setup() {
  
                
                  myservo.attach(9); 
                  pinMode(pir, INPUT);
                  Serial.begin(9600); 
}
void loop() {
  readValue = digitalRead(pir);
  
  if(readValue==HIGH){
  myservo.write(90);
  delay(1000);
  
  }
  
  
  else {
  myservo.write(0);
  delay(10);

}

}



