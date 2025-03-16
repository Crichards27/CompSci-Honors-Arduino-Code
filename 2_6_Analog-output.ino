const int ledPin = 9;      
const int buttonPin = 7;   
int brightness = 255;      
int count = 0;             

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);  
    Serial.begin(9600);               
}

void loop() {
    if (digitalRead(buttonPin) == LOW) {  
        count++;  // Increase count
        Serial.print("Button pressed! Count: ");
        Serial.println(count);

        brightness -= 50;
        if (brightness < 0) brightness = 255; 

        analogWrite(ledPin, brightness); 

        if (brightness > 200) {
            Serial.println("The LED is at full brightness");
        } else if (brightness > 100) {
            Serial.println("The LED is getting dimmer");
        } else {
            Serial.println("The LED is very dim now");
        }

        if (count > 10) {
            Serial.println("\"The only limit to our realization of tomorrow is our doubts of today.\" - Franklin D. Roosevelt");
        }

        delay(250); 
    } else {
        analogWrite(ledPin, 0); 
    }
}
