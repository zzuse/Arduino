int redPin = 10;
int greenPin = 9;
int bluePin = 6;
String myColor;
String msg="What Colour Do You Want?";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() > 0) {
      Serial.read();
  }
  while(Serial.available()==0) {}
  myColor = Serial.readString();
  Serial.print("Your color is: ");
  Serial.println(myColor);

  if (myColor.startsWith("red")) {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
  }
  if (myColor.startsWith("green")) {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
  }
  if (myColor.startsWith("blue")) {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
  }
  if (myColor.startsWith("aqua")) {
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
    analogWrite(bluePin,80);
  }
  if (myColor.startsWith("cyan")) {
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
    analogWrite(bluePin,255);
  }
  if (myColor.startsWith("magenta")) {
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
  }
  if (myColor.startsWith("yellow")) {
    analogWrite(redPin,255);
    analogWrite(greenPin,255);
    analogWrite(bluePin,0);
  }
  if (myColor.startsWith("orange")) {
    analogWrite(redPin,255);
    analogWrite(greenPin,165);
    analogWrite(bluePin,0);
  }
  if (myColor.startsWith("fuchsia")) {
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
  }
  if (myColor.startsWith("mystery")) {
    float red = float(random())/RANDOM_MAX * 255;
    float green = float(random())/RANDOM_MAX * 255;
    float blue = float(random())/RANDOM_MAX * 255;

    analogWrite(redPin,red);
    analogWrite(greenPin,green);
    analogWrite(bluePin,blue);
  }
}
