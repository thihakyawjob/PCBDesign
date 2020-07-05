//--- Begin code (copy from here)---
int buzzer = 5;//variable for buzzer pin
void setup() {
  // put your setup code here, to run once;
 }
void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer,400); //tone(pinNumber,frequency)
  delay(500);
  noTone(buzzer);//noTone(pinNumber)
  delay(500);
}
//--- End code (copy to here)---

