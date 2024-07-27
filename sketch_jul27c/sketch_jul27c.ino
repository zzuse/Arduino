int buzzPin = 8;
int lightPen=A0;
int lightVal;
int dv=250;
int redPin=9;
int greenPin=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightPen);
  Serial.println(lightVal);
  delay(dv);
  if (lightVal > 550) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW); 
  }
}
