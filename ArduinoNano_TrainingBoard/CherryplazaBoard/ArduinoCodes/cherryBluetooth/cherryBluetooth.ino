/*
  HC05 - Bluetooth

  modified 19 July 2020
  by THIHA KYAW

  This example code is for Cherryplaza Arduino Training Board
*/
#include <SoftwareSerial.h> 
SoftwareSerial cherryBluetooth(3, 2); // RX | TX 
int flag = 0; 
int LED1 = 6;
int LED2 = 7;  
void setup() 
{   
  Serial.begin(9600); 
  cherryBluetooth.begin(9600); 
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH); 
  Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
  if (cherryBluetooth.available()) 
    flag = cherryBluetooth.read(); 
  if (flag == 1) 
  { 
    digitalWrite(LED1, LOW); 
    Serial.println("LED1 On"); 
  }
  else  if (flag == 2) 
  { 
    digitalWrite(LED2, LOW); 
    Serial.println("LED2 On"); 
  } 
  else if (flag == 0) 
  { 
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);  
    Serial.println("LED Off"); 
  } 
} 
