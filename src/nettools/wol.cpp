#include <WiFiUdp.h>
#include <WebServer.h>
#include <ESP32Ping.h>
#include <HTTPClient.h>
#include "wol.h"
#include "wolCSS.h"
#include "wolHOME.h"
#include "wolSetup.h"


// List of WOL devices: {"Name", "MAC", "Broadcast IP"}
wolDevice devices[] = {
  //{"Device1", "0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF", "192.168.1.255"},
  //{"Device2", "0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF", "192.168.1.255"},
  //{"Device3", "0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF", "192.168.1.255"},
  //{"Device4", "0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF", "192.168.1.255"},
};

// calculate the number of devices
const int deviceCount = sizeof(devices) / sizeof(devices[0]);

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



void handleCSS() {
    server.send(200, "text/css", WOL_CSS);
}

//create a webpage 
void handleRoot() {
    String html = String(WOL_HOME_PAGE);

    // Add CSS style to the HTML
    String cssStyle = "<style>";
    cssStyle += WOL_CSS;
    cssStyle += "</style>";
    html.replace("</head>", cssStyle + "</head>");

    // generate device buttons
    String deviceButtons = "";

    for (int i = 0; i < deviceCount; i++) {
        deviceButtons += "<div style='margin: 15px 0;'>";
        deviceButtons += "<button style=\"width: 100%; height: 75px; cursor: pointer;\" "
                 "onclick=\"window.location.href='/wake?device=" + String(i) + "'\">"
                 "Wake " + String(devices[i].name) +
                 "</button>";
        deviceButtons += "</div>";
    }

    // If no devices are configured, show a first-time setup message
    if (deviceCount == 0) {
        handleSetup(); // Redirect to setup page
        return;
    }

    // Replace placeholders
    html.replace("{{DEVICE_BUTTONS}}", deviceButtons);
    server.send(200, "text/html", html);
}


void handleSetup() { 
  String html = String(WOL_SETUP_PAGE);
  // Add CSS style to the HTML
  String cssStyle = "<style>";
  cssStyle += WOL_CSS;
  cssStyle += "</style>";
  html.replace("</head>", cssStyle + "</head>");
  server.send(200,"text/html", html); 
}

// Features to be added
/*

bool isOnline(const String& ip) {
    return Ping.ping(ip.c_str());
}

void handleStatus() {
    
}

*/






void startWOLServer() {
  udp.begin(wolPort);
  server.on("/", handleRoot);
  server.on("/style.css", handleCSS);  // 添加 CSS 路由
  server.begin();
}

void handleWOLClient() {
  server.handleClient(); // Handle incoming requests
}
