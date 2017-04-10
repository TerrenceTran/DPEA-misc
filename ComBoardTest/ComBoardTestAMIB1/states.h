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

namespace TEST {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();

namespace amib2 {

namespace events {
void fastBlink();

}
}

namespace events {
void fastBlink();
}
}



enum State {
  STATE_IDLE,
  STATE_TEST
};

extern MasterManager<State, 2, 0> manager;
