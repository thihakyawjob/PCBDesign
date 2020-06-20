/*
  Blink

  Turns an LED1 and LED2 on for one second, then off for one second, repeatedly.

  modified 20 Jun 2020
  by THIHA KYAW

  This example code is for Cherryplaza Arduino Training Board
*/
int LED1=6;
int LED2=7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED2, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
  digitalWrite(LED1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
}
