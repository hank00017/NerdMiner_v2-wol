#ifndef WOL_H
#define WOL_H

#include <WiFiUdp.h>
#include <WebServer.h>
#include <ESP32Ping.h>
#include <HTTPClient.h>

struct wolDevice {
  const char* name;
  const char* macAddress;    // MAC address
  const char* ipAddress;     // IP address
  uint16_t port;             // Usually 9 or 7
};


#endif // WOL_H