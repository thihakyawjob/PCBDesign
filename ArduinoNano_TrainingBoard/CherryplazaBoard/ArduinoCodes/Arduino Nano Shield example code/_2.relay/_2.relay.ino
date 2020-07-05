//--- Begin code (copy from here)---
void setup() {
  // put your setup code here, to run once:
  pinMode(A3,OUTPUT);//initialize the relay pin as OUTPUT
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A3,HIGH);//NO->close, NC->open
  delay(1000);//delay 1 second
  digitalWrite(A3,LOW);//NO->open, NC->close(normal state)
  delay(1000);//delay 1 second
}
//--- End code (copy to here)---

