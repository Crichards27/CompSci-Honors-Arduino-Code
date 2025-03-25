const int sensorPin = A0;  
const int ledPin = 10;     

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);  
}

void loop() {
    int lightAmount = analogRead(sensorPin);  
    Serial.println(lightAmount);  

    // Map light amount (assuming values range from 0 to 1023)
    int ledBrightness = map(lightAmount, 1023, 0, 0, 255);

    analogWrite(ledPin, ledBrightness);  
    delay(50);  
}
