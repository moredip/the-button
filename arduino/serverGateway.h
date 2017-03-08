#include <ESP8266HTTPClient.h>

#pragma once

class ServerGateway {
  public:
    ServerGateway(const String &deviceUid);

    void sendHeartbeat();
    void sendButtonPress();

  private:   

    bool postDeviceUIdTo(const String &endpoint);

    HTTPClient _httpClient;
    String _deviceUid;
};
