#define LEFT_SWITCH_PIN 7
#define RIGHT_SWITCH_PIN 8

void setup() {
  pinMode(LEFT_SWITCH_PIN, INPUT_PULLUP);   // Use internal pull-up resistor
  pinMode(RIGHT_SWITCH_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Microswitch Test Started");
}

void loop() {
  bool leftPressed = digitalRead(LEFT_SWITCH_PIN) == LOW;   // LOW = pressed
  bool rightPressed = digitalRead(RIGHT_SWITCH_PIN) == LOW;

  if (leftPressed) {
    Serial.println("Left microswitch is pressed!");
  } else {
    Serial.println("Left microswitch is released.");
  }

  if (rightPressed) {
    Serial.println("Right microswitch is pressed!");
  } else {
    Serial.println("Right microswitch is released.");
  }

  delay(300); // Adjust delay as needed
}
