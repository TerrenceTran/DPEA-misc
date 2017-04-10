#pragma once

#define SLAVEMANAGER
#include <Manager.h>

namespace IDLE {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();

namespace events {

}

namespace master {


namespace events {

}
}
}

namespace TEST {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();

namespace events {
void fastBlink();
}

namespace master {


namespace events {
void fastBlink();
}
}
}



enum State {
  STATE_IDLE,
  STATE_TEST
};

extern SlaveManager<State, 2, 0> manager;
