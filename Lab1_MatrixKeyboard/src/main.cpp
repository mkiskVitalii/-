#include <Arduino.h>
#include <Keypad.h>
#include <ArduinoSTL.h>
#include <map>
#include <string>

const byte ROWS = 4;
const byte COLS = 4;

const char hexKeys[ROWS][COLS] = {
    {'0', '1', '2', '3'},
    {'4', '5', '6', '7'},
    {'8', '9', 'A', 'B'},
    {'C', 'D', 'E', 'F'}
};

byte rowPins[ROWS] = { 7, 8, 9, 10 };
byte colPins[COLS] = { 6, 5, 4, 3 };

std::map<char, std::string> displayedKeys = {
    {'0', "S1"},
    {'1', "S2"},
    {'2', "S3"},
    {'3', "S4"},
    {'4', "S5"},
    {'5', "S6"},
    {'6', "S7"},
    {'7', "S8"},
    {'8', "S9"},
    {'9', "S10"},
    {'A', "S11"},
    {'B', "S12"},
    {'C', "S13"},
    {'D', "S14"},
    {'E', "S15"},
    {'F', "S16"}
};

const char* translateKeyToDisplay(const char key);
Keypad customKeypad = Keypad(makeKeymap(hexKeys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600);
}

void loop() {
    char keyPressed = customKeypad.getKey();
    if (keyPressed)
    {
        std::string tmp = displayedKeys[keyPressed];
        Serial.println(tmp.c_str());
    }
}
