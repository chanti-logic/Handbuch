// Define digital input pins for each speed setting using numeric pin numbers
const int pinLowSpeed = 2;     // Pin 2 connected to "Low Speed" position of rotary switch
const int pinMediumSpeed = 3;  // Pin 3 connected to "Medium Speed" position
const int pinHighSpeed = 4;    // Pin 4 connected to "High Speed" position

void setup() 
{
  // Configure the digital pins as inputs with internal pull-up resistors
  pinMode(pinLowSpeed, INPUT_PULLUP);
  pinMode(pinMediumSpeed, INPUT_PULLUP);
  pinMode(pinHighSpeed, INPUT_PULLUP);

  // Initialize serial communication for debugging purposes
  Serial.begin(10000);
}

void loop() 
{
  // Check which switch position is active (connected to GND) and give out a matching statement
  if (digitalRead(pinLowSpeed) == LOW) 
  {
    Serial.println("Motor speed: Low");
  }
  
   else if (digitalRead(pinMediumSpeed) == LOW) 
  {
    Serial.println("Motor speed: Medium");
  } 

  else if (digitalRead(pinHighSpeed) == LOW) 
  {
    Serial.println("Motor speed: High");
  }

  // Small delay to debounce the switch and avoid rapid state changes
  delay(100);
}
