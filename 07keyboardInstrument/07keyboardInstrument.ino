//
//  Arduino Starter Kit projects
//
//  Created by Claudio Carnino
//  Copyright © 2015 Tugulab. All rights reserved.
//

enum PinId {
    PinIdKeyboard = A0,
    PinIdSpeaker = 8,
};

enum NoteFrequency { // Frequency in Hz
    NoteFrequencyC = 262,
    NoteFrequencyD = 294,
    NoteFrequencyE = 330,
    NoteFrequencyF = 349,
};


void setup() {
    Serial.begin(9600);
}


/**
Play a note
- param note: Note frequency in Hz (NoteFrequency enum)
*/
void playNote(int note) {
    tone(PinIdSpeaker, note);
}


void loop() {

    const int keyboardValue = analogRead(PinIdKeyboard);
    Serial.println(keyboardValue);

    // Play the riht note, depending on the value read
    if (keyboardValue == 1023) {
        playNote(NoteFrequencyC);

    } else if (keyboardValue >= 990 && keyboardValue <= 1010) {
        playNote(NoteFrequencyD);

    } else if (keyboardValue >= 505 && keyboardValue <= 515) {
        playNote(NoteFrequencyE);

    } else if (keyboardValue >= 5 && keyboardValue <= 10) {
        playNote(NoteFrequencyF);

    } else {
        noTone(PinIdSpeaker);
    }

}
