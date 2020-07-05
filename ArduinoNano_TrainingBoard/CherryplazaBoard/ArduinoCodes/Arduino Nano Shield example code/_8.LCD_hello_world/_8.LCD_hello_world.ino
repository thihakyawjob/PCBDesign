//--- Begin code (copy from here)---
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;// if u don't know the address, first i2c scanner sketch
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
void setup() {
lcd.begin(20,4);
  // put your setup code here, to run once:
  lcd.setCursor(0,0);
  lcd.print("Hello world ");
}
void loop() {
  // put your main code here, to run repeatedly:
 }
//--- End code (copy to here)---

