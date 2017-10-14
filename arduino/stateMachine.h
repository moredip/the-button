#pragma once

class LED;
class NeoPixel;

class StateMachine {
  public:
    StateMachine(LED &led,NeoPixel &neoPixel);

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
    NeoPixel &_neoPixel;
    int _state;
};
