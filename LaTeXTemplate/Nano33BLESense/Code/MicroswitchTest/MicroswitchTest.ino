#define SWITCH_PIN 9  // Toggle switch connected to pin D9

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Test for toggle switch started");
}

void loop() {
  bool switchOn = digitalRead(SWITCH_PIN) == LOW;  // LOW = ON (depending on wiring)

  if (switchOn) {
    Serial.println("Switch is ON!");
  } else {
    Serial.println("Switch is OFF!");
  }

  delay(200);
}
