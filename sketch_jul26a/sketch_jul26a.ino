// PIN ~3 ~5 ~6 ~9 ~10 ~11 have analog out
int greenPin = 9;
int readPin = A3;
int V2 = 0;
float V3 = 0;
int bright = 127;
int delayTime = 500;
int numBlinks;
String msg = "How Many Blinks do you want: ";

void setup()
{
    // put your setup code here, to run once:
    pinMode(greenPin, OUTPUT);
    pinMode(readPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    // Write 255 means most time is 5v
    // Write 0 means most time is 0v
    // Write 127 means half time 5v, half time 0v
    analogWrite(greenPin, bright);
    // Read from 0~1023
    // 0V ~ 0
    // 5V ~ 1023
    // Read after Write 127(half time 5v, half time 0v) ~ ...0,0,0,967,966,967...
    V2 = analogRead(readPin);

    Serial.print("Analog Read: ");
    Serial.println(V2);
    V3 = (5./1023.) * V2;
    Serial.print("Voltage: ");
    Serial.println(V3);
    delay(delayTime);

    Serial.print(msg);
    while(Serial.available() == 0) {
    }
    numBlinks = Serial.parseInt();
    for (int j = 0; j < numBlinks; j++) {
      analogWrite(greenPin, 255);
      delay(delayTime);
      analogWrite(greenPin, 0);
      delay(delayTime);
    }
}
