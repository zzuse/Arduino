
int seg_a = 2;
int seg_b = 3;
int seg_c = 4;
int seg_d = 5;
int seg_e = 6;
int seg_f = 7;
int seg_g = 8;
int seg_h = 9;

#define COM1 10
#define COM2 11
#define COM3 12
#define COM4 13

int buttonPin = 0;
int hourNum = 0;
int minuteNum = 0;
int buttonOld = 1;
int buttonNew = 0;

unsigned char table[10][8] = {{0, 0, 1, 1, 1, 1, 1, 1},  // 0
                              {0, 0, 0, 0, 0, 1, 1, 0},  // 1
                              {0, 1, 0, 1, 1, 0, 1, 1},  // 2
                              {0, 1, 0, 0, 1, 1, 1, 1},  // 3
                              {0, 1, 1, 0, 0, 1, 1, 0},  // 4
                              {0, 1, 1, 0, 1, 1, 0, 1},  // 5
                              {0, 1, 1, 1, 1, 1, 0, 1},  // 6
                              {0, 0, 0, 0, 0, 1, 1, 1},  // 7
                              {0, 1, 1, 1, 1, 1, 1, 1},  // 8
                              {0, 1, 1, 0, 1, 1, 1, 1}}; // 9
void setup()
{
    // put your setup code here, to run once:
    // Serial.begin(9600);
    pinMode(seg_a, OUTPUT);
    pinMode(seg_b, OUTPUT);
    pinMode(seg_c, OUTPUT);
    pinMode(seg_d, OUTPUT);
    pinMode(seg_e, OUTPUT);
    pinMode(seg_f, OUTPUT);
    pinMode(seg_g, OUTPUT);
    pinMode(seg_h, OUTPUT);

    pinMode(COM1, OUTPUT);
    pinMode(COM2, OUTPUT);
    pinMode(COM3, OUTPUT);
    pinMode(COM4, OUTPUT);

    pinMode(buttonPin, INPUT);
}

void Display(unsigned char com, unsigned char num)
{
    digitalWrite(seg_a, LOW);
    digitalWrite(seg_b, LOW);
    digitalWrite(seg_c, LOW);
    digitalWrite(seg_d, LOW);
    digitalWrite(seg_e, LOW);
    digitalWrite(seg_f, LOW);
    digitalWrite(seg_g, LOW);
    digitalWrite(seg_h, LOW);

    switch (com) {
        case 1:
            digitalWrite(COM1, LOW);
            digitalWrite(COM2, HIGH);
            digitalWrite(COM3, HIGH);
            digitalWrite(COM4, HIGH);
            break;
        case 2:
            digitalWrite(COM1, HIGH);
            digitalWrite(COM2, LOW);
            digitalWrite(COM3, HIGH);
            digitalWrite(COM4, HIGH);
            break;
        case 3:
            digitalWrite(COM1, HIGH);
            digitalWrite(COM2, HIGH);
            digitalWrite(COM3, LOW);
            digitalWrite(COM4, HIGH);
            break;
        case 4:
            digitalWrite(COM1, HIGH);
            digitalWrite(COM2, HIGH);
            digitalWrite(COM3, HIGH);
            digitalWrite(COM4, LOW);
            break;
        default:
            break;
    }

    int i = num;
    digitalWrite(seg_a, table[i][7]);
    digitalWrite(seg_b, table[i][6]);
    digitalWrite(seg_c, table[i][5]);
    digitalWrite(seg_d, table[i][4]);
    digitalWrite(seg_e, table[i][3]);
    digitalWrite(seg_f, table[i][2]);
    digitalWrite(seg_g, table[i][1]);
    digitalWrite(seg_h, table[i][0]);
    if (com == 2) {
        // a blinking dot, millis() Returns the number of milliseconds passed since
        //  the Arduino board began running the current program
        digitalWrite(seg_h, millis() / 1000 % 2 ? HIGH : LOW);
    }
}

int scanButton()
{
    buttonNew = digitalRead(buttonPin);
    // Serial.println(millis());
    // button always HIGH, only LOW when push it.
    // only catch LOW to HIGH, means only catch release it.
    if (buttonOld == 0 && buttonNew == 1) {
        hourNum = hourNum + 100;
        if (hourNum > 2300) hourNum = 0;
    }
    buttonOld = buttonNew;
    minuteNum = millis() / 60000 % 60;
    // 59 min and 59 seconcds will plus one hour
    if (minuteNum == 59 && millis() / 1000 % 60 == 59) {
        delay(1000);
        hourNum = hourNum + 100;
        if (hourNum > 2300) hourNum = 0;
    }
    delay(5);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Display(1, hourNum / 1000);
    delay(3);

    Display(2, hourNum % 1000 / 100);
    delay(3);

    Display(3, minuteNum % 100 / 10);
    delay(3);

    Display(4, minuteNum % 10);
    delay(3);

    scanButton();
}
