#include "states.h"
#include <SpeedyStepper.h>
#include <FlexyStepper.h>

namespace SINGLESTEPPERSLIDER {
  
  FlexyStepper stepper;

  
  const byte STEPPER_PORT = 1;
  
  void setup() {
    
    stepper.connectToPort(STEPPER_PORT);
    stepper.setSpeedInStepsPerSecond(10);
    stepper.setAccelerationInStepsPerSecondPerSecond(50);
    stepper.setCurrentPositionInSteps(0.0);
    stepper.enableStepper();
  }
  
  void loop() {

    if (position.changed) {
      stepper.moveToPositionInSteps(position.value);
      position.changed = false;
    }
  
    if (speed.changed) {
      stepper.setSpeedInStepsPerSecond(speed.value);
      speed.changed = false;
    }
    
    if (acceleration.changed) {
      stepper.setAccelerationInStepsPerSecondPerSecond(acceleration.value);
      acceleration.changed = false;
    }
  
  }
  
  void events::homeStepper() {

  }
  
  void enter() {
    stepper.enableStepper();
  }
  
  void exit() {
    stepper.disableStepper();
  }
}
