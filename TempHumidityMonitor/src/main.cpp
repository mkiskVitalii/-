#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

#define DHTPIN            A3
#define DHTTYPE           DHT11
#define I2C_LCD_ADDRESS   0x27
#define LCD_COL_COUNT     16
#define LCD_ROW_COUNT     2
#define SERIAL_BOUND_RATE 9600
#define RED_PIN           8
#define GREEN_PIN         9
#define BLUE_PIN          10
#define SERVO_PIN         13
#define MAX_HUMIDITY      60
#define MAX_TEMPERATURE   50

struct MonitoringDevice {
    MonitoringDevice();
    bool getData(const DHT &);

    float humidity;
    float temperature;
};

MonitoringDevice::MonitoringDevice() :
                      humidity(0), temperature(0)
{
}

bool MonitoringDevice::getData(const DHT &d)
{
    humidity = d.readHumidity();
    temperature = d.readTemperature();

    if (humidity > MAX_HUMIDITY)
      return false;
    else if (temperature > MAX_TEMPERATURE)
      return false;

    return true;
}

LiquidCrystal_I2C lcd(I2C_LCD_ADDRESS,
                    LCD_COL_COUNT, LCD_ROW_COUNT);
DHT dht(DHTPIN, DHTTYPE);
MonitoringDevice md;
Servo myServo;
int myServoPosition = 0;
bool servoEnable = false;

void setup() {
    Serial.begin(SERIAL_BOUND_RATE);
    Serial.println("Temperature and Humidity Sensor Test");
    dht.begin();
    lcd.init();
    lcd.backlight();
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    myServo.attach(SERVO_PIN);
}

void turnOnServo()
{
    if (servoEnable)
      return;
    myServo.write(180);
    servoEnable = true;
}

void turnOffServo()
{
    if (servoEnable)
      myServo.write(0);
    servoEnable = false;
}


void loop() {
    if (md.getData(dht)) {
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, HIGH);
        turnOffServo();
    } else {
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(RED_PIN, HIGH);
        turnOnServo();
    }


    Serial.print("Humidity: ");
    Serial.print((int)md.humidity);
    Serial.print(" %, Temp: ");
    Serial.print((int)md.temperature);
    Serial.println(" ° Celsius");

    lcd.setCursor(1, 0);
    lcd.print("T/H  monitoring");
    lcd.setCursor(2, 1);
    lcd.print("T:");
    lcd.print((int)md.temperature);
    lcd.print("C");
    lcd.setCursor(10, 1);
    lcd.print("H:");
    lcd.print((int)md.humidity);
    lcd.print("%");
    delay(1000);
}
