#include "Arduino.h"

#include "led.h"

const int LED_PIN = 13;

LED::LED()
{
  this->setOff();
}

void LED::setFlashing(int periodOn, int periodOff){
  _dutyCyclePeriodOn = periodOn;
  _dutyCyclePeriodOff = periodOff;
}

void LED::setOn(){
  setFlashing(1,0);
}

void LED::setOff(){
  setFlashing(0,1);
}

void LED::takeTurn(long now){
  int fullPeriod = _dutyCyclePeriodOn + _dutyCyclePeriodOff;
  int cyclePosition = now % fullPeriod;

  bool ledOn = cyclePosition <= _dutyCyclePeriodOff;

  digitalWrite(LED_PIN,ledOn);
}
