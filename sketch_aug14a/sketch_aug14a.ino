
int seg_a = A2;
int seg_b = A3;
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

int trigPin = 2;
int echoPin = 3;
unsigned long pingTravelTime;
unsigned long bucketTravelTime = 0;
int numMea = 0;
float ave_new = 0;
float ave_old = 0;

int showNum = 0;

int buttonAddPin = A0;
int buttonAddOld = 1;
int buttonAddNew = 0;

int buttonSubPin = A1;
int buttonSubOld = 1;
int buttonSubNew = 0;

int ToggleSwitch = A4;
int SwitchOld = 1;
int SwitchNew = 0;
int toggleFlag = 0;

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

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // run out of digital pin using analog in instead, need output HIGH.
    pinMode(buttonAddPin, OUTPUT);
    digitalWrite(buttonAddPin, HIGH);
    pinMode(buttonSubPin, OUTPUT);
    digitalWrite(buttonSubPin, HIGH);
    pinMode(ToggleSwitch, OUTPUT);
    digitalWrite(ToggleSwitch, HIGH);
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
}

int scanDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pingTravelTime = pulseIn(echoPin, HIGH);
    bucketTravelTime += pingTravelTime;
    delay(20);
}

int scanButton()
{
    buttonAddNew = digitalRead(buttonAddPin);
    if (buttonAddOld == 0 && buttonAddNew == 1) {
        showNum++;
        if (showNum > 9999) showNum = 9999;
    }
    buttonAddOld = buttonAddNew;
    buttonSubNew = digitalRead(buttonSubPin);
    if (buttonSubOld == 0 && buttonSubNew == 1) {
        showNum--;
        if (showNum < 0) showNum = 0;
    }
    buttonSubOld = buttonSubNew;
    SwitchNew = digitalRead(ToggleSwitch);
    if (SwitchOld == 0 && SwitchNew == 1) {
        toggleFlag = ~toggleFlag;
    }
    SwitchOld = SwitchNew;
}

void toggleLED(int num)
{
    Display(1, num / 1000);
    delay(3);

    Display(2, num % 1000 / 100);
    delay(3);

    Display(3, num % 100 / 10);
    delay(3);

    Display(4, num % 10);
    delay(3);
}

void toggleSensor()
{
    scanDistance();
    scanButton();
}

void loop()
{
    if (toggleFlag == 0) {
        toggleLED(showNum);
    } else {
        toggleLED(ave_old);
    }
    toggleSensor();
    numMea++;
    if (numMea % 100 == 0) {
        ave_new = bucketTravelTime * 17 / 1000 / 100;
        // Serial.println(ave_new);
        bucketTravelTime = 0;
    }
    if (ave_new < 100 && ave_old > 200) {
        // buzz
        showNum++;
    }
    ave_old = ave_new;
    delay(20);
}
