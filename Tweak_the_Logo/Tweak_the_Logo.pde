// Import and set up the serial object
import processing.serial.*;
Serial myPort;

// Create an object for the image
PImage logo;

// Variable to store the background color
int bgcolor = 0;

void setup() {
  // Setting the color mode
  size(1, 1);
  surface.setResizable(true);
  colorMode(HSB, 255);
  
  // Loading the image
  logo = loadImage("https://www.arduino.cc/en/pub/skins/arduinoWide/img/logo.png");
  surface.setSize(logo.width, logo.height);
  
  // Printing available serial ports
  println("Available serial ports:");
  println(Serial.list());
  
  // Creating the serial object
  myPort = new Serial(this, "COM6", 9600);
}

void draw() {
  // Reading Arduino data from the serial port
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
// Setting the image background and displaying the image
background(bgcolor, 255, 255);
image(logo, 0, 0);
}
