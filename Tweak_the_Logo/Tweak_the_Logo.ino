void setup() {
  // Open a serial connection
  Serial.begin(9600);
}

void loop() {
  // Send the sensor value
  Serial.write(analogRead(A0)/4);

  // Let the ADC stabilize
  delay(100);
}
