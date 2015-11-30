//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdLed = 13,
    PinIdPhotoresistor = A0,
    PinIdSpeaker = 8,
};

enum PitchFrequency {
    PitchFrequencyLow = 50,
    PitchFrequencyHigh = 4000,
};

// Min/max that the photoresistor can read
int photoresistorMinValue;
int photoresistorMaxValue;


void setup() {
    
    pinMode(PinIdLed, OUTPUT);
    
    // Calibrate the photoresistor, while turning the led on
    digitalWrite(PinIdLed, HIGH);
    calibratePhotoresistor(&photoresistorMinValue, &photoresistorMaxValue);
    digitalWrite(PinIdLed, LOW);
}


/**
Calibrate the photoresistor bounds
param int minValue Minimum value to set
param int maxValue Maximum value to set
*/
void calibratePhotoresistor(int *minValue, int *maxValue) {
    
    // Set the min/max photoresistor bounds to their opposive value. 
    *minValue = 1023;
    *maxValue = 0;
    
    // Calibrate for a period of time 
    const int calibrationPeriodMs = 5000;
    while (millis() < calibrationPeriodMs) {
        
        const int photoresistorValue = analogRead(PinIdPhotoresistor);
        
        if (photoresistorValue > *maxValue) {
            *maxValue = photoresistorValue;
        }
        if (photoresistorValue < *minValue) {
            *minValue = photoresistorValue;
        }
    }
}


void loop() {
    
    // Catch the light and translate it in an appropriate pitch
    const int photoresistorValue = analogRead(PinIdPhotoresistor);
    const int audioPitch = map(photoresistorValue, 
                               photoresistorMinValue, photoresistorMaxValue,
                               PitchFrequencyLow, PitchFrequencyHigh);
    // Play the frequency
    tone(PinIdSpeaker, audioPitch, 20);
    
    delay(10);
}
