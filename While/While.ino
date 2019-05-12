int redled=8;
int blueled=10;

int blinkred;
int blinkblue;

int redon;
int redoff;

int blueon;
int blueoff;

void setup() {
  Serial.begin(9600);
  pinMode(redled,OUTPUT);
  pinMode(blueled,OUTPUT);
 
  Serial.println("This is my Blinking program");
  Serial.println("");
  
  Serial.println("How Many redled blinks?");
  while(Serial.available()==0){};
  blinkred= Serial.parseInt();

  Serial.println("How Long should reled be on?");
  while(Serial.available()==0){};
  redon=Serial.parseInt();

  Serial.println("How Long Should redled be off?");
  while(Serial.available()==0){};
  redoff=Serial.parseInt();

  

   Serial.println("How  many times does blueled blinks");
   while (Serial.available()==0){};
   blinkblue=Serial.parseInt ();

   Serial.println("How Long Should blueled be on?");
  while(Serial.available()==0){};
  blueon=Serial.parseInt();

  Serial.println("How Long Should blueled be off?");
  while(Serial.available()==0){};
  blueoff=Serial.parseInt();

  Serial.println("");
  
}


void loop() {
  for (int x=1;x<=blinkred;x=x+1)
  {
  
  Serial.print("This is the redled blinking #");
  Serial.println(x);  
  digitalWrite(redled,HIGH);
  delay(redon);
  digitalWrite(redled,LOW);
  delay(redoff);
  }
   Serial.println("");
   
  for(int y=1;y<=blinkblue;y=y+1)
  {
  Serial.print("This is the blueled blinking #");
  Serial.println(y);
  digitalWrite(blueled,HIGH);
  delay(blueon);
  digitalWrite(blueled,LOW);
  delay(blueoff);
  }
    Serial.println("");
  
}
