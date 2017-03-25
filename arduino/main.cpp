#include "Arduino.h"

#include "main.h"

#include "duid.h"
#include "networkConnector.h"
#include "stateMachine.h"
#include "serverGateway.h"
#include "heartbeat.h"
#include "button.h"
#include "buttonReporter.h"
#include "led.h"

String loadDuid();

Main::Main(){
}

void Main::setup(){
  _duid = loadDuid();
  
  // not bothering to clean these up since we'll be a singleton
  _pLED = new LED();
  _pStateMachine = new StateMachine(*_pLED);

  _pServerGateway = new ServerGateway(_duid);
  _pHeartbeat = new Heartbeat(*_pServerGateway, *_pStateMachine);
  _pButtonReporter = new ButtonReporter(*_pServerGateway,*_pStateMachine);
  _pButton = new Button(*_pButtonReporter);


  NetworkConnector networkConnector(*_pStateMachine);
  networkConnector.BLOCKING_connectToNetwork();
}

void Main::loop() {
  long now = millis();
  _pHeartbeat->takeTurn(now);
  _pButton->takeTurn(now);
  _pLED->takeTurn(now);
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
