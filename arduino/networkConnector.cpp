#include "networkConnector.h"

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "vendor/WiFiManager/WifiManager.h"

#include "stateMachine.h"

NetworkConnector::NetworkConnector(StateMachine &stateMachine)
  :_stateMachine(stateMachine)
{
}

void NetworkConnector::BLOCKING_connectToNetwork()
{
  WiFiManager wifiManager;

  _stateMachine.onConnectingToNetwork();
  
  if( wifiManager.autoConnect("the button") ){
    _stateMachine.onConnectedToNetwork();
  }else{
    _stateMachine.onFailedToConnectToNetwork();
  }
}
