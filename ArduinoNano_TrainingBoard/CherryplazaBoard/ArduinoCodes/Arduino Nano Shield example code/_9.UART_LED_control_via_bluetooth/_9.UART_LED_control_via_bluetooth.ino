//--- Begin code (copy from here)---
#include <SoftwareSerial.h>
SoftwareSerial BT (5,6); //TX RX respectively
int ch ;
int led = 6;

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available()>0){
    ch = BT.read();
    Serial.println(ch);
    if(ch == 1){
      digitalWrite(led,HIGH);
    }

    if(ch == 0){
      digitalWrite(led,LOW);
    }
  }
}
//--- End code (copy to here)---

