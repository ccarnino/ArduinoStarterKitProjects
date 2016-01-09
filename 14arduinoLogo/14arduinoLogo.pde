import org.firmata.*;

//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

import processing.serial.*;


// Variables
Serial serialInputPort;
PImage logo;
int backgroundColor = 0;


void setup() {
  // Set the color mode
  colorMode(HSB, 255);
  
  // Load the logo and set the size
  logo = loadImage("https://www.arduino.cc/en/pub/skins/arduinoWide/img/logo.png");
  size(170, 116);
  
  println("Available serial ports: ");
  println(Serial.list());
  
  // Create the serial connection
  int indexSerialPortToReadFrom = 1;
  serialInputPort = new Serial(this, Serial.list()[indexSerialPortToReadFrom], 9600);
}


void draw() {

  // Read the values from the serial port if available
  boolean isSerialInputPortAvailable = serialInputPort.available() > 0;
  if (isSerialInputPortAvailable) {
    backgroundColor = serialInputPort.read();
    println(backgroundColor);
  }
  
  // Set the background color and show the image
  background(backgroundColor, 255, 255);
  image(logo, 0, 0);
}