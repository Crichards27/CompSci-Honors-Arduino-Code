int RED_PIN = 9;
int GREEN_PIN 10;
int BLUE_PIN 11;

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}


void setColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}

void loop() {
    int stepDelay = 10; 

    // Transition through RGB color wheel
    for (int r = 255, g = 0, b = 0; g <= 255; g++) { setColor(r, g, b); delay(stepDelay); }  // Red to Yellow
    for (int r = 255, g = 255, b = 0; r >= 0; r--) { setColor(r, g, b); delay(stepDelay); }  // Yellow to Green
    for (int r = 0, g = 255, b = 0; b <= 255; b++) { setColor(r, g, b); delay(stepDelay); }  // Green to Cyan
    for (int r = 0, g = 255, b = 255; g >= 0; g--) { setColor(r, g, b); delay(stepDelay); }  // Cyan to Blue
    for (int r = 0, g = 0, b = 255; r <= 255; r++) { setColor(r, g, b); delay(stepDelay); }  // Blue to Magenta
    for (int r = 255, g = 0, b = 255; b >= 0; b--) { setColor(r, g, b); delay(stepDelay); }  // Magenta to Red
}
