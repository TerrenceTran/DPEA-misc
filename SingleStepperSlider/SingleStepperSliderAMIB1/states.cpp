#include "states.h"

static const StateInfo state_infos[2] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {SINGLESTEPPERSLIDER::setup, SINGLESTEPPERSLIDER::enter, SINGLESTEPPERSLIDER::exit, SINGLESTEPPERSLIDER::loop, SINGLESTEPPERSLIDER::event}
};

static const WireValue wire_values[3] = {
  {1, 0, sizeof(uint32_t), (Value<void*>*) &SINGLESTEPPERSLIDER::position},
  {1, 1, sizeof(uint32_t), (Value<void*>*) &SINGLESTEPPERSLIDER::speed},
  {1, 2, sizeof(uint32_t), (Value<void*>*) &SINGLESTEPPERSLIDER::acceleration}
};

MasterManager<State, 2, 3> manager(0x6a19ede2, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace SINGLESTEPPERSLIDER {
Value<uint32_t> position;
Value<uint32_t> speed;
Value<uint32_t> acceleration;

void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::homeStepper();
    break;
  case 1:
    events::positiveMove();
    break;
  case 2:
    events::negativeMove();
    break;
  case 3:
    events::enableStepper();
    break;
  case 4:
    events::disableStepper();
    break;
  default:
    break;
  }
}


}

