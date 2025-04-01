const int red1 = 3, yellow1 = 4, green1 = 5;    //North-South
const int red2 = 6, yellow2 = 7, green2 = 8;    //East-West
const int pedestrianButton = 2, pedestrianLight = 9;
const int buzzer = 10; 

volatile bool pedestrianRequest = false;
volatile unsigned long lastInterruptTime = 0;

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
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pedestrianButton), requestPedestrianCrossing, FALLING);
}

void loop() {
  if (pedestrianRequest) {
    Serial.println("Pedestrian button pressed");
    activatePedestrianCrossing();
    pedestrianRequest = false;
  } else {
    normalTrafficCycle();
  }
}

void normalTrafficCycle() {
  digitalWrite(red1, HIGH);
  digitalWrite(green2, HIGH);
  delay(5000);
  
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  delay(3000);
  
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green1, HIGH);
  delay(5000);
  
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(3000);
  
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, LOW);
}

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
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 200) {  
    pedestrianRequest = true;
    lastInterruptTime = interruptTime;
  }
}
