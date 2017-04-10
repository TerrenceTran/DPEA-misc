
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
var SPIROGRAPH = {
  id: 1,
  master: {
    values: {
      stepperSpeed1: new HardwareValue(1, 0, Manager.TYPE_UINT32),
      stepperSpeed2: new HardwareValue(1, 1, Manager.TYPE_UINT32),
      stepperSpeed3: new HardwareValue(1, 2, Manager.TYPE_UINT32)
    },
    events: {
      disableSteppers: function disableSteppers() { manager.sendEvent(0, 1); },
      enableSteppers: function enableSteppers() { manager.sendEvent(1, 1); }
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_SPIROGRAPH = 1;

var STATES = {
  IDLE: IDLE,
  SPIROGRAPH: SPIROGRAPH
};
var manager = new Manager([IDLE, SPIROGRAPH]);
