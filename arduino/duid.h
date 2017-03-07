#include <EEPROM.h>

#pragma once

typedef uint8_t DUID[16];

bool readDuid( DUID &duid);
void burnRandomDuid();
