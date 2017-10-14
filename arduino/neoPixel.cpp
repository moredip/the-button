#include "neoPixel.h"

const int DATA_PIN = 14;

NeoPixel::NeoPixel()
  : _strip(1,DATA_PIN,NEO_RGB+NEO_KHZ800)
{
  _strip.begin();
  setColor(0,0,0);
}

void NeoPixel::setColor(uint8_t r, uint8_t g, uint8_t b){
  Serial.print("<NeoPixel> setColor(");
  Serial.print(r);
  Serial.print(",");
  Serial.print(g);
  Serial.print(",");
  Serial.print(b);
  Serial.println(")");
  _strip.setPixelColor(0,r,g,b);
  _strip.show();
}
