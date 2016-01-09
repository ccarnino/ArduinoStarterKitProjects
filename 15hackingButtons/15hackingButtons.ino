//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdOptocoupler = 2,
};


void setup() {
    pinMode(PinIdOptocoupler, OUTPUT);
}


void loop() {
    
    // Close the circuit for few millisends
    digitalWrite(PinIdOptocoupler, HIGH);
    delay(100);
    digitalWrite(PinIdOptocoupler, LOW);
    
    // Repeat after a delay
    delay(1000);
}
