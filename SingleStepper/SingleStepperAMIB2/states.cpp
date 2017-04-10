#include <SerialSlave.h>
#include "states.h"

static const StateInfo state_infos[2] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {SINGLESTEPPER::setup, SINGLESTEPPER::enter, SINGLESTEPPER::exit, SINGLESTEPPER::loop, SINGLESTEPPER::event}
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
namespace SINGLESTEPPER {


void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::homeStepper();
    break;
  default:
    break;
  }
}

namespace master {
RemoteValue<0, uint32_t> stepperPosition(0);

namespace events {
void homeStepper() { manager.sendEvent(0); }
}
}
}


SLAVERECV
