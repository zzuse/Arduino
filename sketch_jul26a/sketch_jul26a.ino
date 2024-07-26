int greenPin = 9;
int bright = 127;
void setup()
{
    // put your setup code here, to run once:
    pinMode(greenPin, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    // 255 means most time is 5v
    // 5 means most time is 0v
    // 127 means half time 5v, half time 0v
    analogWrite(greenPin, bright);
}
