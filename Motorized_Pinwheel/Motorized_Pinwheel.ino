// Name your constants and variables
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup() {
  // Declare the pins' direction
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  // Read the input, pull the putput high if pressed
  switchState = digitalRead(switchPin);
  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
  }
}
