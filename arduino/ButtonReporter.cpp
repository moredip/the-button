#include "buttonReporter.h"

ButtonReporter::ButtonReporter(ServerGateway &serverGateway)
  :_serverGateway(serverGateway)
{}

void ButtonReporter::handleButtonPress(){
  _serverGateway.sendButtonPress();
}

