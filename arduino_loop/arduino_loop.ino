int redled=8;
int blueled=10;

void setup() {
  pinMode(redled,OUTPUT);
  pinMode(blueled,OUTPUT);
  
  
  // put your setup code here, to run once:

}

void loop() {
  for( int k=1;k<=5;k=k+1){
  digitalWrite(redled,HIGH);
  delay(1000);
  digitalWrite(redled,LOW);
  delay(1000);
  }

  for(int L=1;L<=6;L=L+1){
  digitalWrite(blueled,HIGH);
  delay(1000);
  digitalWrite(blueled,LOW);
  delay(1000);

    }
  
  // put your main code here, to run repeatedly:

}
