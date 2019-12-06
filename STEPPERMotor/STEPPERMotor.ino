#include <Stepper.h>
const float STEPS_PER_REV=32;
const float GEAR_RED=64;
const float STEPS_PER_OUT_REV=STEPS_PER_REV*GEAR_RED;
int StepsRequired;
Stepper steppermotor(STEPS_PER_REV,8,9,10,11);
int numbItems

void setup() {
 Serial.begin(9600);
 Serial.print("how many items do you want?");
 whilee (Serial.available()==0){
  numbItems=Serial.parseInt();
 }

}

void loop() {
stp();

}

void stp(){
  steppermotor.setSpeed(600);
  StepsRequired=STEPS_PER_OUT_REV/2;
  steppermotor.step(StepsRequired);
  delay(2000);

StepsRequired=STEPS_PER_OUT_REV/2;
steppermotor.setSpeed(100);
steppermotor.step(StepsRequired);
delay(2000);

StepsRequired=-STEPS_PER_OUT_REV/2;
steppermotor.setSpeed(700);
steppermotor.step(StepsRequired);
delay(2000);


}

