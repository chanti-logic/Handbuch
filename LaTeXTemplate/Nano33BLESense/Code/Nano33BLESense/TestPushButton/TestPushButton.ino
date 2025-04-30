#include <LEDGeneral.h>
#include <LEDPower.h>
#include <LEDRGB.h>
#include <LEDSignsOfLife.h>
#include <LEDbuiltin.h>
#include <Arduino.h>

/**
*
*  @file TestPushButton.ino
*
*  @brief Simple application reading in the built-in push button states. 
*
*
*  @details If the built-in push button is pressed, the the internal built-in LED is turn on for 2 seconds

*  
*/

#define BUTTON_B 11 /*<   Button_B is here defined as pin 11 */ 
#define BUTTON_PIN  BUTTON_B /*< Use the onboard push button (BUTTON_B) */

#define SET_ON  true  /*< Define flag for switching on  */
#define SET_OFF false /*< Define flag for switching off */

bool buttonState = false; /*< state of the built-in push button */
 
/**  
*  @brief the setup function runs once when you press reset or power the board
*
*  standard function of Arduino sketches
*  
*  Initialization of the built-inb LED and the push button
*
*  @param ---
*
*  @return void
*/  
 
void setup() {
  // Initialize the pin as an output
  LEDBuiltinsetup();
  // Initialize the pin as an input
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

        
/** 
*  @brief the loop function runs over and over again forever
*  
*  standard function of Arduino sketches
*  
*  swichting the built-in led on for 2 sec, if the push button is pressed
*
*  @param ---
*
*  @return void
*/  
void loop() 
{
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) 
  {	
    // Turn the LED on
    LEDBuiltin(SET_ON);
    // Wait for two second
    delay(2000);
    // Turn the LED off
    LEDBuiltin(SET_OFF);
    // Wait for one second
    delay(1000);
    buttonState = LOW;
  }	
}