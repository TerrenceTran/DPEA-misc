'use strict'; //This causes it to be executed in "strict" mode which prevents some unsafe syntax

// Set up a new stage
var floor = Math.floor;
var stage = new Stage();

// manager variables
var manager;

// We need to declare each scene
var MenuScene;
var attrs;

// This function would preload any images used by p5
// You can see an example of this in the Console 4 or 10 code
function preload() {
}

// This is one of the first functions that gets called when you load the interface
// It is the function that should initialize any variables you want to access from any scene
// and it should construct the scenes in the next heirarchy level down (Such as menu scenes and custom control scenes)
function setup() {
  // MASTER = true; // for two player mode, not necessary
  resizeCanvas(windowWidth, windowHeight);
  initMenuVariables();
  attrs = {fill:255, size:100, align:CENTER, style:BOLD, leading:50, strokeWeight:10, strokeColor:0}; //This is our text attributes variable
  
  //Here we create the menu scene. It a simple ButtonScene with one button with the following names and button action
  var menuButtonNames = ["Step Up", "Step Down"];
  var menuButtonActions = [this.positiveMove.bind(this), this.negativeMove.bind(this)];
  
  this.MenuScene = new ButtonsScene("Step The Step", null, menuButtonNames, menuButtonActions, null, null, null, {size:100, leading:50});
  stage.addScene("MenuScene", this.MenuScene);
  
  //Finally we transition to our menu scene once everything has been created
  stage.transitionTo('MenuScene');  
  manager.changeState(STATE_SINGLESTEPPERSLIDER);
}

//Required draw function. Dont change
function draw() {
  stage.draw();
}

////////////////////////////////////////////////// BUTTONS ////////////////////////////////////

// This starting scene has one buttons: A start button
function positiveMove() {
  console.log("Positive Move");
  SINGLESTEPPERSLIDER.master.events.positiveMove();
}

function negativeMove() {
  console.log("Negative Move");
  SINGLESTEPPERSLIDER.master.events.negativeMove();
}

//All these are needed to handle touch/mouse events properly
window.touchStarted = stage.touchStarted.bind(stage);
window.touchMoved = stage.touchMoved.bind(stage);
window.touchEnded = stage.touchEnded.bind(stage);
window.mousePressed = stage.mousePressed.bind(stage);
window.mouseDragged = stage.mouseDragged.bind(stage);
window.mouseReleased = stage.mouseReleased.bind(stage);
