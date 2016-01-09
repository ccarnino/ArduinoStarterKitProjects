//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdSerialInput = A0,
};


void setup() {
    const int SerialFrequency = 9600;
    Serial.begin(SerialFrequency);
}


void loop() {
    
    // Read the value from the analog input and transform in an acceptable value for transmission
    const int analogValue = analogRead(PinIdSerialInput);
    const int transmissibleValue = map(analogValue, 
                                      0, 1023, 
                                      0, 255);
    
    // Write the value i the serial communication buffer
    Serial.write(transmissibleValue);
    Serial.println(transmissibleValue);
    
    // Let the ADC settle down (??)
    delay(100);
}
