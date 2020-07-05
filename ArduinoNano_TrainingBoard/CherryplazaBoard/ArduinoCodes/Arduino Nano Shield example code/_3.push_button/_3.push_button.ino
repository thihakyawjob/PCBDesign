//--- Begin code (copy from here)---
int buttonPin = 8; //pin number connect with button pin
int ledPin = 6; //pin number connect with LED1 pin
int buttonState = 0; //variable for reading the button status
void setup() {
  // put your setup code here, to run once:
  // initialize the LED pin as an output:
  pinMode(ledPin,OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
  // turn LED on:
  digitalWrite(ledPin, HIGH);
  } else {
  // turn LED off:
  digitalWrite(ledPin, LOW);
  }
}
//--- End code (copy to here)---

