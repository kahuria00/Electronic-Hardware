
int echo=3;
int trig=5;
float distance;
float duration;

void setup() {
 

                pinMode(echo,INPUT);
                pinMode(trig,OUTPUT);

}

void loop() {
              digitalWrite(trig,LOW);
              delayMicroseconds(5);
              digitalWrite(trig,HIGH);
              delayMicroseconds(10);
              digitalWrite(trig,LOW);

              duration= pulseIn(echo,HIGH);
              distance=(duration/2)*0.0343 ;


             Serial.println("distance is ");
             Serial.print("");
             Serial.println(distance);
             
             delay(500);
             

}
