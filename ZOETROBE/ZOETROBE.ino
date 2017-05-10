#include <Arduino.h>
#include <SpeedyStepper.h>
#include <FlexyStepper.h>

#define BEAM_BUTTON_LIGHT 24
#define BEAM_BUTTON 25
#define BEAM_LEDS 10

#define BACKLIGHT_BUTTON_LIGHT 26
#define BACKLIGHT_BUTTON 27
#define BACKLIGHT_LEDS 9

#define LID_SENSOR 28

#define MOTOR_BUTTON_LIGHT 8
#define MOTOR_BUTTON 23
#define MOTOR_SPEED_POT A0
#define MOTOR_PORT 1

#define MICROSTEPPING 8
#define TRANSMISSION 5
#define BASE_STEPS_PER_REV 200

int beamState = LOW;
int lastBeamState = LOW;
int backlightState = LOW;
int lastBacklightState = LOW;
int motorState = LOW;
int lastMotorState = LOW;

FlexyStepper stepper;

void setup() {
  ////// Pinmode all ports ///////////
  
  pinMode(MOTOR_BUTTON_LIGHT, OUTPUT);
  pinMode(MOTOR_BUTTON, INPUT_PULLUP);
  pinMode(MOTOR_SPEED_POT, INPUT_PULLUP);

  pinMode(BEAM_BUTTON_LIGHT, OUTPUT);
  pinMode(BEAM_BUTTON, INPUT_PULLUP);
  pinMode(BEAM_LEDS, OUTPUT);

  pinMode(BACKLIGHT_BUTTON_LIGHT, OUTPUT);
  pinMode(BACKLIGHT_BUTTON, INPUT_PULLUP);
  pinMode(BACKLIGHT_LEDS, OUTPUT);

  pinMode(LID_SENSOR, INPUT_PULLUP);

  ////////// Initialize Stepper //////////

  stepper.connectToPort(MOTOR_PORT);
  stepper.setStepsPerRevolution(BASE_STEPS_PER_REV * TRANSMISSION * MICROSTEPPING);
  stepper.setSpeedInRevolutionsPerSecond(1.0);
  stepper.setAccelerationInRevolutionsPerSecondPerSecond(5.0);
  stepper.setCurrentPositionInRevolutions(0.0);
  stepper.setTargetPositionRelativeInRevolutions(1000.0);
  stepper.disableStepper();

  ///////// Initialize Lights and Button Lights //////////

  digitalWrite(MOTOR_BUTTON_LIGHT, motorState);
  digitalWrite(BEAM_BUTTON_LIGHT, beamState);
  digitalWrite(BEAM_LEDS, beamState);
  digitalWrite(BACKLIGHT_BUTTON_LIGHT, backlightState);
  digitalWrite(BACKLIGHT_LEDS, backlightState);

}

void loop() {

  //////////// Non-Latching Buttons require Button States /////////
  beamState = digitalRead(BEAM_BUTTON);
  backlightState = digitalRead(BACKLIGHT_BUTTON);
  motorState = digitalRead(MOTOR_BUTTON);
  
  if (beamState != lastBeamState) {
    digitalWrite(BEAM_BUTTON_LIGHT, beamState);
    digitalWrite(BEAM_LEDS, beamState);
    delay(50);
  }

  if (backlightState != lastBacklightState) {
    digitalWrite(BACKLIGHT_BUTTON_LIGHT, backlightState);
    digitalWrite(BACKLIGHT_LEDS, backlightState);
    delay(50);
  }

  if (motorState != lastMotorState) {
    //On State: enable motor and reset revolution goal
    if (motorState == HIGH) {
      digitalWrite(MOTOR_BUTTON_LIGHT, HIGH);
      stepper.resetVelocity();
      stepper.setSpeedInRevolutionsPerSecond(analogRead(MOTOR_SPEED_POT)/255.0);
      stepper.setTargetPositionRelativeInRevolutions(1000.0);
      stepper.enableStepper();
    }
    //Off State: disable motor and turn off light
    else {
      digitalWrite(MOTOR_BUTTON_LIGHT, LOW);
      stepper.disableStepper();
    }
    delay(50);
  }
  
  stepper.processMovement();

  ///////////// Save Last States For Next Loop Iteration /////////////
  lastMotorState = motorState;
  lastBeamState = beamState;
  lastBacklightState = backlightState;
}
