#include <WiFiUdp.h>
#include <WebServer.h>
#include <ESP32Ping.h>
#include <HTTPClient.h>
#include "wol.h"
#include "wolHTML.h"


// List of WOL devices: {"Name", "MAC", "Broadcast IP"}
wolDevice devices[] = {
  {"Device1", "AA:BB:CC:DD:EE:FF", "192.168.1.255"},
  {"Device2", "AA:BB:CC:DD:EE:FF", "192.168.1.255"},
  {"Device3", "AA:BB:CC:DD:EE:FF", "192.168.1.255"},
  {"Device4", "AA:BB:CC:DD:EE:FF", "192.168.1.255"},
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

// 計算設備數量
const int deviceCount = sizeof(devices) / sizeof(devices[0]);

//create a webpage 
void handleRoot() {
    String html = String(WOL_HTML_PAGE);

        // 生成設備按鈕
    String deviceButtons = "";

    for (int i = 0; i < deviceCount; i++) {
        
        deviceButtons += "<div style='margin: 15px 0;'>";
        deviceButtons += "<button style=\"width: 100%; height: 75px; cursor: pointer;\" "
                 "onclick=\"window.location.href='/wake?device=" + String(i) + "'\">"
                 "Wake " + String(devices[i].name) +
                 "</button>";
        deviceButtons += "</div>";
    }
    
    // 如果沒有設備，顯示提示訊息
    if (deviceCount == 0) {
        deviceButtons = "<div style='text-align:center;color:#666;'>No devices configured</div>";
    }

    // 替換佔位符
    html.replace("{{DEVICE_BUTTONS}}", deviceButtons);
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