

int redled=8;
int greenled=10;
int orangeled=12;
int button=2;
int buttonValue=0;

void setup() {
    
    pinMode(redled,OUTPUT);
    pinMode(greenled,OUTPUT);
    pinMode(orangeled,OUTPUT);
    pinMode(button,INPUT);
  // put your setup code here, to run once:

}

void loop() {
    buttonValue=digitalRead(button);
    if (buttonValue==HIGH){
    changeLights();
    }
}
 void changeLights(){
   digitalWrite(redled,HIGH);
   delay(5000);
   digitalWrite(orangeled,HIGH);
   delay(2000);
   digitalWrite(redled,LOW);
   digitalWrite(orangeled,LOW);
   digitalWrite(greenled,HIGH);
   delay(5000);
   digitalWrite(greenled,LOW);
   delay(1000);
    
  
  // put your main code here, to run repeatedly:

}

