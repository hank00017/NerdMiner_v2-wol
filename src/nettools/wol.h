#ifndef WOL_H
#define WOL_H

#include <WiFiUdp.h>
#include <WebServer.h>
#include <ESP32Ping.h>
#include <HTTPClient.h>

#define wolPort 9  // Default WOL port
struct wolDevice {
  const char* name;
  const char* macAddress;    // MAC address
  const char* ipAddress;     // IP address
};


void sendWOLPacket(const byte* macAddress);

#endif // WOL_H