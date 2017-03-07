#include "Arduino.h"

#include "duid.h"

bool readDuid( DUID &duid)
{  
  if( EEPROM.read(0) != 'D' ){ return false; }
  if( EEPROM.read(1) != 'U' ){ return false; }
  if( EEPROM.read(2) != 'I' ){ return false; }
  if( EEPROM.read(3) != 'D' ){ return false; }
  
  for ( int i = 0; i <= 16; i++ ){
    duid[i] = EEPROM.read(i+4);
  }
  
  return true;
}

void burnRandomDuid()
{
  EEPROM.write(0, 'D');
  EEPROM.write(1, 'U');
  EEPROM.write(2, 'I');
  EEPROM.write(3, 'D');

  for ( int i = 0; i <= 16; i++ ){
    EEPROM.write(i+4, random(256)); 
  }
}

String duidAsString(const DUID &duid)
{
  String s;
  for ( int i = 0; i <= 16; i++ ){
    s += String(duid[i],HEX);
  }
  return s;
}

