#include <WiFiUdp.h>
#include <WebServer.h>
#include <ESP32Ping.h>
#include "wol.h"
#include <HTTPClient.h>

// List of WOL devices: {"Name", "MAC", "Broadcast IP", Port}
wolDevice devices[] = {
  {"Device1", "AA:BB:CC:DD:EE:FF", "192.168.1.255", 9 },
};
