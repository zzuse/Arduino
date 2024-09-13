#include <IRremote.h>
// IRremote 4.4.1
// https://github.com/Arduino-IRremote/Arduino-IRremote
int IR_RECEIVE_PIN = 2;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
    // put your main code here, to run repeatedly:
    while (IrReceiver.decode() == 0) {
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    delay(1500);
    IrReceiver.resume();
}
