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

namespace SINGLESTEPPER {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();

namespace events {
void homeStepper();
}

namespace master {
extern RemoteValue<0, uint32_t> stepperPosition;

namespace events {
void homeStepper();
}
}
}



enum State {
  STATE_IDLE,
  STATE_SINGLESTEPPER
};

extern SlaveManager<State, 2, 0> manager;
