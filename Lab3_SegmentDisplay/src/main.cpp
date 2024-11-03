#include <Arduino.h>

const int PIN_A  = 11;
const int PIN_B  = 7;
const int PIN_C  = 4;
const int PIN_D  = 2;
const int PIN_E  = 1;
const int PIN_F  = 10;
const int PIN_G  = 5;
const int PIN_DP = 3;

const int DIGIT_COUNT = 4;
const int DIGITS[DIGIT_COUNT] = { 12, 9, 8, 6 };

void onDigit(const int digit)
{
    for (int i = 0; i < DIGIT_COUNT; ++i)
    {
        if (i == digit)
            digitalWrite(DIGITS[i], HIGH);
        else
            digitalWrite(DIGITS[i], LOW);
    }
}

void setup() {
    // Set all segments & digits as outputs
    pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
    pinMode(PIN_C, OUTPUT);
    pinMode(PIN_D, OUTPUT);
    pinMode(PIN_E, OUTPUT);
    pinMode(PIN_F, OUTPUT);
    pinMode(PIN_G, OUTPUT);
    pinMode(PIN_DP, OUTPUT);
    pinMode(DIGITS[0], OUTPUT);
    pinMode(DIGITS[1], OUTPUT);
    pinMode(DIGITS[2], OUTPUT);
    pinMode(DIGITS[3], OUTPUT);
}

void showTwo()
{
    digitalWrite(PIN_A, LOW);
    digitalWrite(PIN_B, LOW);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_D, LOW);
    digitalWrite(PIN_E, LOW);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_G, LOW);
}

void showZero()
{
    digitalWrite(PIN_A, LOW);
    digitalWrite(PIN_B, LOW);
    digitalWrite(PIN_C, LOW);
    digitalWrite(PIN_D, LOW);
    digitalWrite(PIN_E, LOW);
    digitalWrite(PIN_F, LOW);
    digitalWrite(PIN_G, HIGH);
}

void showThree()
{
    digitalWrite(PIN_A, LOW);
    digitalWrite(PIN_B, LOW);
    digitalWrite(PIN_C, LOW);
    digitalWrite(PIN_D, LOW);
    digitalWrite(PIN_E, HIGH);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_G, LOW);
}

void loop() {
    // 2
    onDigit(0);
    showTwo();
    delay(1);

    // 0
    onDigit(1);
    showZero();
    delay(1);

    // 0
    onDigit(2);
    showZero();
    delay(1);

    // 0
    onDigit(3);
    showThree();
    delay(1);
}