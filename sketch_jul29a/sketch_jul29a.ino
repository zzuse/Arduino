#include <Stepper.h>
// one lap is 2048 step ~ 360 degree.
int stepsPerRevolution = 2048;
// Speed: 3 laps per minute. 20 seconds per lap.
int motSpeed=3;
int PinIn1=2;
int PinIn2=3;
int PinIn3=4;
int PinIn4=5;
Stepper myStepper(stepsPerRevolution, PinIn1, PinIn3, PinIn2, PinIn4);
int dt=500;

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(stepsPerRevolution);
  delay(dt);
  myStepper.step(-stepsPerRevolution);
  delay(dt);
  // rotate 90 degree, forward and backward
  myStepper.step(stepsPerRevolution/4);
  delay(dt);
  myStepper.step(-(stepsPerRevolution/4));
  delay(dt);
}
