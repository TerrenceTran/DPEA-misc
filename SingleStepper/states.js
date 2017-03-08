
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
var SINGLESTEPPER = {
  id: 1,
  master: {
    values: {
      stepperPosition: new HardwareValue(1, 0, Manager.TYPE_UINT32)
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
var STATE_SINGLESTEPPER = 1;

var STATES = {
  IDLE: IDLE,
  SINGLESTEPPER: SINGLESTEPPER
};
var manager = new Manager([IDLE, SINGLESTEPPER]);
