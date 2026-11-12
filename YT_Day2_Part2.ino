// 6 LEDs: Alternating Blue and Red on UNO's 6 PWM pins
const int ledPins[6] = {3, 5, 6, 9, 10, 11};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // ==========================================
  // ১ম অংশ: ডিজিটাল সিকোয়েন্স (Chaser Effect)
  // ==========================================
  for (int repeat = 0; repeat < 4; repeat++) {
    // বাম থেকে ডানে (Blue -> Red -> Blue -> Red -> Blue -> Red)
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(80);
      digitalWrite(ledPins[i], LOW);
    }
    // ডান থেকে বামে
    for (int i = 4; i > 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(80);
      digitalWrite(ledPins[i], LOW);
    }
  }

  // সব অফ করে ছোট বিরতি
  delay(300);

  // ==========================================
  // ২য় অংশ: ব্রাইটনেস কন্ট্রোল (PWM Breathing Effect)
  // ==========================================
  for (int repeat = 0; repeat < 2; repeat++) {
    // ব্রাইটনেস বাড়ানো (Fade In: 0 to 255)
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      for (int i = 0; i < 6; i++) {
        analogWrite(ledPins[i], brightness);
      }
      delay(20);
    }

    // ব্রাইটনেস কমানো (Fade Out: 255 to 0)
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      for (int i = 0; i < 6; i++) {
        analogWrite(ledPins[i], brightness);
      }
      delay(20);
    }
  }

  delay(500);
}