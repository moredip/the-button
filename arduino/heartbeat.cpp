#include "heartbeat.h"

const long HEARTBEAT_INTERVAL = 10000; // 10 seconds

Heartbeat::Heartbeat(const String &deviceUid)
  : _deviceUid(deviceUid)
  , _lastHeartbeat(0)
{}

void Heartbeat::takeTurn(long now)
{
  if( now - _lastHeartbeat < HEARTBEAT_INTERVAL ){
    return;
  }
  
  sendHeartbeat();

  _lastHeartbeat = now;
}

void Heartbeat::sendHeartbeat(){
  _httpClient.begin("http://phone-me.herokuapp.com/device/heartbeat");

  int httpCode = _httpClient.POST(_deviceUid);
  _httpClient.end();
   
  // httpCode will be negative on error
  if(httpCode <= 0) {
    Serial.printf("[Heartbeat] <ERROR> POST failed, error: %s\n", _httpClient.errorToString(httpCode).c_str());
  }
}

