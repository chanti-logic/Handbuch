/*
  APDS9960 - Gesture Sensor
  This example reads gesture data from the on-board APDS9960 sensor of the
  Nano 33 BLE Sense and prints any detected gestures to the Serial Monitor.
  Gesture directions are as follows:
  - UP:    from USB connector towards antenna
  - DOWN:  from antenna towards USB connector
  - LEFT:  from analog pins side towards digital pins side
  - RIGHT: from digital pins side towards analog pins side
  The circuit:
  - Arduino Nano 33 BLE Sense
  This example code is in the public domain.
*/

#include <Arduino_APDS9960.h>

void setup() {
  Serial.begin(9600);
  //Red
  pinMode(LEDR, OUTPUT);
  //Green
  pinMode(LEDG, OUTPUT);
  //Blue
  pinMode(LEDB, OUTPUT);
  
  while (!Serial);
  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
  }
  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);
  Serial.println("Detecting gestures ...");
  // Turining OFF the RGB LEDs
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}
void loop() {
  if (APDS.gestureAvailable()) {
    // a gesture was detected, read and print to serial monitor
    int gesture = APDS.readGesture();
    switch (gesture) {
      case GESTURE_UP:
        Serial.println("Detected UP gesture");
        digitalWrite(LEDR, LOW);
        delay(1000);
        digitalWrite(LEDR, HIGH);
        break;
      case GESTURE_DOWN:
        Serial.println("Detected DOWN gesture");
        digitalWrite(LEDG, LOW);
        delay(1000);
        digitalWrite(LEDG, HIGH);
        break;
      case GESTURE_LEFT:
        Serial.println("Detected LEFT gesture");
        digitalWrite(LEDB, LOW);
        delay(1000);
        digitalWrite(LEDB, HIGH);
        break;
      case GESTURE_RIGHT:
        Serial.println("Detected RIGHT gesture");
        digitalWrite(LEDB, LOW);
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDG, LOW);
        delay(1000);
        digitalWrite(LEDB, HIGH);
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDR, HIGH);
        break;
      default:
        break;
    }
  }
}