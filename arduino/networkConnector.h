#pragma once

class StateMachine;

class NetworkConnector {
  public:
    NetworkConnector(StateMachine &stateMachine);

    void BLOCKING_connectToNetwork();
  private:
    StateMachine &_stateMachine;
};
