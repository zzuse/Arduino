const int A1A = 6;
const int A1B = 5;
const int dt = 2000;
int speed = 50;

void setup() {
  // put your setup code here, to run once:
  // L9110 chip for DC motor.
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, HIGH);
  delay(dt);

  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
  delay(dt);

  analogWrite(A1A, 0);
  analogWrite(A1B, speed);
  delay(dt);

  analogWrite(A1A, speed);
  analogWrite(A1B, 0);
  delay(dt);
  
  speed = speed + 50;
  if (speed > 250) speed = 250;
}
