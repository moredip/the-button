#include "serverGateway.h"

/*
#define SERVER_HOST ("192.168.0.102")
#define SERVER_PORT (5000)
//*/

//*
#define SERVER_HOST ("an-button.herokuapp.com")
#define SERVER_PORT (80)
//*/


ServerGateway::ServerGateway(const String &deviceUid)
  : _deviceUid(deviceUid)
{}

void ServerGateway::sendHeartbeat(){
  Serial.print("[ServerGateway] sending heartbeat for "); Serial.println(_deviceUid);
  postDeviceUIdTo("/device/heartbeat");
}

void ServerGateway::sendButtonPress(){
  Serial.println("[ServerGateway] sending button press");
  postDeviceUIdTo("/device/button");
}

bool ServerGateway::postDeviceUIdTo(const String &endpoint){
  _httpClient.begin(SERVER_HOST,SERVER_PORT,endpoint);
  _httpClient.addHeader("Content-Type","text/plain");

  int httpCode = _httpClient.POST(_deviceUid);
  _httpClient.end();
   
  // httpCode will be negative on error
  if(httpCode <= 0) {
    Serial.printf(
      "[ServerGateway] <ERROR> POST to %s failed, error: %s\n", 
      endpoint.c_str(), 
      _httpClient.errorToString(httpCode).c_str()
    );
  }
}
