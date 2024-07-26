int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin9 = 9;
int waitTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin9, HIGH);
  delay(waitTime);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin9, LOW);
  delay(waitTime);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin9, LOW);
  delay(waitTime);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  digitalWrite(pin9, LOW);
  delay(waitTime);

  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin9, LOW);
  delay(waitTime);
}
