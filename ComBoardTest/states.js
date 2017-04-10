
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
var TEST = {
  id: 1,
  master: {
    values: {
      
    },
    events: {
      fastBlink: function fastBlink() { manager.sendEvent(0, 1); }
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_TEST = 1;

var STATES = {
  IDLE: IDLE,
  TEST: TEST
};
var manager = new Manager([IDLE, TEST]);
