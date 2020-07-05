//--- Begin code (copy from here)---
#include<Stepper.h>
const float STEPS_PER_REV=32;
const float GEAR_RED=64;
const float STEPS_PER_OUT_REV=STEPS_PER_REV*GEAR_RED;
int StepsRequired;
Stepper steppermotor(STEPS_PER_REV,9,11,10,12);
void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  steppermotor.setSpeed(1);
  StepsRequired=4;
  steppermotor.step(StepsRequired);
  delay(2000);

  StepsRequired=STEPS_PER_OUT_REV/2;
  steppermotor.setSpeed(100);
  steppermotor.step(StepsRequired);
  delay(1000);

  StepsRequired=-STEPS_PER_OUT_REV/2;
  steppermotor.setSpeed(700);
  steppermotor.step(StepsRequired);
  delay(2000);
}
//--- End code (copy to here)---

