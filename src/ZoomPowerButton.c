/*
ansshahzadr 6/16/2021
DK: leanoardo with Atmega32U4

Functions:
quick press the button once to bring the zoom window to the front and mute it
long press the button if the window is in the front will end the zoom meeting

Button Lib:
https://github.com/mathertel/OneButton

Keyboard Lib:
https://github.com/arduino-libraries/Keyboard
*/

#include "OneButton.h"
#include "Keyboard.h"

const int PIN_INPUT = 2;          // button input pin

//set up button
OneButton button(PIN_INPUT, true);

void setup() {

  // make input pin an input and turn on the
  // pullup resistor so it does'nt goes high unless
  // connected to ground
  pinMode(PIN_INPUT, INPUT_PULLUP);  
  Keyboard.begin();

  //button lib functions
  button.attachClick(click1);
  button.attachLongPressStart(longPressStart1);
  delay(100);
  
}

void loop() {

  //monitor buttons
  button.tick();
}

// This function will be called when the button is was pressed once.
void click1() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('a');
  Keyboard.releaseAll(); 
} 

// This function will be called once when the button1 is pressed for a long time.
void longPressStart1() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('q');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.println();
}