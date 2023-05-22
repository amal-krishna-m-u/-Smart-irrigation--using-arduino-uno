#include <LiquidCrystal.h>

// Pin connections for LCD
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// Pin connections for moisture sensor and pump
const int sensor_pin = A0;
const int pump_pin = 7;

// Threshold value for moisture level
const int moisture_threshold = 30; // Adjust the threshold value according to your needs

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(pump_pin, OUTPUT);
  digitalWrite(pump_pin, LOW); // Turn off the pump initially

  lcd.begin(16, 2); // Initialize the LCD display
  lcd.print("Smart Irrigation");
  lcd.setCursor(0, 1);
  lcd.print("System");

  Serial.begin(9600);
  Serial.println("Reading from the Moisture sensor...");
  delay(2000);
}

void loop() {
  int output_value = analogRead(sensor_pin);
  output_value = map(output_value, 10, 550, 0, 100);
  Serial.print("Moisture: ");
  Serial.print(output_value);
  Serial.println("%");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(output_value);
  lcd.print("%");

  if (output_value < moisture_threshold) {
    digitalWrite(pump_pin, HIGH); // Turn on the pump
    lcd.setCursor(0, 1);
    lcd.print("Pump: ON");
    delay(1000);
  } else {
    digitalWrite(pump_pin, LOW); // Turn off the pump
    lcd.setCursor(0, 1);
    lcd.print("Pump: OFF");
    delay(1000);
  }

  delay(1000);
}
