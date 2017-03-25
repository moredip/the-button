#pragma once

class LED;

class StateMachine {
  public:
    StateMachine(LED &led);

    void takeTurn(long now);

    void onConnectingToNetwork();
    void onConnectedToNetwork();
    void onFailedToConnectToNetwork();
    void onHeartbeat();
    void onButtonPressed();

    void _transitionToIdle();

  private:
    void onStateChanged();
    void requestFutureTransitionToIdle(long duration);

    LED &_led;
    int _state;
};
