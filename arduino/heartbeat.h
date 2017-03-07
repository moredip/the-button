#include <ESP8266HTTPClient.h>

#pragma once

class Heartbeat {
  public:
    Heartbeat(const String &deviceUid);
    void takeTurn(long now);

  private:
    void sendHeartbeat();
    
    HTTPClient _httpClient;
    String _deviceUid;
    long _lastHeartbeat;
};
