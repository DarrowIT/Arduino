int switchState = 0;

// Configure pin functionality
void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}

// Create the loop function
void loop(){
switchState = digitalRead(2);

  if (switchState == LOW) {
  // the button is not pressed
    digitalWrite(3, HIGH); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, LOW); // red LED
  }
  
  else {
    // the button is pressed
    digitalWrite(3, LOW); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, HIGH); // red LED
    delay(250); // wait for a quarter second
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250); // wait for a quarter second
  }
} // go back to the beginning of the loop
