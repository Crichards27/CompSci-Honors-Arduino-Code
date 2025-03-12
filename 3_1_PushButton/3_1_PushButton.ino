const int buttonPin = 2;   // Button connected to pin 2
const int led1 = 8;        // LED 1 connected to pin 8
const int led2 = 11;       // LED 2 connected to pin 11

int buttonState;           
int lastButtonState = LOW; 
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int pressCount = 0;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    int reading = digitalRead(buttonPin);


  
        if (reading == LOW && lastButtonState == HIGH) {     //DEtect button press
            pressCount++;
            delay(500);
            if (pressCount == 1) {          //Light states
                digitalWrite(led1, HIGH);
                digitalWrite(led2, LOW);
            } else if (pressCount == 2) {
                digitalWrite(led1, LOW);
                digitalWrite(led2, HIGH);
            } else if (pressCount == 3) {
                digitalWrite(led1, HIGH);
                digitalWrite(led2, HIGH);
            } else if (pressCount >= 4) {
                digitalWrite(led1, LOW);
                digitalWrite(led2, LOW);
                pressCount = 0;     // Reset press count
            }
        }
    

    lastButtonState = reading;    //Stores last button state on/off
}
