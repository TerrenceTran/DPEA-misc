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

FlexyStepper stepper;

void setup() {
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

  stepper.connectToPort(MOTOR_PORT);
  stepper.setStepsPerRevolution(BASE_STEPS_PER_REV * TRANSMISSION * MICROSTEPPING);
  stepper.setSpeedInRevolutionsPerSecond(1.0);
  stepper.setAccelerationInRevolutionsPerSecondPerSecond(5.0);
  stepper.setCurrentPositionInRevolutions(0.0);

  stepper.setTargetPositionRelativeInRevolutions(1000.0);
  stepper.enableStepper();

}

void loop() {
  stepper.processMovement();
}
