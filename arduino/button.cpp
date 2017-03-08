#include "Arduino.h"

#include "button.h"

const int BUTTON_PIN = 12;
const long DEBOUNCE_DELAY = 50;


Button::Button(ButtonHandler &handler)
  : _handler(handler)
    , _lastReading(HIGH)
    , _buttonState(LOW)
    , _lastTransition(0)
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void Button::takeTurn(long now)
{
  int reading = digitalRead(BUTTON_PIN);

  if (reading != _lastReading) {
    _lastTransition = now;
  }

  if ((now - _lastTransition) > DEBOUNCE_DELAY) {
    if (reading != _buttonState) {
      _buttonState = reading;

      if( _buttonState == LOW ){ // logic is inverted - pulled-up button pin
        Serial.println("<Button> press detected");
        _handler.handleButtonPress();
      }
    }
  }

  _lastReading = reading;
}
