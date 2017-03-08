#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include "vendor/WiFiManager/WifiManager.h"

#include "main.h"

Main main;

void setup() {
  Serial.begin(115200);
  delay(100); // seems to need a brief pause at boot

  main.setup();
  
  WiFiManager wifiManager;
  wifiManager.autoConnect("the button");
}

void loop() {
  main.loop();
}
