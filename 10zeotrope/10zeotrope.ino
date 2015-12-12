//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdControlA = 2,
    PinIdControlB = 3,
    PinIdEnable = 9,
    PinIdDirectionSwitch = 4,
    PinIdOnOffSwitch = 5,
    PinIdPot = A0,
};

// Set the initial state
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

boolean motorEnabled = 0;
boolean motorDirection = 1;
int motorSpeed = 0;


void setup() {
    pinMode(PinIdDirectionSwitch, INPUT);
    pinMode(PinIdOnOffSwitch, INPUT);
    pinMode(PinIdControlA, OUTPUT);
    pinMode(PinIdControlB, OUTPUT);
    pinMode(PinIdEnable, OUTPUT);
    
    digitalWrite(PinIdEnable, LOW);
}


void loop() {
    
    onOffSwitchState = digitalRead(PinIdOnOffSwitch);
    delay(1); // Why the delay???
    
    directionSwitchState = digitalRead(PinIdDirectionSwitch);
    motorSpeed = analogRead(PinIdPot) / 4;
    
    // Update the Enable-the-motor state
    const boolean onOffStateHasChanged = onOffSwitchState != previousOnOffSwitchState;
    if (onOffStateHasChanged && onOffSwitchState) {
        motorEnabled = !motorEnabled;
    }
    
    // Update the Direction-switch-state
    const boolean directionStateHasChanged = directionSwitchState != previousDirectionSwitchState;
    if (directionStateHasChanged && directionSwitchState) {
        motorDirection = !motorDirection;
    }
    
    // Set the direction in the IC
    digitalWrite(PinIdControlA, motorDirection);
    digitalWrite(PinIdControlB, !motorDirection);
    
    // Enable the motor and set the speed
    digitalWrite(PinIdEnable, motorEnabled ? motorSpeed : 0);
    
    // Set the current states
    previousOnOffSwitchState = onOffSwitchState;
    previousDirectionSwitchState = directionSwitchState;
}
