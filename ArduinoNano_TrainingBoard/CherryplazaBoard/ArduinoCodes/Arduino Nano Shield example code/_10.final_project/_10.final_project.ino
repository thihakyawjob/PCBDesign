//--- Begin code (copy from here)---
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

#include "DHT.h";
#define DHTpin 7
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);
float hum; //store humidity value in percent
float temp; //store temperature value in Celcius

int buzzerPin = 5;
int LED1 = 6;
int LED2 =7;
int buttonPin = 8;
int relayPin = A7;

int buttonState;
int relayState = HIGH;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;    

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  dht.begin();
  pinMode(buzzerPin,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(buttonPin,INPUT);
  pinMode(relayPin,OUTPUT);

  digitalWrite(relayPin,relayState);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("humidity = ");
  lcd.print(hum);
  lcd.print("%");
  if(temp >= 70){
    digitalWrite(LED1,HIGH);
    tone(buzzerPin,450);
    delay(500);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    noTone(buzzerPin);
    delay(500);
    digitalWrite(LED2,LOW);
  }
  
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        relayState = !relayState;
      }
    }
  }

  // set the LED:
  digitalWrite(relayPin, relayState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  
}//--- End code (copy to here)---


