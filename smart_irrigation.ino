// Smart Irrigation System

int sensor_pin = A0;
int output_value;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading from the Moisture sensor...");
  delay(2000);
}

void loop() {
  output_value = analogRead(sensor_pin);
  output_value = map(output_value, 10, 550, 0, 100);
  Serial.print("Moisture: ");
  Serial.print(output_value);
  Serial.println("%");

  if (output_value < 30) { // Adjust the threshold value according to your needs
    digitalWrite(3, HIGH); // Turn on the pump
    delay(1000);
  } else {
    digitalWrite(3, LOW);  // Turn off the pump
    delay(1000);
  }
  
  delay(1000);
}