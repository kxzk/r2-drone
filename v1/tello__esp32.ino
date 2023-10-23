#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;

char terminator = '\n';

static const char* SSID = "TELLO-9C5041";
static const char* PASS = "";
static const char* TELLO_IP = "192.168.10.1";
static const int CMD_PORT = 8889;

void setup() {
  Serial.begin(115200);

  Serial0.begin(9600);
}

void loop() {

  while (Serial0.available()) {

    delay(5);

    String cmd = Serial0.readStringUntil(terminator);

    Serial.println(cmd);

    if (cmd == "reset") {
      udp.flush();
      udp.stop();
      WiFi.disconnect(true);
    } else if (cmd == "command") {
      // delete old config
      WiFi.disconnect(true);

      while (WiFi.status() != WL_CONNECTED) {
        Serial.println("[connecting] wifi");
        WiFi.mode(WIFI_STA);  // Set the Wi-Fi mode to Station Mode
        WiFi.begin(SSID, PASS);
        delay(10000);
      }
      Serial.println("[connected] wifi");
      Serial.print("[wifi] status=");
      Serial.println(WiFi.status());

      udp.begin(CMD_PORT);
      delay(2000);

      sendCommand(cmd);
    } else {
      sendCommand(cmd);
    }
  }
}

void sendCommand(String command) {
  Serial.print("[tello] cmd=");
  Serial.println(command);
  udp.beginPacket(TELLO_IP, CMD_PORT);
  udp.write((const unsigned char*)command.c_str(), command.length());
  udp.endPacket();
  delay(1000);
}

