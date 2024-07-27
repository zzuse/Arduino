int buzzPin = 8;
int potPin=A3;
int potVal;
int dt1=1;
int dt2=2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  Serial.println(potVal);
  while(potVal>1000) {
    digitalWrite(buzzPin, HIGH);
    potVal=analogRead(potPin);
    Serial.println(potVal);
  }
  digitalWrite(buzzPin,LOW);

  for (int j = 1; j <= 100; j++) {
    digitalWrite(buzzPin, HIGH);
    delay(dt1);
    digitalWrite(buzzPin, LOW);
    delay(dt1);
  }

  for (int j = 1; j <= 100; j++) {
    digitalWrite(buzzPin, HIGH);
    delay(dt2);
    digitalWrite(buzzPin, LOW);
    delay(dt2);
  }

  delay(5000);

  // HZ to microseconds 1000000/(HZ*2);
  int tone[7] = {261, 293, 329, 349, 392, 440, 493};
  for (int octave = 1; octave < 8; ) {
    if (octave % 2 == 0 || octave == 1) {
      Serial.println(octave);
      for (int dt = 0; dt < 7; dt++) {
        Serial.print("HZ: ");
        Serial.println(tone[dt]*2*octave);
        int dt_time = 1000000/(tone[dt]*2*octave);
        if (octave == 6 && (dt == 0 || dt == 1 || dt == 2)) continue;
        Serial.print("delay in microseconds: ");
        Serial.println(dt_time);
        for (int j = 1; j <= 1000; j++) {
          digitalWrite(buzzPin, HIGH);
          delayMicroseconds(dt_time);
          digitalWrite(buzzPin, LOW);
          delayMicroseconds(dt_time);
        }
      }
    }
    octave ++;
  }

  delay(5000);
}
