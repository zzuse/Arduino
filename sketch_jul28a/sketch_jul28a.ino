#include <Servo.h>

int lightVal;
int lightPin = A4;
int servoPin = 9;
int servoPos = 0;
int dt = 250;
Servo myservo;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    // Servo Red for power, brown for ground, orange for control
    pinMode(servoPin, OUTPUT);
    myservo.attach(servoPin);
    pinMode(lightPin, INPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    lightVal = analogRead(lightPin);
    Serial.println(lightVal);
    // liner for angle to lightVal
    servoPos = (-16. / 63.) * lightVal + 16. * 780. / 63.;
    myservo.write(servoPos);

    delay(dt);
}
