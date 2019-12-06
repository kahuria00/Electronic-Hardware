  #include <PCD8544.h>
 PCD8544 lcd;
int flowPin = 2;    //This is the input pin on the Arduino
int flowRate=0;    //This is the value we intend to calculate. 
int flowAmount =0;
volatile int count; //This integer needs to be set as volatile to ensure it updates correctly during the interrupt process.  
//count = 0;  
int solenoid = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flowPin, INPUT);           //Sets the pin as an input
  attachInterrupt(0, Flow, RISING);  //Configures interrupt 0 (pin 2 on the Arduino Uno) to run the function "Flow"  
  lcd.begin(84, 48);  //Start Nokia LCD
  pinMode(solenoid, OUTPUT);
  digitalWrite(solenoid, HIGH); //enable flow
  count=0;
  
}
void loop() {
  // put your main code here, to run repeatedly:  
      // Reset the counter so we start counting from 0 again
  interrupts();   //Enables interrupts on the Arduino
  delay (1000);   //Wait 1 second 
  noInterrupts(); //Disable the interrupts on the Arduino
  lcd.setCursor(0, 0);
   
  //Start the math
  flowRate = (count * 2.25);        //Take counted pulses in the last second and multiply by 2.25mL 
//  flowRate = flowRate * 60;         //Convert seconds to minutes, giving you mL / Minute
//  flowRate = flowRate / 1000;       //Convert mL to Liters, giving you Liters / Minute
  lcd.print(flowRate);    //Print the variable flowRate to LCDo
  Serial.println(flowRate);

  if(flowRate >500){
    digitalWrite(solenoid, LOW);
    }
}
 
void Flow()
{
   count++; //Every time this function is called, increment "count" by 1
}
