
int seg_a = 2;
int seg_b = 3;
int seg_c = 4;
int seg_d = 5;
int seg_e = 6;
int seg_f = 7;
int seg_g = 8;
int seg_h = 9;

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
    pinMode(seg_a, OUTPUT);
    pinMode(seg_b, OUTPUT);
    pinMode(seg_c, OUTPUT);
    pinMode(seg_d, OUTPUT);
    pinMode(seg_e, OUTPUT);
    pinMode(seg_f, OUTPUT);
    pinMode(seg_g, OUTPUT);
    pinMode(seg_h, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    unsigned char i;
    for (i = 0; i < 10; i++) {
        digitalWrite(seg_a, table[i][7]);
        digitalWrite(seg_b, table[i][6]);
        digitalWrite(seg_c, table[i][5]);
        digitalWrite(seg_d, table[i][4]);
        digitalWrite(seg_e, table[i][3]);
        digitalWrite(seg_f, table[i][2]);
        digitalWrite(seg_g, table[i][1]);
        digitalWrite(seg_h, table[i][0]);
    }
}
