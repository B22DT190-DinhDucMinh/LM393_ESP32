#define SOUND_PIN 0   // GPIO0 - chân BOOT

unsigned long lastTrigger = 0;
int count = 0;
// hello
void setup() {
  Serial.begin(115200);
  Serial.println("Sound Sensor Started");
  pinMode(SOUND_PIN, INPUT);
}

void loop() {
  // LM393 kích mức LOW khi có tiếng động
  if (digitalRead(SOUND_PIN) == LOW) {

    // Chống nhiễu để không đếm nhiều lần
    if (millis() - lastTrigger > 300) {
      count++;   // tăng số lần phát hiện

      Serial.print("[");
      Serial.print(count);
      Serial.print("] Sound detected at ");
      Serial.print(millis());
      Serial.println(" ms");
    }

    lastTrigger = millis();
  }
}