#include "states.h"
#include <SpeedyStepper.h>

namespace SINGLESTEPPER {
  
  const byte testPin = 10;
 
  void setup() {
    pinMode(testPin, OUTPUT);
    digitalWrite(testPin, HIGH);
  }
  
  void loop() {
 
  }
  
  void events::homeStepper() {
    digitalWrite(testPin, HIGH);
    delay(1000);
    digitalWrite(testPin, LOW);
    delay(1000);
    digitalWrite(testPin, HIGH);
    delay(1000);
    digitalWrite(testPin, LOW);
    delay(1000);
  }
  
  void enter() {

  }
  
  void exit() {

  }
}
