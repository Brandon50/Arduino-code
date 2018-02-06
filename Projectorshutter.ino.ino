#include <Servo.h> 
#include "IRLibAll.h"
#include <IRLibRecvPCI.h> 
Servo servoLeft;
Servo servoRight;
IRrecvPCI myReceiver(2);
IRdecode myDecoder;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial);
  myReceiver.enableIRIn();
  Serial.println(F("Active"));

servoRight.attach(9); servoLeft.attach(12); 
}
void loop() {
  // put your main code here, to run repeatedly:
     if(myReceiver.getResults()) {
      myDecoder.decode();
     if(myDecoder.value==0xA10C840B){
      Serial.println("TURN");     
      servoRight.writeMicroseconds(1700);     //Second right
  servoLeft.writeMicroseconds(1700);
delay(360);
servoRight.writeMicroseconds(1500);
servoLeft.writeMicroseconds(1500);      //Stop
delay(2000);}
    myReceiver.enableIRIn(); 
  }
}


