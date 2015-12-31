//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

#include <Servo.h>

// Setup constants
enum PinId {
    PinIdPiezo = A0,
    PinIdSwitch = 2,
    PinIdLedYellow = 3,
    PinIdLedGreen = 4,
    PinIdLedRed = 5,
    PinIdServoMotor = 9,
};

enum KnockReferenceValue {
    KnockReferenceValueQuiet = 10,
    KnockReferenceValueLoud= 100,
};

enum ServoMotorState {
    ServoMotorStateUnlocked = 0,
    ServoMotorStateLocked = 90,
};

const int NumberOfKnocksNeededToUnlock = 3;

// Setup variables
boolean locked = false;
int numberOfKnocks = 0;
Servo servoMotor;


void setup() {
    
    pinMode(PinIdLedYellow, OUTPUT);
    pinMode(PinIdLedGreen, OUTPUT);
    pinMode(PinIdLedRed, OUTPUT);
    pinMode(PinIdSwitch, INPUT);
    
    const int SerialFrequency = 9600;
    Serial.begin(SerialFrequency);
    
    digitalWrite(PinIdLedGreen, HIGH);
    servoMotor.attach(PinIdServoMotor);
    servoMotor.write(ServoMotorStateUnlocked);
    Serial.println("The box is unlocked!");
}

/// Is the knock value valid?
boolean isKnockValueValid(int value) {
    // Valid value
    if (value >= KnockReferenceValueQuiet && value < KnockReferenceValueLoud) {
        
        digitalWrite(PinIdLedYellow, HIGH);
        delay(50);
        digitalWrite(PinIdLedYellow, LOW);
        
        Serial.print("Valid knock of value ");
        Serial.println(value);
        
        return true;
    }
    
    // Invalid value
    Serial.print("Invalid knock of value ");
    Serial.println(value);

    return false;
}


void loop() {

    if (locked) {
        // It's locked. Check the knocks to unlock it
        const int knockValue = analogRead(PinIdPiezo);
        const boolean hasKnocked = knockValue > 0;
        boolean hasEnoughKnocks = numberOfKnocks >= NumberOfKnocksNeededToUnlock;
        
        if (hasKnocked && !hasEnoughKnocks) {
            if (isKnockValueValid(knockValue)) {
                numberOfKnocks++;
            }
            Serial.print(3 - numberOfKnocks);
            Serial.println(" more knocks to go");
        }
        
        hasEnoughKnocks = numberOfKnocks >= NumberOfKnocksNeededToUnlock;
        if (hasEnoughKnocks) {
            // Unlock
            locked = false;

            digitalWrite(PinIdLedGreen, HIGH);
            digitalWrite(PinIdLedRed, LOW);

            servoMotor.write(ServoMotorStateUnlocked);
            Serial.println("The box is locked!");

            delay(20);
        }
        
        return;
    }
    
    
    // It's unlocked. Check the switch to lock it
    const int switchValue = digitalRead(PinIdSwitch);
    if (switchValue == HIGH) {
        // Lock
        locked = true;
        numberOfKnocks = 0;

        digitalWrite(PinIdLedGreen, LOW);
        digitalWrite(PinIdLedRed, HIGH);

        servoMotor.write(ServoMotorStateLocked);
        Serial.println("The box is locked!");

        delay(1000);
    }
}
