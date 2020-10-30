// Import the library
#include <Servo.h>

// Creating the servo object
Servo myServo;

// Variable declaration
int const potPin = A0;
int potVal;
int angle;

void setup() {
  // Associating the servo object with the Arduino pin, initializing the serial port
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // Reading the potentiometer value
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Mapping the potentiometer value to the servo values
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  // Rotating the servo
  myServo.write(angle);
  delay(15);
}
