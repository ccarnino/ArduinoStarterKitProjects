//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

// Pin ids
enum LedPinId {
    LedPinIdRed = 11, 
    LedPinIdGreen = 10, 
    LedPinIdBlue = 9, 
};

// Pin ids
enum SensorPinId {
    SensorPinIdRed = A0, 
    SensorPinIdGreen = A1, 
    SensorPinIdBlue = A2, 
};


// Outut color values
int outputRedValue = 0;
int outputGreenValue = 0;
int outputBlueValue = 0;

// Input color values
int sensorRedValue = 0;
int sensorGreenValue = 0;
int sensorBlueValue = 0;


void setup() {
    
    const int sensorBaudPerSec = 9600;
    Serial.begin(sensorBaudPerSec);
    
    pinMode(LedPinIdRed, OUTPUT);
    pinMode(LedPinIdGreen, OUTPUT);
    pinMode(LedPinIdBlue, OUTPUT);
}


void loop() {
    
    // Read from the light sensors
    sensorRedValue = analogRead(SensorPinIdRed);
    delay(5);
    sensorGreenValue = analogRead(SensorPinIdGreen);
    delay(5);
    sensorBlueValue = analogRead(SensorPinIdBlue);
    
    // Convert the input sensor value on base (max 1024) to output compatible value (max 255)
    outputRedValue = sensorRedValue / 4;
    outputGreenValue = sensorGreenValue / 4;
    outputBlueValue = sensorBlueValue / 4;
    
    // Set PWM value for changing the led color
    analogWrite(LedPinIdRed, outputRedValue);
    analogWrite(LedPinIdGreen, outputRedValue);
    analogWrite(LedPinIdBlue, outputRedValue);
    
    // Logging
    Serial.print("INPUT: ");
    Serial.print("Red: ");
    Serial.print(sensorRedValue);
    Serial.print(", Green: ");
    Serial.print(sensorGreenValue);
    Serial.print(", Blue: ");
    Serial.print(sensorBlueValue);
    Serial.print(" # ");
    Serial.print("OUTPUT: ");
    Serial.print("Red: ");
    Serial.print(outputRedValue);
    Serial.print(", Green: ");
    Serial.print(outputGreenValue);
    Serial.print(", Blue: ");
    Serial.print(outputBlueValue);
    Serial.println("\n");
}
