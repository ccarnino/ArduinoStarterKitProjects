//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdTiltSwitch = 8,
};

const int LEDsPinIds[] = {2, 3, 4, 5, 6, 7};
const int LEDsPinIdsSize = sizeof(LEDsPinIds) / sizeof(*LEDsPinIds);
const int intervalLEDSwitchEvent = 1000;

unsigned long lastLEDSwitchTime = 0;
int tiltSwitchState = 0;
int previousTiltSwitchState = 0;

// Preselect the index of the first LED to switch on
int indexNextLEDToSwitchOn = 0;


void setup() {
  
    // Set the tilt switch as an input and save initial status
    pinMode(PinIdTiltSwitch, INPUT);
    tiltSwitchState = digitalRead(PinIdTiltSwitch);
    
    // Set the LEDs as output
    for (int pinIndex = 0; pinIndex < LEDsPinIdsSize; pinIndex++) {
        pinMode(LEDsPinIds[pinIndex], OUTPUT);
    }
}


void loop() {
    
    // Calculate how much time is passed since previous led switch event
    const unsigned long currentTime = millis();
    const unsigned long elapsedTimeSinceLastLEDSwitch = currentTime - lastLEDSwitchTime;
    
    const boolean turnOnNextLED = elapsedTimeSinceLastLEDSwitch > intervalLEDSwitchEvent;
    if (turnOnNextLED) {
        
        // Save the LED switch time
        lastLEDSwitchTime = currentTime;
        
        const boolean hasToResetLEDs = indexNextLEDToSwitchOn >= LEDsPinIdsSize;
        if (hasToResetLEDs) {

            // Switch off all the LEDs
            for (int pinIndex = 0; pinIndex < LEDsPinIdsSize; pinIndex++) {
                digitalWrite(LEDsPinIds[pinIndex], LOW);
            }
            
            // Reset the index
            indexNextLEDToSwitchOn = 0;
        }
        
        const boolean canTurnOnNextLED = indexNextLEDToSwitchOn >= 0 && indexNextLEDToSwitchOn < LEDsPinIdsSize;
        if (canTurnOnNextLED) {
            
            // Turn on the LED
            digitalWrite(LEDsPinIds[indexNextLEDToSwitchOn], HIGH);
            // Set the next id of the LED to turn on
            indexNextLEDToSwitchOn++;
        }
    }
    
    // Check if the tilt switch state has changed
    tiltSwitchState = digitalRead(PinIdTiltSwitch);
    const boolean hasTiltSwitchStateChanged = tiltSwitchState != previousTiltSwitchState;
    if (hasTiltSwitchStateChanged) {
        
        // Switch off all the LEDs
        for (int pinIndex = 0; pinIndex < LEDsPinIdsSize; pinIndex++) {
            digitalWrite(LEDsPinIds[pinIndex], LOW);
        }
        
        // Reset the time of last switch event
        lastLEDSwitchTime = currentTime;
        
        // Reset the index of the first LED to turn on
        indexNextLEDToSwitchOn = 0;
        
        // Save the tilt switch state
        previousTiltSwitchState = tiltSwitchState;
    }
}
