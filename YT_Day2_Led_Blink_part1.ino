// 6 LEDs: Alternating Blue and Red on UNO PWM pins
// Blue LEDs: Pin 11, 9, 5
// Red LEDs: Pin 10, 6, 3
const int bluePins[3] = {11, 9, 5};
const int redPins[3]  = {10, 6, 3};
const int allPins[6]  = {11, 10, 9, 6, 5, 3};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(allPins[i], OUTPUT);
  }
}

void loop() {
  // ========================================================
  // Pattern 1: ৬টি LED একসাথে ব্লিংক করবে (ঠিক ৫ সেকেন্ড)
  // ২৫০ms ON + ২৫০ms OFF = ৫০০ms প্রতি সাইকেল। ১০ বার = ৫০০০ms (৫ সেকেন্ড)
  // ========================================================
  for (int i = 0; i < 10; i++) {
    // সবকটি অন
    for (int p = 0; p < 6; p++) {
      digitalWrite(allPins[p], HIGH);
    }
    delay(300);

    // সবকটি অফ
    for (int p = 0; p < 6; p++) {
      digitalWrite(allPins[p], LOW);
    }
    delay(300);
  }

  // ========================================================
  // Pattern 2: অল্টারনেটিং ব্লিংক (ঠিক ৫ সেকেন্ড)
  // Blue ON & Red OFF (২৫০ms) -> Red ON & Blue OFF (২৫০ms)
  // প্রতি সাইকেল ৫০০ms। ১০ বার = ৫০০০ms (৫ সেকেন্ড)
  // ========================================================
  for (int i = 0; i < 10; i++) {
    // ৩টি Blue ON, ৩টি Red OFF
    for (int b = 0; b < 3; b++) digitalWrite(bluePins[b], HIGH);
    for (int r = 0; r < 3; r++) digitalWrite(redPins[r], LOW);
    delay(350);

    // ৩টি Red ON, ৩টি Blue OFF
    for (int b = 0; b < 3; b++) digitalWrite(bluePins[b], LOW);
    for (int r = 0; r < 3; r++) digitalWrite(redPins[r], HIGH);
    delay(350);
  }

  // প্যাটার্ন রিপিট হওয়ার আগে সব LED নিভিয়ে ছোট্ট বিরতি
  for (int p = 0; p < 6; p++) {
    digitalWrite(allPins[p], LOW);
  }
  delay(400);
}