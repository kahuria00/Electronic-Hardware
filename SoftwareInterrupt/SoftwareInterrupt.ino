#include <TimerOne.h>
String LEDStatus="OFF";
int YellowLED=10;
int RedLED=11;
 
void setup() {
  pinMode(YellowLed,OUTPUT);
  pinMode(RedLed,OUTPUT);

  Timer1.initialize(100000);
  Timer.attachInterrupt(BlinkYellow);
  Serial.begin(9600);
 }

void loop() {
  difitalWrite(RedLed,HIGH);
  delay(1000);
  digitalWrite(RedLed,LOW);
  delay(1000);
}

void BlinkYellow(){
  if(LEDStatus=="ON"){
    digitalWrite(YellowLed,LOW);
    LEDStatus="OFF";
    return;}

 if(LEDStatus=="OFF"){
  digitalWrite(YellowLed,HIGH);
  LEDStatus="ON"
  return:}
 }
    
  
  }
