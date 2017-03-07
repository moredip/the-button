#include "duid.h"

bool readDuid( DUID &duid){  
  if( EEPROM.read(0) != 'D' ){ return false; }
  if( EEPROM.read(1) != 'U' ){ return false; }
  if( EEPROM.read(2) != 'I' ){ return false; }
  if( EEPROM.read(3) != 'D' ){ return false; }
  
  for ( int i = 0; i <= 16; i++ ){
    duid[i] = EEPROM.read(i+4);
  }
  
  return true;
}
