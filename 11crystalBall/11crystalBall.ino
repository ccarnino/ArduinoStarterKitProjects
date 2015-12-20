//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

enum PinId {
    PinIdSwitch = 6,
};


int switchState = 0;
int previousSwitchState = 0;
int replyIndex;


void setup() {
    
    lcd.begin(16, 2);
    pinMode(PinIdSwitch, INPUT);
    
    // Write to the 1st line
    lcd.print("Ask the");
    
    // Write to the 2nd line
    lcd.setCursor(0, 1);
    lcd.print("Crystal ball!");
}


void loop() {
    
    switchState = digitalRead(PinIdSwitch);
    
    // If the state has changed and is low again
    const boolean isStateChanged = switchState != previousSwitchState;
    const boolean isStateLow = switchState == LOW;
    if (isStateChanged && isStateLow) {
        
        // Choose a random reply
        replyIndex = random(8);
        
        // Reset the display
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("The ball says:");
        lcd.setCursor(0, 1);
        
        switch (replyIndex) {
            case 0:
            lcd.print("Yes");
            break;
            
            case 1:
            lcd.print("Most likely");
            break;
            
            case 2:
            lcd.print("Certainly");
            break;
            
            case 3:
            lcd.print("Outlook good");
            break;
            
            case 4:
            lcd.print("Unsure");
            break;
            
            case 5:
            lcd.print("Ask again");
            break;
            
            case 6:
            lcd.print("Doubtful");
            break;
            
            default:
            lcd.print("No");
            break;
        }
    }
    
    // Save the state
    previousSwitchState = switchState;
}
