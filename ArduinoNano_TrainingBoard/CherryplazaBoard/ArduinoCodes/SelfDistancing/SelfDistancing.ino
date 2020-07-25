/*
  Arduino Ultrasoninc Sensor HC-SR04

  modified 19 July 2020
  by THIHA KYAW

  This example code is for Cherryplaza Arduino Training Board
*/
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

//Color setting for LCD
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;



#define echoPin 3 // attach pin D3, J3-4  to pin Echo of HC-SR04
#define trigPin 2 //attach pin D2, J3-3  to pin Trig of HC-SR04
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

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.setRGB(colorR, colorG, colorB);
  
  // Print a message to the LCD.
  lcd.print("Cherryplaza");
  delay(2000); //2 sec to display

  lcd.setRGB(50, 205, 50);

  lcd.setCursor(0, 0);

  lcd.print("Start Measuring");

  
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

  //Show Distance in line 2
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Distance:"); 
  
  lcd.setCursor(10, 1);
  lcd.print(distance);
  lcd.print("cm");

  if(distance < 100)
  {
    digitalWrite(buzzPin, HIGH);
    lcd.setRGB(colorR, colorG, colorB);
  }
  else
  {
    digitalWrite(buzzPin, LOW);
     lcd.setRGB(50, 205, 50);
  }
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); //1 sec to display
}
