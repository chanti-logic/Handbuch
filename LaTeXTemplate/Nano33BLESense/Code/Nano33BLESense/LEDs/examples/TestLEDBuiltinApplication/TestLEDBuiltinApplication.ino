/**
*
*  @file TestLEDBuiltinApplication.ino
*
*  @brief How to control the built-in LED of the Arduino Nano 33 BLE Sense
*	
*
*  The LED is switched on for 1 second and switched off for 29 second so that the LED flashes accordingly.

*  
*/

#include <../LEDs/BuiltinLED.h>
#include <../LEDs/LED.h>
#include <../LEDs/SignsOfLife.h>


#define CycleTimeOn 1000 /*< Duty cycle[ms] */

#define CycleTimeOff 29000 /*< Switch-off time [ms] */



/**  
*  @brief the setup function runs once when you press reset or power the board
*
*  standard function of Arduino sketches
*  
*  Initialization of the pin LED_BUILTIN for the signs of life
*
*  @param ---
*
*  @return void
*/  
void setup() {
    // Initialize the function SignsOfLife
	SignsOfLifeInit(LED_BUILTIN, CycleTimeOn, CycleTimeOff)
	
	// Application
	// ...
}
 

   
   /** 
*  @brief the loop function runs over and over again forever
*  
*  standard function of Arduino sketches
*  
*  swichting the led on / off for the signs of life
*
*  @param ---
*
*  @return void
*/  
void loop() {
	// Switch builtin LED on/off
	SignsOfLife();
	
	// Application
	// ...
}