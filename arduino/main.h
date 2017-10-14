#pragma once

class ServerGateway;
class Heartbeat;
class Button;
class ButtonReporter;
class LED;
class NeoPixel;
class StateMachine;

class Main {
  public:
    Main();
    void setup();
    void loop();

  private:
    String _duid;
    StateMachine *_pStateMachine;
    ServerGateway *_pServerGateway;
    Heartbeat *_pHeartbeat;
    Button *_pButton;
    ButtonReporter *_pButtonReporter;
    LED *_pLED;
    NeoPixel *_pNeoPixel;
};
