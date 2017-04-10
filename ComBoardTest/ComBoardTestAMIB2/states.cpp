#include <SerialSlave.h>
#include "states.h"

static const StateInfo state_infos[2] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {TEST::setup, TEST::enter, TEST::exit, TEST::loop, TEST::event}
};

static const WireValue wire_values[0] = {
  
};

SlaveManager<State, 2, 0> manager(2, state_infos, wire_values);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}

namespace master {


namespace events {

}
}
}
namespace TEST {


void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::fastBlink();
    break;
  default:
    break;
  }
}

namespace master {


namespace events {
void fastBlink() { manager.sendEvent(0); }
}
}
}


SLAVERECV
