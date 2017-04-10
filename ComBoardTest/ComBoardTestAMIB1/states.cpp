#include "states.h"

static const StateInfo state_infos[2] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {TEST::setup, TEST::enter, TEST::exit, TEST::loop, TEST::event}
};

static const WireValue wire_values[0] = {
  
};

MasterManager<State, 2, 0> manager(0xaf1efd27, state_infos, wire_values, 1);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
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

namespace amib2 {

namespace events {
void fastBlink() { manager.sendSlaveEvent(2, 0); }
}
}
}

