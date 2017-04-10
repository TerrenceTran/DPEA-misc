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

namespace SPIROGRAPH {
extern Value<uint32_t> stepperSpeed1;
extern Value<uint32_t> stepperSpeed2;
extern Value<uint32_t> stepperSpeed3;

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {
void disableSteppers();
void enableSteppers();
}
}



enum State {
  STATE_IDLE,
  STATE_SPIROGRAPH
};

extern MasterManager<State, 2, 3> manager;
