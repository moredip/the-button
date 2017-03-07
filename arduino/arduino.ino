#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include "vendor/WiFiManager/WifiManager.h"

#include "duid.h"
#include "heartbeat.h"

DUID g_duid;
Heartbeat *pHeartbeat;

void setup() {
  Serial.begin(115200);
  delay(100); // seems to need a brief pause at boot
  
  loadDuid();

  pHeartbeat = new Heartbeat(duidAsString(g_duid));

  WiFiManager wifiManager;
  wifiManager.autoConnect("the button");
}

void loop() {
  long now = millis();
  pHeartbeat->takeTurn(now);
}

void loadDuid(){
  EEPROM.begin(20);

  if( readDuid(g_duid) ){
    Serial.print("Device UID: ");
    Serial.println(duidAsString(g_duid));
  }else{
    Serial.println("<WARNING> No Device UID found in EEPROM");
  }

  EEPROM.end();
}

