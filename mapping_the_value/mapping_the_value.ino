

int pinport=A0; //pinport declared

int blueled=10; //blueled declared

int Readvalue;// Readvalue declared

float Writevalue;//  Writevalue declared (float incase of decimal(type))
float voltage; // voltage declared(type of float)


void setup() {

    Serial.begin(9600);//serial monitor mode
    pinMode(pinport,INPUT);
    pinMode(blueled,OUTPUT);
    
  // put your setup code here, to run once:

}

void loop() {
   
   
   Readvalue=analogRead(pinport);
   Writevalue=(255./1023.)*Readvalue;// calculate write value
   voltage=(5./1023.)*Readvalue;
   analogWrite (blueled,Writevalue);//write value
   
   Serial.print("Pin value");
   Serial.print(Readvalue);
   Serial.print("");
   Serial.print("mapped Value");
   Serial.print("");
   Serial.print("voltage value");
   Serial.print("");
   Serial.println(voltage);
  

   analogWrite(blueled,HIGH); 
   delay(Readvalue);
   analogWrite(blueled,LOW);
   delay(Readvalue);// control the blinking time using the potentiometer.

   
  // put your main code here, to run repeatedly:

}

