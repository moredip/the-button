#include "buttonReporter.h"

ButtonReporter::ButtonReporter(ServerGateway &serverGateway, StateMachine &stateMachine)
  :_serverGateway(serverGateway),
  _stateMachine(stateMachine)
{}

void ButtonReporter::handleButtonPress(){
  _serverGateway.sendButtonPress();
  _stateMachine.onButtonPressed();
}

