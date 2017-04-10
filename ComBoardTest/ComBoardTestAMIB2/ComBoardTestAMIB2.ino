#include <Arduino.h>
#include <Wire.h>
#include <MultiInterfaceBoard.h>
#include <SpeedyStepper.h>
#include <FlexyStepper.h>
#include <RCServo.h>

#include "states.h"
#include <Manager.h>

void setup() {
  setupMultiInterfaceBoard();
  manager.setup(STATE_IDLE);  
}

void loop() {
  manager.loop();
}