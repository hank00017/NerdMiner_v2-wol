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


void sendWOLPacket(const byte* macAddress); // Function to send the WOL packet
void startWOLServer(); // Function to start the WOL server
void handleRoot(); // Handles the HTTP request for the homepage and displays the WOL control page
void handleWOLClient(); // Function to handle incoming http requests
void handleSetup(); // Function to handle the setup page for adding devices


#endif // WOL_H
