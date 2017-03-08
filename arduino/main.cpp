#include "Arduino.h"

#include "main.h"

#include "duid.h"
#include "serverGateway.h"
#include "heartbeat.h"
#include "button.h"
#include "buttonReporter.h"

String loadDuid();

Main::Main(){
}

void Main::setup(){
  _duid = loadDuid();
  
  // not bothering to clean these up since we'll be a singleton
  _pServerGateway = new ServerGateway(_duid);
  _pHeartbeat = new Heartbeat(*_pServerGateway);
  _pButtonReporter = new ButtonReporter(*_pServerGateway);
  _pButton = new Button(*_pButtonReporter);
}

void Main::loop() {
  long now = millis();
  _pHeartbeat->takeTurn(now);
  _pButton->takeTurn(now);
}

String loadDuid(){
  DUID duid;

  EEPROM.begin(20);
  bool readSucceeded = readDuid(duid);
  EEPROM.end();

  if( readSucceeded ){
    return duidAsString(duid);
  }else{
    Serial.println("<WARNING> No Device UID found in EEPROM");
    return "UNIDENTIFIED DEVICE";
  }
}
