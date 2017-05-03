
var IDLE = {
  id: 0,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_IDLE = 0;
var SINGLESTEPPERSLIDER = {
  id: 1,
  master: {
    values: {
      position: new HardwareValue(1, 0, Manager.TYPE_UINT32),
      speed: new HardwareValue(1, 1, Manager.TYPE_UINT32),
      acceleration: new HardwareValue(1, 2, Manager.TYPE_UINT32)
    },
    events: {
      homeStepper: function homeStepper() { manager.sendEvent(0, 1); }
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_SINGLESTEPPERSLIDER = 1;

var STATES = {
  IDLE: IDLE,
  SINGLESTEPPERSLIDER: SINGLESTEPPERSLIDER
};
var manager = new Manager([IDLE, SINGLESTEPPERSLIDER]);
