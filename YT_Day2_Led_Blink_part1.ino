const int bluePins[3] = {11, 9, 5};
const int redPins[3]  = {10, 6, 3};
const int allPins[6]  = {11, 10, 9, 6, 5, 3};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(allPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 10; i++) {
    for (int p = 0; p < 6; p++) {
      digitalWrite(allPins[p], HIGH);
    }
    delay(300);    
    for (int p = 0; p < 6; p++) {
      digitalWrite(allPins[p], LOW);
    }
    delay(300);
  }
  for (int i = 0; i < 10; i++) {    
    for (int b = 0; b < 3; b++) digitalWrite(bluePins[b], HIGH);
    for (int r = 0; r < 3; r++) digitalWrite(redPins[r], LOW);
    delay(350);    
    for (int b = 0; b < 3; b++) digitalWrite(bluePins[b], LOW);
    for (int r = 0; r < 3; r++) digitalWrite(redPins[r], HIGH);
    delay(350);
  }  
  for (int p = 0; p < 6; p++) {
    digitalWrite(allPins[p], LOW);
  }
  delay(400);
}
