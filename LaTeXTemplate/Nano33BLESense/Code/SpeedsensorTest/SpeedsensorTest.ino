#define SPEED_SENSOR_PIN 2  // Sensor connected to pin D2

void setup() {
  pinMode(SPEED_SENSOR_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("LM393 Speed Sensor test started");
}

void loop() {
  int sensorState = digitalRead(SPEED_SENSOR_PIN);

  if (sensorState == LOW) {
    Serial.println("Object detected (LOW)");
  } else {
    Serial.println("No object detected (HIGH)");
  }

  delay(100);  // Small delay for better readability
}


