#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    lcd.init();
    lcd.backlight();
}

void loop() {
    lcd.setCursor(2, 0);
    lcd.print("Lab2 KISK-13");
    delay(10);
    lcd.setCursor(0, 1);
    lcd.print("Vitalii Romaniv!");
    delay(10);
}