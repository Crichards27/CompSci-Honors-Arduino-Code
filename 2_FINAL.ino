const int red1 = 2, yellow1 = 3, green1 = 4;
const int red2 = 5, yellow2 = 6, green2 = 7;
const int pedestrianButton = 8, pedestrianLight = 9;
const int buzzer = 10; 

bool pedestrianRequest = false; 

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(pedestrianLight, OUTPUT);
  pinMode(buzzer, OUTPUT);  
  
  pinMode(pedestrianButton, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(pedestrianButton), requestPedestrianCrossing, FALLING);
}

void loop() {
  if (pedestrianRequest) {
    activatePedestrianCrossing();
    pedestrianRequest = false;
  } else {
    normalTrafficCycle();
  }
}

// Normal traffic light cycle
void normalTrafficCycle() {
  // Signal 1: Red, Signal 2: Green (5s)
  digitalWrite(red1, HIGH);
  digitalWrite(green2, HIGH);
  delay(5000);
  
  // Signal 2: Yellow (3s)
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  delay(3000);
  
  // Signal 2: Red, Signal 1: Green (5s)
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green1, HIGH);
  delay(5000);
  
  // Signal 1: Yellow (3s)
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(3000);
  
  // Reset for next cycle
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, LOW);
}

// Pedestrian crossing function
void activatePedestrianCrossing() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    delay(500);
    
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    delay(500);
  }

  
  digitalWrite(pedestrianLight, HIGH);
  for (int i = 0; i < 10; i++) {  
    tone(buzzer, 1000); 
    delay(250);         
    noTone(buzzer);     
    delay(250);         
  }
  digitalWrite(pedestrianLight, LOW);
}


void requestPedestrianCrossing() {
  pedestrianRequest = true;
}
