#include "ServerGateway.h"

#pragma once

class Heartbeat {
  public:
    Heartbeat(ServerGateway &serverGateway);
    void takeTurn(long now);

  private:
    
    ServerGateway &_serverGateway;
    long _lastHeartbeat;
};
