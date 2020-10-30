// Create an array of frequencies
int notes[] = {262,294,330,349};

void setup() {
  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value and sent it to the serial monitor
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  // Use an if()...else statement to determine what note to play
  if(keyVal == 1023){
    tone(8, notes[0]);
  }
  
  // Play the notes that correspond to the analog value
  else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }
  
  // Stop playing the tone when nothing is pressed
  else{
    noTone(8);
  }
}
