#pragma once

#include <Adafruit_NeoPixel.h>

class NeoPixel {
  public:
    NeoPixel();
    void setColor(uint8_t r, uint8_t g, uint8_t b);

  private:
    Adafruit_NeoPixel _strip;
};
