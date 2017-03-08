#pragma once

class ButtonHandler {
  public:
    virtual void handleButtonPress() = 0;
};

class Button {
  public:
    Button(ButtonHandler &handler);
    void takeTurn(long now);

  private:
    ButtonHandler &_handler;
    
    int _buttonState;
    int _lastReading;
    long _lastTransition;
};
