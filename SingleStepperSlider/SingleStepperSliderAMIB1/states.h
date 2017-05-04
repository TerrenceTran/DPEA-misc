#pragma once

#include <Manager.h>

namespace IDLE {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}

namespace SINGLESTEPPERSLIDER {
extern Value<uint32_t> position;
extern Value<uint32_t> speed;
extern Value<uint32_t> acceleration;

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {
void homeStepper();
void positiveMove();
void negativeMove();
void enableStepper();
void disableStepper();
}
}



enum State {
  STATE_IDLE,
  STATE_SINGLESTEPPERSLIDER
};

extern MasterManager<State, 2, 3> manager;
