//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

// Pin ids
enum PinId {
    PinIdRedLed1st = 5, 
    PinIdRedLed2nd = 4, 
    PinIdGreenLed = 3, 
    PinIdSwitch = 2,
};

/// Blink delay
int const BlinkDelayMilliseconds = 250;
/// Switch state
int switchState = LOW;


void setup() {
    
    pinMode(PinIdRedLed1st, OUTPUT);
    pinMode(PinIdRedLed2nd, OUTPUT);
    pinMode(PinIdGreenLed, OUTPUT);
    pinMode(PinIdSwitch, INPUT);
}


void loop() {
    
    switchState = digitalRead(PinIdSwitch);
    
    if (switchState == LOW) {
        // Turn on the green led
        digitalWrite(PinIdGreenLed, HIGH);
        digitalWrite(PinIdRedLed1st, LOW);
        digitalWrite(PinIdRedLed2nd, LOW);
    
    } else {
        // Turn off the green led
        digitalWrite(PinIdGreenLed, LOW);
        
        // Make the two red leds flash with a delay
        digitalWrite(PinIdRedLed1st, HIGH);
        digitalWrite(PinIdRedLed2nd, LOW);
        delay(BlinkDelayMilliseconds);
        
        digitalWrite(PinIdRedLed1st, LOW);
        digitalWrite(PinIdRedLed2nd, HIGH);
        delay(BlinkDelayMilliseconds);
    }
    
}
