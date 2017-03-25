#include "main.h"

Main main;

void setup() {
  Serial.begin(115200);
  delay(100); // seems to need a brief pause at boot

  main.setup();
}

void loop() {
  main.loop();
}
