#include "heartbeat.h"

const long HEARTBEAT_INTERVAL = 10000; // 10 seconds

Heartbeat::Heartbeat(ServerGateway &serverGateway)
  : _serverGateway(serverGateway)
  , _lastHeartbeat(0)
{}

void Heartbeat::takeTurn(long now)
{
  if( now - _lastHeartbeat < HEARTBEAT_INTERVAL ){
    return;
  }
  
  _serverGateway.sendHeartbeat();

  _lastHeartbeat = now;
}
