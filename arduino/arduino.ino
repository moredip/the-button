#include "duid.h"

DUID g_duid;

void setup() {
  Serial.begin(9600);
  
  loadDuid();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void loadDuid(){
  EEPROM.begin(20);

  if( readDuid(g_duid) ){
    Serial.print("Device UID: ");
    for ( int i = 0; i <= 16; i++ ){
      Serial.print(g_duid[i],HEX);
    }
    Serial.println();
  }else{
    Serial.println("<WARNING> No Device UID found in EEPROM");
  }

  EEPROM.end();
}

