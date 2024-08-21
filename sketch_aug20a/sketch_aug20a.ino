#include "DHT11.h"
#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs,en,d4,d5, d6, d7);

int sensePin = 2;
// using DHT11 V2.1.0 library
DHT11 HT(sensePin);
int humidity;
int tempC;
int setTime = 500;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    lcd.begin(16,2);
}

void loop()
{
    // put your main code here, to run repeatedly:
    HT.readTemperatureHumidity(tempC, humidity);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.println("%   ");
    lcd.setCursor(0, 1);
    lcd.print("Temperature: ");
    lcd.print(tempC);
    lcd.println("C");
    delay(setTime);
}
