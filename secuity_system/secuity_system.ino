int REDLED =8;
int buzzer=10;
int PIR=6;

void setup() {
  Serial.begin(9600);
  pinMode(REDLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(PIR,INPUT);

}

void loop() {
 if(digitalRead(PIR)==HIGH){
  digitalWrite(REDLED,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(REDLED,LOW);
  digitalWrite(buzzer,LOW);
  delay(1000);
  Serial.println("THIEF THIEF!!!");  
  }
 else{
  digitalWrite(REDLED,LOW);
  digitalWrite(buzzer,LOW);
  Serial.println("Scanning ..");
  delay(1000);
 } 
 }

