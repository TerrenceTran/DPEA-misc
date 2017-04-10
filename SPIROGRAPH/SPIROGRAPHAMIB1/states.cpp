#include "states.h"

static const StateInfo state_infos[2] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {SPIROGRAPH::setup, SPIROGRAPH::enter, SPIROGRAPH::exit, SPIROGRAPH::loop, SPIROGRAPH::event}
};

static const WireValue wire_values[3] = {
  {1, 0, sizeof(uint32_t), (Value<void*>*) &SPIROGRAPH::stepperSpeed1},
  {1, 1, sizeof(uint32_t), (Value<void*>*) &SPIROGRAPH::stepperSpeed2},
  {1, 2, sizeof(uint32_t), (Value<void*>*) &SPIROGRAPH::stepperSpeed3}
};

MasterManager<State, 2, 3> manager(0xe550229b, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace SPIROGRAPH {
Value<uint32_t> stepperSpeed1;
Value<uint32_t> stepperSpeed2;
Value<uint32_t> stepperSpeed3;

void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::disableSteppers();
    break;
  case 1:
    events::enableSteppers();
    break;
  default:
    break;
  }
}


}

