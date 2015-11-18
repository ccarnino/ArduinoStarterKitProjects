#include <Servo.h>


enum PinId {
    PinIdPontentiometerOutput = A0,
    PinIdServoMotorInput = 9,
};

enum PontentiometerOutputValue {
    PontentiometerOutputValueMin = 0,
    PontentiometerOutputValueMax = 1023,
};

enum ServoMotorInputAngle {
    ServoMotorInputAngleMin = 0,
    ServoMotorInputAngleMax = 179,
};

const int loopCycleDelayMilliseconds = 15;

Servo servoMotor;
int potentiometerValue;
int servoMotorAngle;


void setup() {
    
    servoMotor.attach(PinIdServoMotorInput);
    
    Serial.begin(9600);
}


void loop() {
    
    // Reading the potentiomenter value
    potentiometerValue = analogRead(PinIdPontentiometerOutput);
    Serial.print("PontentiometerOutputPin: ");
    Serial.print(potentiometerValue);
    
    // Calculate the servomotor rotation angle
    servoMotorAngle = map(potentiometerValue, 
                          PontentiometerOutputValueMin, PontentiometerOutputValueMax, 
                          ServoMotorInputAngleMin, ServoMotorInputAngleMax);
    Serial.print(", angle: ");
    Serial.println(servoMotorAngle);
    
    // Set the servomotor to the right angle
    servoMotor.write(servoMotorAngle);
    
    delay(loopCycleDelayMilliseconds);
}
