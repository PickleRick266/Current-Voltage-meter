#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Analogue input pins
const int voltagePin = A0;
const int shuntPin = A1;

// Resistor value for current calculation
const float shuntResistor = 100.0; // ohms

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("V/I Meter");
}

void loop() {
  int voltageReading = analogRead(voltagePin);
  int shuntReading = analogRead(shuntPin);

  float inputVoltage = voltageReading * (5.0 / 1023.0);
  float shuntVoltage = shuntReading * (5.0 / 1023.0);

  float currentAmps = shuntVoltage / shuntResistor;
  float currentMilliAmps = currentAmps * 1000.0;

  lcd.setCursor(0, 0);
  lcd.print("V: ");
  lcd.print(inputVoltage, 2);
  lcd.print(" V      ");

  lcd.setCursor(0, 1);
  lcd.print("I: ");
  lcd.print(currentMilliAmps, 1);
  lcd.print(" mA     ");
}