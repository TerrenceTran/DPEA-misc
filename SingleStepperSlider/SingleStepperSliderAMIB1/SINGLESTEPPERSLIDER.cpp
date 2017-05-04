#include "states.h"
#include <SpeedyStepper.h>
#include <FlexyStepper.h>

namespace SINGLESTEPPERSLIDER {
  
  FlexyStepper stepper;

  
  const byte STEPPER_PORT = 1;
  
  void setup() {
    
    stepper.connectToPort(STEPPER_PORT);
    stepper.setSpeedInStepsPerSecond(300);
    stepper.setAccelerationInStepsPerSecondPerSecond(1000);
    stepper.setCurrentPositionInSteps(0.0);
    stepper.enableStepper();
    
    position.value = 160;
  }
  
  void loop() {
  
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
  
  void events::positiveMove() {
    stepper.moveRelativeInSteps(position.value);
  }
  
  void events::negativeMove() {
    stepper.moveRelativeInSteps(-1 * position.value);
  }

  void events::enableStepper() {
    stepper.enableStepper();
  }

  void events::disableStepper() {
    stepper.disableStepper();
  }
  void enter() {
    stepper.enableStepper();
  }
  
  void exit() {
    stepper.disableStepper();
  }
}
