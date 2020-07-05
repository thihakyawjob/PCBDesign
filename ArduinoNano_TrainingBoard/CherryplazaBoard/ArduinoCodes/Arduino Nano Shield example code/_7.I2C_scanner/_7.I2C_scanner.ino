//--- Begin code (copy from here)---
#include "I2CScanner.h"
I2CScanner scanner;
void setup() 
{
  Serial.begin(9600);
  while (!Serial) {};
  scanner.Init();
}
void loop() 
{
  scanner.Scan();
  delay(5000);
}
//--- End code (copy to here)---

