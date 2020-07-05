//--- Begin code (copy from here)---
void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);//initialize the led1 pin as OUTPUT
  pinMode(7,OUTPUT);//initialize the led2 pin as OUTPUT
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(6,HIGH);//LED1 ON
  delay(1000);//LED1 ON 1 second
  digitalWrite(6,LOW);//LED1 OFF
  digitalWrite(7,HIGH);//LED2 ON
  delay(1000);//LED2 ON 1 second
  digitalWrite(7,LOW);//LED2 OFF
}//--- End code (copy to here)---

