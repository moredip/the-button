#include "heartbeat.h"

#include "serverGateway.h"
#include "stateMachine.h"

const long HEARTBEAT_INTERVAL = 10000; // 10 seconds

Heartbeat::Heartbeat(ServerGateway &serverGateway,StateMachine &stateMachine)
  : _serverGateway(serverGateway)
  , _stateMachine(stateMachine)
  , _lastHeartbeat(0)
{}

void Heartbeat::takeTurn(long now)
{
  if( now - _lastHeartbeat < HEARTBEAT_INTERVAL ){
    return;
  }
  
  _stateMachine.onHeartbeat();
  _serverGateway.sendHeartbeat();

  _lastHeartbeat = now;
}
