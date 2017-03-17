#pragma once

class LED {
  public:
    LED();
    void takeTurn(long now);

    void setFlashing(int periodOn, int periodOff);
    void setOn();
    void setOff();

  private:
    int _dutyCyclePeriodOn;
    int _dutyCyclePeriodOff;
};
