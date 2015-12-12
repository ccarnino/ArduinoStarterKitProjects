//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdSwitch = 2,
    PinIdMotor = 9,
};


void setup() {
    pinMode(PinIdSwitch, INPUT);
    pinMode(PinIdMotor, OUTPUT);
}


void loop() {
    // Turn on/off the motor reflecting the state of the switch
    const boolean switchState = digitalRead(PinIdSwitch);
    digitalWrite(PinIdMotor, switchState);
}
