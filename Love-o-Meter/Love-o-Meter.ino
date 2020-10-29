// A pair of useful constants
const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup(){
  // Open a serial port and initialize to the desired speed
  Serial.begin(9600);

  // Initialize the digital pin directions and turn off
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    }
}

void loop() {
  // Read the temperature sensor
  int sensorVal = analogRead(sensorPin);

  // Read the temperature sensor values to the computer
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Convert the sensor reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // Convert the voltage to temperature and send the value to the computer
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  // Turn off LEDs for a low temperature
  if(temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }

  // Turn on one LED for low-mid temperature  
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }

  // Turn on two LEDs for mid-high temperature 
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    }

  // Turn on three LEDs for a high temperature  
  else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    }
  delay(1);
}
