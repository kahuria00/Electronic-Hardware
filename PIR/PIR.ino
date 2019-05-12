int redled = 3;
int greenled =5;
int PIR=10;
int motionValue;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(PIR,INPUT);
 

}

void loop() {
 
motionValue=digitalRead(PIR);
for (int k=1;k>motionValue;k=k+2)
if(motionValue==HIGH){
digitalWrite(redled,HIGH);
delay(1000);
digitalWrite(redled,LOW);
delay(1000);

}

else{
  digitalWrite(greenled,HIGH);
  delay(1000);
  digitalWrite(greenled,LOW);
  delay(1000);
  
  
  
}




}
