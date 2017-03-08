#include "states.h"
#include <FlexyStepper.h>

namespace SINGLESTEPPER {
  
  FlexyStepper stepper;
  
  const byte STEPPER_POWER = 10; // replaces #define / cap no underscore
  const byte STEPPER_PORT = 1;
  const byte STEPPER_HOME_SENSOR = 8;
  const byte MICROZERO = 26;
  const byte MICROONE = 24;
  
  void setup() {
    pinMode(STEPPER_POWER, OUTPUT);
    pinMode(MICROZERO, OUTPUT);
    pinMode(MICROONE, OUTPUT);
    pinMode(STEPPER_HOME_SENSOR, INPUT_PULLUP);
    
    digitalWrite(MICROZERO, LOW);
    digitalWrite(MICROONE, LOW);
    
    stepper.connectToPort(1);
    stepper.setStepsPerRevolution(200);
    stepper.setSpeedInRevolutionsPerSecond(0.2);
    stepper.setAccelerationInRevolutionsPerSecondPerSecond(0.1);
    
    stepper.enableStepper();
    stepper.moveToHomeInRevolutions(1, 200, 200, STEPPER_HOME_SENSOR);
    stepper.disableStepper();

  }
  
  void loop() {
    stepper.moveToPositionInRevolutions(0);
    stepper.moveToPositionInRevolutions(10);
  }
  
  void events::homeStepper() {
    stepper.moveToHomeInRevolutions(1, 200, 200, STEPPER_HOME_SENSOR);
  }
  
  void enter() {
    stepper.enableStepper();
  }
  
  void exit() {
    stepper.disableStepper();
  }
}
