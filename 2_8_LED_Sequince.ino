int ledPins[] = {7, 8, 9, 10};
int delayTime = 2000;

void setup(){
  for (int i = 0; i < 4; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop(){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 5; j++){
      for (int numblinks = 5; numblinks > 4; numblinks++){
      digitalWrite(ledPins[i], HIGH);
      delay(delayTime);
      digitalWrite(ledPins[i], LOW);
      }
    }
  }   
}
