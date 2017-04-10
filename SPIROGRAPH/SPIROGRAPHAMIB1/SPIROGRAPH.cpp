#include "states.h"
#include <SpeedyStepper.h>

namespace SPIROGRAPH {
  
  SpeedyStepper stepper1;
  SpeedyStepper stepper2;
  SpeedyStepper stepper3;
  
  const byte STEPPER_PORT_1 = 1;
  const byte STEPPER_PORT_2 = 2;
  const byte STEPPER_PORT_3 = 3;
  
  const byte MICRO_STEPPING_1 = 16; // WHITE 50:1
  const byte MICRO_STEPPING_2 = 16; // BLUE 5:1
  const byte MICRO_STEPPING_3 = 16; // RED 5:1
  
  const byte TRANSMISSION_1 = 50;
  const byte TRANSMISSION_2 = 5;
  const byte TRANSMISSION_3 = 5;
  
  const byte BASE_STEPS_PER_REVOLUTION = 200;
  
  void setup() {
    stepper1.connectToPort(STEPPER_PORT_1);
    stepper2.connectToPort(STEPPER_PORT_2);
    stepper3.connectToPort(STEPPER_PORT_3);
    
    stepper1.setStepsPerRevolution(BASE_STEPS_PER_REVOLUTION*MICRO_STEPPING_1*TRANSMISSION_1);
    stepper2.setStepsPerRevolution(BASE_STEPS_PER_REVOLUTION*MICRO_STEPPING_2*TRANSMISSION_2);
    stepper3.setStepsPerRevolution(BASE_STEPS_PER_REVOLUTION*MICRO_STEPPING_3*TRANSMISSION_3);
    
    stepper1.setSpeedInRevolutionsPerSecond(1.0);
    stepper2.setSpeedInRevolutionsPerSecond(1.0);
    stepper3.setSpeedInRevolutionsPerSecond(1.0);
    
    stepper1.setAccelerationInRevolutionsPerSecondPerSecond(10);
    stepper2.setAccelerationInRevolutionsPerSecondPerSecond(10);
    stepper3.setAccelerationInRevolutionsPerSecondPerSecond(10);

    stepper1.setCurrentPositionInRevolutions(0.0);
    stepper2.setCurrentPositionInRevolutions(0.0);
    stepper3.setCurrentPositionInRevolutions(0.0);

    stepper1.setupRelativeMoveInRevolutions(10000.0);
    stepper2.setupRelativeMoveInRevolutions(10000.0);
    stepper3.setupRelativeMoveInRevolutions(10000.0);

  }
  
  void loop() {
    /*
    stepper1.moveToPositionInRevolutions(0);
    stepper2.moveToPositionInRevolutions(0);
    stepper3.moveToPositionInRevolutions(0);
    
    stepper1.moveToPositionInRevolutions(16);
    stepper2.moveToPositionInRevolutions(16);
    stepper3.moveToPositionInRevolutions(16);
    */
    if(stepperSpeed1.changed || stepperSpeed2.changed || stepperSpeed3.changed) {
      stepper1.setSpeedInRevolutionsPerSecond(stepperSpeed1.value);
      stepper2.setSpeedInRevolutionsPerSecond(stepperSpeed2.value);
      stepper3.setSpeedInRevolutionsPerSecond(stepperSpeed3.value);
      
      stepperSpeed1.changed = false;
      stepperSpeed2.changed = false;
      stepperSpeed3.changed = false;
    }
    
    stepper1.processMovement();
    stepper2.processMovement();
    stepper3.processMovement();
  }
  
  void events::enableSteppers() {
    stepper1.enableStepper;
    stepper2.enableStepper;
    stepper3.enableStepper;
  }
  
  void events::disableSteppers() {
    stepper1.disableStepper();
    stepper2.disableStepper();
    stepper3.disableStepper();
  }
  
  void enter() {
    events::enableSteppers
  }
  
  void exit() {
    events::disableSteppers
  }
}
