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
  onStateChanged();
}

void StateMachine::onConnectingToNetwork(){
  _state = LOOKING_FOR_NETWORK;
  onStateChanged();
}

void StateMachine::onConnectedToNetwork(){
  _state = IDLE;
  onStateChanged();
}

void StateMachine::onFailedToConnectToNetwork(){
  _state = NO_NETWORK;
  onStateChanged();
}

void StateMachine::onHeartbeat(){
  _state = SENDING_HEARTBEAT;
  onStateChanged();
  requestFutureTransitionToIdle(100);
}

void StateMachine::onButtonPressed(){
  _state = SENDING_BUTTON_PRESS;
  onStateChanged();
  requestFutureTransitionToIdle(3000);
}

void StateMachine::onStateChanged(){
  switch(_state){
    case BOOTING:
      Serial.println("<StateMachine> BOOTING");
      _led.setOn();
      return;
    case LOOKING_FOR_NETWORK: 
      Serial.println("<StateMachine> LOOKING_FOR_NETWORK");
      _led.setFlashing(500,1000);
      return;
    case NO_NETWORK: 
      Serial.println("<StateMachine> NO_NETWORK");
      _led.setFlashing(50,50);
      return;
    case IDLE: 
      Serial.println("<StateMachine> IDLE");
      _led.setOff();
      return;
    case SENDING_HEARTBEAT:
      Serial.println("<StateMachine> SENDING_HEARTBEAT");
      _led.setFlashing(5,20);
      return;
    case SENDING_BUTTON_PRESS: 
      Serial.println("<StateMachine> SENDING_BUTTON_PRESS");
      _led.setFlashing(500,100);
      return;
  }
}

Ticker ticker;

void transitionToIdleBinder(StateMachine *self){
  reinterpret_cast<StateMachine *>(self)->_transitionToIdle();
}

void StateMachine::requestFutureTransitionToIdle(long duration){
  ticker.once_ms (duration,transitionToIdleBinder,this);
}

void StateMachine::_transitionToIdle(){
  _state = IDLE;
  onStateChanged();
}
