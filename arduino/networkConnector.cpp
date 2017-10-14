#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager#install-through-library-manager

#include "networkConnector.h"

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
