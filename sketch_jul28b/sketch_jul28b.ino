#include <Servo.h>

int servoPin = 9;
int servoPos = 0;
int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int Xval;
int Yval;
int Sval;
int dt = 200;

Servo myservo;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(servoPin, OUTPUT);
    myservo.attach(servoPin);

    // JoyStick x for analog in A0, y for analog in A1, button for digital input 2
    pinMode(Xpin, INPUT);
    pinMode(Ypin, INPUT);
    pinMode(Spin, INPUT);
    digitalWrite(Spin, HIGH);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Xval = analogRead(Xpin);
    Yval = analogRead(Ypin);
    Sval = digitalRead(Spin);

    Serial.print("X Value = ");
    Serial.print(Xval);
    Serial.print(" Y Value = ");
    Serial.print(Yval);
    Serial.print(" Swich State is ");
    Serial.println(Sval);

    // Joystick 0 - 1023, only control X, since only one dimention for servo
    servoPos = (180. / 1023.) * Xval;
    myservo.write(servoPos);
    delay(dt);
}
