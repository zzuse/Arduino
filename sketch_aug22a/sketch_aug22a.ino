// MFRC522 1.4.11 https://github.com/miguelbalboa/rfid
#include <MFRC522.h>
#include <SPI.h>
#define RST_PIN 9
#define SS_PIN 10
#define Relay 2
MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
byte nuidPICC[4];

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    while (!Serial)
        ;
    SPI.begin();
    mfrc522.PCD_Init();
    delay(4);
    mfrc522.PCD_DumpVersionToSerial();

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    Serial.println("Scan PICC to see UID, SAK, type, and data blocks...");
    printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    Serial.print("PICC type: ");
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType != MFRC522::PICC_TYPE_MIFARE_1K
        && piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        Serial.println("Your tag is not of type MIFARE Classic.");
        return;
    }

    if (mfrc522.uid.uidByte[0] != nuidPICC[0] || mfrc522.uid.uidByte[1] != nuidPICC[1] || mfrc522.uid.uidByte[2] != nuidPICC[2]
        || mfrc522.uid.uidByte[3] != nuidPICC[3]) {
        Serial.println("A new card has been detected.");

        for (byte i = 0; i < 4; i++) {
            nuidPICC[i] = mfrc522.uid.uidByte[i];
        }

        Serial.println("The NUID tag is: ");
        Serial.print("In hex: ");
        printHex(mfrc522.uid.uidByte, mfrc522.uid.size);
        Serial.println();
        Serial.print("In dec: ");
        printDec(mfrc522.uid.uidByte, mfrc522.uid.size);
        Serial.println();
    } else {
        Serial.println("Card read previously.");
        digitalWrite(Relay,HIGH);
        Serial.println("The Host 1!");
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(' ');
    Serial.print(buffer[i], DEC);
  }
}