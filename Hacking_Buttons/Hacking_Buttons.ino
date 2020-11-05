// Name a constant
const int optoPin = 2;

void setup() {
  // Configure the pin direction
  pinMode(optoPin, OUTPUT);
}

void loop() {
  // Pull the pin high and low
  digitalWrite(optoPin, HIGH);
  delay(3000);
  digitalWrite(optoPin, LOW);
  delay(3000);
}
