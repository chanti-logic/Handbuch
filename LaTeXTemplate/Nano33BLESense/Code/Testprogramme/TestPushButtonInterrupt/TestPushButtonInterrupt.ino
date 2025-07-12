#define SPEED_SENSOR_PIN 2  // Connect the LM393 output to digital pin 2

void setup() {
  pinMode(SPEED_SENSOR_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("LM393 Speed Sensor Test Started");
}

void loop() {
  int sensorState = digitalRead(SPEED_SENSOR_PIN);

  if (sensorState == LOW) {
    Serial.println("Object detected (LOW signal)");
  } else {
    Serial.println("No object (HIGH signal)");
  }

  delay(200); // Adjust delay as needed
}
