// Pin connections
const int soilSensorPin = A0;    // Analog pin for soil sensor
const int relayPin = 2;          // Digital pin for relay control

// Threshold values for moisture levels
const int dryThreshold = 700;    // Adjust this value based on your soil sensor readings
const int wetThreshold = 300;    // Adjust this value based on your soil sensor readings

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);   // Initialize relay pin to LOW (off)
  Serial.begin(9600);            // Initialize serial communication
}

void loop() {
  int moistureLevel = analogRead(soilSensorPin);  // Read the moisture level from the soil sensor
  
  if (moistureLevel >= dryThreshold) {
    // Soil is dry, turn on the pump
    digitalWrite(relayPin, HIGH);
    Serial.println("Pump ON");
  } else if (moistureLevel <= wetThreshold) {
    // Soil is wet enough, turn off the pump
    digitalWrite(relayPin, LOW);
    Serial.println("Pump OFF");
  }
  
  delay(1000);  // Delay for stability, you can adjust this value if needed
}