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

namespace SINGLESTEPPER {
extern Value<uint32_t> stepperPosition;

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {
void homeStepper();
}
}



enum State {
  STATE_IDLE,
  STATE_SINGLESTEPPER
};

extern MasterManager<State, 2, 1> manager;
