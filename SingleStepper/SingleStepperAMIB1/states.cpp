#include "states.h"

static const StateInfo state_infos[2] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {SINGLESTEPPER::setup, SINGLESTEPPER::enter, SINGLESTEPPER::exit, SINGLESTEPPER::loop, SINGLESTEPPER::event}
};

static const WireValue wire_values[1] = {
  {1, 0, sizeof(uint32_t), (Value<void*>*) &SINGLESTEPPER::stepperPosition}
};

MasterManager<State, 2, 1> manager(0xdf148757, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace SINGLESTEPPER {
Value<uint32_t> stepperPosition;

void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::homeStepper();
    break;
  default:
    break;
  }
}


}

