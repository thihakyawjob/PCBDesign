/*
  Arduino Ultrasoninc Sensor HC-SR04

  modified 19 July 2020
  by THIHA KYAW

  This example code is for Cherryplaza Arduino Training Board
*/

#define echoPin 3 // attach pin A5, J3-4  to pin Echo of HC-SR04
#define trigPin 2 //attach pin A4, J3-3  to pin Trig of HC-SR04
#define buzzPin 5

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Cherryplaza Arduino Training Board"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  if(distance < 100)
  {
    digitalWrite(buzzPin, HIGH);
  }
  else
  {
    digitalWrite(buzzPin, LOW);
  }
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
