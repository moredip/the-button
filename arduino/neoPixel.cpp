#include "neoPixel.h"

const int DATA_PIN = 14;

NeoPixel::NeoPixel()
  : _strip(1,DATA_PIN,NEO_RGB)
{
  _strip.begin();
  setColor(200,0,50);
}

void NeoPixel::setColor(uint8_t r, uint8_t g, uint8_t b){
  _strip.setPixelColor(0,r,g,b);
  _strip.show();
}
