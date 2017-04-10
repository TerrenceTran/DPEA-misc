#include "states.h"
#include <SpeedyStepper.h>

namespace SINGLESTEPPER {
  
  SpeedyStepper stepper1;
  SpeedyStepper stepper2;
  //SpeedyStepper stepper3;
  
  const byte STEPPER_PORT_1 = 1;
  const byte STEPPER_PORT_2 = 2;
  const byte STEPPER_PORT_3 = 3;
  const byte STEPPER_HOME_SENSOR = 62;
  const byte MICRO_STEPPING = 32;
  const byte BASE_STEPS_PER_REVOLUTION = 200;
  
  void setup() {
    pinMode(STEPPER_HOME_SENSOR, INPUT_PULLUP);
    
    stepper1.connectToPort(STEPPER_PORT_1);
    stepper2.connectToPort(STEPPER_PORT_2);
    //stepper3.connectToPort(STEPPER_PORT_3);
    
    stepper1.setStepsPerRevolution(BASE_STEPS_PER_REVOLUTION*MICRO_STEPPING);
    stepper2.setStepsPerRevolution(BASE_STEPS_PER_REVOLUTION*MICRO_STEPPING);
    //stepper3.setStepsPerRevolution(BASE_STEPS_PER_REVOLUTION*MICRO_STEPPING);
    
    stepper1.setSpeedInRevolutionsPerSecond(2);
    stepper2.setSpeedInRevolutionsPerSecond(0.5);
    //stepper3.setSpeedInRevolutionsPerSecond(10);
    
    stepper1.setAccelerationInRevolutionsPerSecondPerSecond(10);
    stepper2.setAccelerationInRevolutionsPerSecondPerSecond(10);
    //stepper3.setAccelerationInRevolutionsPerSecondPerSecond(10);

    stepper1.setCurrentPositionInRevolutions(0.0);
    stepper2.setCurrentPositionInRevolutions(0.0);
    //stepper3.setCurrentPositionInRevolutions(0.0);

    stepper1.setupRelativeMoveInRevolutions(10000.0);
    stepper2.setupRelativeMoveInRevolutions(10000.0);
    //stepper3.setupRelativeMoveInRevolutions(10000.0);

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

    stepper1.processMovement();
    stepper2.processMovement();
    //stepper3.processMovement();
  }
  
  void events::homeStepper() {
    amib2::events::homeStepper();
    //stepper1.moveToHomeInRevolutions(1, 4, 200, STEPPER_HOME_SENSOR);
  }
  
  void enter() {
    stepper1.enableStepper();
    stepper2.enableStepper();
    //stepper3.enableStepper();
  }
  
  void exit() {
    stepper1.disableStepper();
    stepper2.disableStepper();
    //stepper3.disableStepper();
  }
}
