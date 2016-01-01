//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

#include <CapacitiveSensor.h>

// Setup constants
enum PinId {
    PinIdCapacitiveSensorA = 4,
    PinIdCapacitiveSensorB = 2,
    PinIdLed = 12,
};

const int CapacitiveSensorThreshold = 300;
const int CapacitiveSensorNumberOfSamples = 30;

// Setup variables
CapacitiveSensor capacitiveSensor = CapacitiveSensor(PinIdCapacitiveSensorA, PinIdCapacitiveSensorB);


void setup() {
    
    pinMode(PinIdLed, OUTPUT);
    
    const int SerialFrequency = 9600;
    Serial.begin(SerialFrequency);
}


void loop() {

    const long sensorValue = capacitiveSensor.capacitiveSensor(CapacitiveSensorNumberOfSamples);
    Serial.println(sensorValue);
    
    // Turn on/off the led, based on the sensor value
    const boolean sensorValueHigherThanTreshold = sensorValue > CapacitiveSensorThreshold;
    digitalWrite(PinIdLed, sensorValueHigherThanTreshold);
    
    delay(10);
}
