// Pin for the built-in LED
const int ledPin = 8 ;

// Define the Morse code for each letter (A-Z) and space
const String morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
  // Initialize the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);

}

void loop() {
  // Check if data is available to read from Serial Monitor
  if (Serial.available() > 0) {
    // Read the entire input line (until newline)
    String input = Serial.readStringUntil('\n');
    input.trim();  // Remove any extra spaces or newline characters
    
    // Print the input phrase for debugging
    Serial.print("Input Phrase: ");
    Serial.println(input);
    
    // Loop through each character in the input phrase
    for (int i = 0; i < input.length(); i++) {
      char letter = input.charAt(i);
      
      // Convert the character to uppercase
      letter = toupper(letter);

      // Check if the letter is a valid character (A-Z or space)
      if (letter >= 'A' && letter <= 'Z') {
        int index = letter - 'A';  // Find the corresponding index for the letter
        String code = morseCode[index];  // Get the Morse code for the letter
        
        // Blink the LED based on the Morse code
        blinkMorseCode(code);
        
        delay(500);
      }
      else if (letter == ' ') {
        // A space between words is represented by a longer pause
        Serial.println("Space detected. Adding gap between words.");
        delay(2000);  // Space between words 
      }
    }
    
    // After the whole input is processed, add a longer pause before next input
    delay(3000);  // Longer pause after processing the entire phrase
  }
}

void blinkMorseCode(String code) {
  for (int i = 0; i < code.length(); i++) {
    char symbol = code.charAt(i);
    
    if (symbol == '.') {
      digitalWrite(ledPin, HIGH);  
      delay(250);  
      digitalWrite(ledPin, LOW);   
      delay(250);  
    } else if (symbol == '-') {
      digitalWrite(ledPin, HIGH);  
      delay(750);  
      digitalWrite(ledPin, LOW);   
      delay(250);  
    }
  }

  delay(1000);  
}
