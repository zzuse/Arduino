int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 1000;

byte LED1s = 0xFF;
byte LED2s = 0b01010101;
byte myByte = 0xF0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // 74HC595
  // latchPin LOW to allow update, set data using clockPin to sync, then latchPin HIGH.
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED2s);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  // shift circular
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(latchPin, HIGH);
  myByte = myByte / 128 + myByte * 2;
  delay(dt);
}
