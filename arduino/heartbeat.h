#pragma once

class StateMachine;
class ServerGateway;

class Heartbeat {
  public:
    Heartbeat(ServerGateway &serverGateway,StateMachine &stateMachine);
    void takeTurn(long now);

  private:
    ServerGateway &_serverGateway;
    StateMachine &_stateMachine;
    long _lastHeartbeat;
};
