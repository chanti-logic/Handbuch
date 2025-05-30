#include <LEDGeneral.h>
#include <LEDPower.h>
#include <LEDRGB.h>
#include <LEDSignsOfLife.h>
#include <LEDbuiltin.h>





/**
*  @file TestLEDBuiltin.ino
*
*  @brief Simple program for testing the built-in LED
*	
*
*  Turns the built-in LED on for one second, then off for one second, repeatedly.
*
*  The LED is switched on for 1 second and switched off 
*  for 1 second so that the LED flashes accordingly.
*
*  On the Arduino Nano 33 BLE Sense, it is attached to digital pin 13
*
*/

 
/**  
*  @brief the setup function runs once when you press reset or power the board
*
*  Standard function of Arduino sketches
*  
*  Initialization of the pin LED_BUILTIN as output
*
*  @param ---
*
*  @return void
*/  
void setup() {
    // Initialize the pin as an output
    LEDBuiltinsetup();
}
        
/** 
*  @brief the loop function runs over and over again forever
*  
*  standard function of Arduino sketches
*  
*  swichting the led on / off for 1sec.
*
*  @param ---
*
*  @return void
*/  
void loop() {
    // Turn the LED on
    LEDBuiltin(false);
    // Wait for one second
    delay(1000);
    // Turn the LED off
    LEDBuiltin(true);
    // Wait for one second
    delay(1000);
}