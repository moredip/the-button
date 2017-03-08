#include "Button.h"
#include "ServerGateway.h"

#pragma once

class ButtonReporter : public ButtonHandler {
  public:
    ButtonReporter(ServerGateway &serverGateway);
    void handleButtonPress();

  private:
    ServerGateway &_serverGateway;
};
