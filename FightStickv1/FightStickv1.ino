/* Fight Stick v1
    Unojoy-based setup for 8-button arcade fighter (can also be used with whatever you'd like)
    
    Based on UnoJoy - Alan Chatham (2012)
    Syntax described for a 6-button + 2 macros fighter
*/

#include "UnoJoy.h"

// Define inputs
// Use digital for 11 pushbuttons
byte LightPunch = 2;
byte MediumPunch = 3;
byte HardPunch = 4;
byte MacroPunch = 5;

byte LightKick = 6;
byte MediumKick = 7;
byte HardKick = 8;
byte MacroKick = 9;

byte Menu = 10;
byte Select = 11;
byte Start = 12;

// Use analog (read as digitals) for directions
byte Up = A1;
byte Down = A2;
byte Left = A3;
byte Right = A4;

// Define input array
byte inputPinArray[] = {LightPunch, MediumPunch, HardPunch, MacroPunch,
                        LightKick, MediumKick, HardKick, MacroKick,
                        Menu, Select, Start,
                        Up, Down, Left, Right};

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set controller pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  for (int i = 0; i < sizeof(inputPinArray); i++){
    pinMode(inputPinArray[i], INPUT);
    digitalWrite(inputPinArray[i], HIGH);
  }
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  controllerData.triangleOn = !digitalRead(MediumPunch);
  controllerData.circleOn = !digitalRead(MediumKick);
  controllerData.squareOn = !digitalRead(LightPunch);
  controllerData.crossOn = !digitalRead(LightKick);
  
  // NOTE: In UnoJoyProcessingVisualizer, L1 appears as L2 and vice-versa, same for the R buttons.
  // Have not tested in PS3, but if X1/X2 are switched, switch the pin assignments of the same letter.
  controllerData.l1On = !digitalRead(MacroKick);
  controllerData.l2On = !digitalRead(MacroPunch);
  controllerData.r1On = !digitalRead(HardKick);
  controllerData.r2On = !digitalRead(HardPunch);
  
  controllerData.selectOn = !digitalRead(Select);
  controllerData.startOn = !digitalRead(Start);
  controllerData.homeOn = !digitalRead(Menu);
  
  controllerData.dpadLeftOn = !digitalRead(Left);
  controllerData.dpadUpOn = !digitalRead(Up);
  controllerData.dpadRightOn = !digitalRead(Right);
  controllerData.dpadDownOn = !digitalRead(Down);
  
  // And return the data!
  return controllerData;
}
