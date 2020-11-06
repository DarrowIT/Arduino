// Servo library
#include <Servo.h>
Servo myServo;

// Useful constants
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

// Variables to hold switch and piezo values
int knockVal;
int switchVal;

// Knock thresholds
const int quietKnock = 90;
const int loudKnock = 5500;

// Variables for lock state and number of knocks
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // Setting the direction of the digital pins and initializing servo object and serial port
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);

  // Unlock
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  // Checking the switch
  if(locked == false) {
    switchVal = digitalRead(switchPin);
    
    // Lock
    if(switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }

  // Checking the knock sensor
  if(locked == true) {
    knockVal = analogRead(piezo);
    
    // Counting only valid knocks
    if(numberOfKnocks < 3 && knockVal > 0) {
      if(checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    // Unlock
    if(numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
      delay(2000);
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnock(int value){
  // Check validity of knock
  if(value > quietKnock && value < loudKnock) {
    // Indicating knock is valid
    digitalWrite(yellowLed, HIGH);
    delay(250);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);

    // Function returns true
    return true;
  }
  
  // Indicating invalid knock; function returns false
  else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
