#include "states.h"

namespace TEST {
  
  const byte LED_PIN = 13;
 
  void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
  }
  
  void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
  
  void events::fastBlink() {
    for(int i = 0; i < 20; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  }
  
  void enter() {

  }
  
  void exit() {

  }
}
