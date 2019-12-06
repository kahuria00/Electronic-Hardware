#include <SPI.h> 
#include <MFRC522.h>
# include <servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

Servo servo;
int red = 7;
int green = 5;
int numblink;

 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("How many items do you want?");
  while(Serial.available()==0){};
  numblink=Serial.parseInt();

  Serial.println("Please make your payment?");
  Serial.println();
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "2E 39 30 5B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
    for(int j=1;j<numblink;j=j+1){
      digitalWrite(red,HIGH);
      delay(500);
    }
  }

    if (content.substring(1) == "B0 AF 5E 4D") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
     delay(3000);
    for(int j=1;j<numblink;j=j+1){
      digitalWrite(green,HIGH);
      delay(500);
      
    }
  }

  if 
 
 else   {
    Serial.println(" Access denied");
    delay(3000);
  }

   steppermotor.setSpeed(600);
   StepsRequired = STEPS_PER_OUT_REV*numOfItem;
   steppermotor.step(StepsRequired);
   delay(2000);
} 
