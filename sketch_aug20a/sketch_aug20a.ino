#include "DHT11.h"

int sensePin =2;
DHT11 HT(sensePin);
int humidity;
int tempC;
int setTime = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  HT.readTemperatureHumidity(tempC, humidity);
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.println(tempC);
  delay(setTime);
}
