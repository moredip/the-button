#include "duid.h"

#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include "vendor/WiFiManager/WifiManager.h"

DUID g_duid;

void setup() {
  Serial.begin(9600);
  
  loadDuid();

  WiFiManager wifiManager;
  wifiManager.autoConnect("the button");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void loadDuid(){
  EEPROM.begin(20);

  if( readDuid(g_duid) ){
    Serial.print("Device UID: ");
    for ( int i = 0; i <= 16; i++ ){
      Serial.print(g_duid[i],HEX);
    }
    Serial.println();
  }else{
    Serial.println("<WARNING> No Device UID found in EEPROM");
  }

  EEPROM.end();
}

