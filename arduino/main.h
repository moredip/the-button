#pragma once

class ServerGateway;
class Heartbeat;
class Button;
class ButtonReporter;

class Main {
  public:
    Main();
    void setup();
    void loop();

  private:
    String _duid;
    ServerGateway *_pServerGateway;
    Heartbeat *_pHeartbeat;
    Button *_pButton;
    ButtonReporter *_pButtonReporter;
};
