

int pinport=A0;

void setup() {

    Serial.begin(9600);
    pinMode(pinport,INPUT);
  // put your setup code here, to run once:

}

void loop() {
   int Readvalue;
   
   Readvalue=analogRead(pinport);
   Serial.println(Readvalue); 
   delay(1000);

   
  // put your main code here, to run repeatedly:

}

