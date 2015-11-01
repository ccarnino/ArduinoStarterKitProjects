// Pin ids
enum PinId {
    PinIdRedLed1st = 5, 
    PinIdRedLed2nd = 4, 
    PinIdRedLed3rd = 3, 
    PinIdTemperatureSenson = A0,
};

/// Baseline temperature of the senson
const float baselineTemperature = 18.0;
const float maxVoltage = 5.0;
const int numberValuesTemperatureSensor = 1024;


void setup() {
    
    const int tempSensorBaudPerSec = 9600;
    Serial.begin(tempSensorBaudPerSec);
    
    pinMode(PinIdRedLed1st, OUTPUT);
    pinMode(PinIdRedLed2nd, OUTPUT);
    pinMode(PinIdRedLed3rd, OUTPUT);
}


void loop() {
    
    // Read from the temperature sensor
    const int sensorValue = analogRead(PinIdTemperatureSenson);
    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);
    
    // Calculate the voltage
    const float voltage = (maxVoltage / numberValuesTemperatureSensor) * sensorValue;
    Serial.print(", Volts: ");
    Serial.print(voltage);
    
    // Calculating the temperature in celsius. Here we take a leap of faith with this formula
    // since it's how the sensor datasheet and arduino's starter book suggest to do it.
    const float temperature = (voltage - 0.5) * 100;
    Serial.print(", Celsius: ");
    Serial.println(temperature);
    
    // Set the leds
    const int shouldLight1stLed = temperature > baselineTemperature + 2;
    digitalWrite(PinIdRedLed1st, shouldLight1stLed);
    
    const int shouldLight2ndLed = temperature > baselineTemperature + 4;
    digitalWrite(PinIdRedLed2nd, shouldLight2ndLed);
    
    const int shouldLight3rdLed = temperature > baselineTemperature + 6;
    digitalWrite(PinIdRedLed3rd, shouldLight3rdLed);
    
    delay(1.0);
}
