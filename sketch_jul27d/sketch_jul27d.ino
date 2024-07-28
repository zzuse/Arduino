int LEDState = 0;
int LEDPin = 8;
int buttonPin = 12;
int buttonOld = 1;
int buttonNew = 0;
int dt=100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // The 4-pin push button have two opposite shape legs connected.
  buttonNew = digitalRead(buttonPin);
  if(buttonOld == 0 && buttonNew == 1) {
    if (LEDState == 1) {
      LEDState = 0;
      digitalWrite(LEDPin, LOW);
    } else {
      LEDState = 1;
      digitalWrite(LEDPin, HIGH);
    }
  }
  buttonOld = buttonNew;
  delay(dt);
}
