#pragma once

class LED;

class StateMachine {
  public:
    StateMachine(LED &led);

    void takeTurn(long now);

    void onHeartbeat();
    void onButtonPressed();

  private:
    void onStateChanged();
    void requestFutureTransitionToIdle(long duration);

    LED &_led;
    int _state;
    long _futureIdleTransitionPoint;
};
