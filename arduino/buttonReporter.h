#include "Button.h"

#include "ServerGateway.h"
#include "StateMachine.h"

#pragma once

class ButtonReporter : public ButtonHandler {
  public:
    ButtonReporter(ServerGateway &serverGateway, StateMachine &stateMachine);
    void handleButtonPress();

  private:
    ServerGateway &_serverGateway;
    StateMachine &_stateMachine;
};
