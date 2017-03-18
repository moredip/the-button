#include "Arduino.h"
#include <Ticker.h>
#include <limits.h>

#include "led.h"
#include "stateMachine.h"

enum STATE {
  BOOTING,
  LOOKING_FOR_NETWORK,
  NO_NETWORK,
  IDLE,
  SENDING_HEARTBEAT,
  SENDING_BUTTON_PRESS
};

StateMachine::StateMachine(LED &led)
  : _led(led),
  _state(BOOTING)
{
}

void StateMachine::onHeartbeat(){
  _state = SENDING_HEARTBEAT;
  requestFutureTransitionToIdle(1000);
}

void StateMachine::onButtonPressed(){
  _state = SENDING_BUTTON_PRESS;
  requestFutureTransitionToIdle(5000);
}

void StateMachine::onStateChanged(){
  switch(_state){
    case BOOTING: 
      _led.setOn();
      return;
    case LOOKING_FOR_NETWORK: 
      _led.setFlashing(500,1000);
      return;
    case NO_NETWORK: 
      _led.setFlashing(50,50);
      return;
    case IDLE: 
      _led.setOff();
      return;
    case SENDING_HEARTBEAT: 
      _led.setFlashing(20,200);
      return;
    case SENDING_BUTTON_PRESS: 
      _led.setFlashing(500,100);
      return;
  }
}

Ticker ticker;

void transitionToIdleBinder(StateMachine *self){
  reinterpret_cast<StateMachine *>(self)->_transitionToIdle();
}

void StateMachine::requestFutureTransitionToIdle(long duration){
  ticker.once(duration,transitionToIdleBinder,this);
}

void StateMachine::_transitionToIdle(){
  _state = IDLE;
  onStateChanged();
}
