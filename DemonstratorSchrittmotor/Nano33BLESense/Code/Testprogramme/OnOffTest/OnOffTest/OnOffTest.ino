#define SWITCH_PIN 9  // Connect your rocker switch to digital pin 9

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP);  // Use internal pull-up resistor
  Serial.begin(9600);
  Serial.println("On/Off Rocker Switch Test Started");
}

void loop() {
  bool switchOn = digitalRead(SWITCH_PIN) == LOW;  // LOW = switched ON (depending on wiring)

  if (switchOn) {
    Serial.println("Switch is ON!");
  } else {
    Serial.println("Switch is OFF!");
  }

  delay(200); // Adjust delay as needed
}

