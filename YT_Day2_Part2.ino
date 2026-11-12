const int ledPins[6] = {3, 5, 6, 9, 10, 11};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() { 
  for (int repeat = 0; repeat < 4; repeat++) {    
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(80);
      digitalWrite(ledPins[i], LOW);
    }    
    for (int i = 4; i > 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(80);
      digitalWrite(ledPins[i], LOW);
    }
  } 
  delay(300);  
  for (int repeat = 0; repeat < 2; repeat++) {    
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      for (int i = 0; i < 6; i++) {
        analogWrite(ledPins[i], brightness);
      }
      delay(20);
    }    
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      for (int i = 0; i < 6; i++) {
        analogWrite(ledPins[i], brightness);
      }
      delay(20);
    }
  }

  delay(500);
}
