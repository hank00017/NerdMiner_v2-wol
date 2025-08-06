#include <WiFiUdp.h>
#include <WebServer.h>
#include <ESP32Ping.h>
#include <HTTPClient.h>
#include "wol.h"


// List of WOL devices: {"Name", "MAC", "Broadcast IP"}
wolDevice devices[] = {
  {"Device1", "AA:BB:CC:DD:EE:FF", "192.168.1.255"},
};

// UDP instance for sending WOL packets
WiFiUDP udp;
WebServer server(80);

void sendWOLPacket(const byte* macAddress) {
  byte magicPacket[102];
  // create the magic packet
  for (int i = 0; i < 6; i++) {
    magicPacket[i] = 0xFF;
  }
  for (int i = 1; i <= 16; i++) {
    for (int j = 0; j < 6; j++) {
      magicPacket[i * 6 + j] = macAddress[j];
    }
  }
  // send the magic packet
  udp.beginPacket("255.255.255.255", wolPort);
  udp.write(magicPacket, sizeof(magicPacket));
  udp.endPacket();
}

//create a webpage 
void handleRoot() {
    String html = "<html><body><h1>WOL</h1>";
    server.send(200, "text/html", html);
}

void startWOLServer() {
  udp.begin(wolPort);
  server.on("/", handleRoot);
  server.begin();
}

void handleWOLClient() {
  server.handleClient(); // Handle incoming requests
}