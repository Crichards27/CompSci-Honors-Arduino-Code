int ledPin = 10;
int delayTime = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);

}

void loop() {

digitalWrite(ledPin, HIGH);
delay(delayTime);
digitalWrite(ledPin, LOW);
delay(delayTime);
delayTime = delayTime - 500;
  if (delayTime == 0)
  {
  delayTime = 2000;
  }

}
