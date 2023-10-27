#include <WiFi.h>
#include <WiFiUdp.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DFRobot_DF2301Q.h"


static const char* SSID PROGMEM = "TELLO-9C5041";
static const char* PASS PROGMEM = "";
static const char* TELLO_IP PROGMEM = "192.168.10.1";
static const int CMD_PORT PROGMEM = 8889;

WiFiUDP udp;
DFRobot_DF2301Q_I2C vrs;

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  Serial.begin(9600);

  // init OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("[error] SSD1306 allocation failed"));
    for (;;)
      ;
  }
  Serial.println(F("[oled] connected"));

  // init VRS
  while (!(vrs.begin())) {
    Serial.println(F("[error] Voice Recognition Sensor (VRS) connection failed"));
    delay(2000);
  }
  Serial.println(F("[vrs] connected"));

  vrs.setVolume(7);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.display();

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("[connecting] wifi"));
    WiFi.mode(WIFI_STA);  // Set the Wi-Fi mode to Station Mode
    WiFi.begin(SSID, PASS);
    delay(10000);
  }
  Serial.println(F("[connected] wifi"));
  Serial.print(F("[wifi] status="));
  Serial.println(WiFi.status());

  udp.begin(CMD_PORT);
  delay(2000);

  sendCommand("command");
}

void loop() {
  delay(1000);

  uint8_t CMDID = vrs.getCMDID();

  switch (CMDID) {
    case 1:
      display.println("R2 INIT");
      display.display();
      break;

    case 5:
      display.println("TAKEOFF");
      display.display();
      sendCommand("takeoff");
      break;

    case 6:
      display.println("LAND");
      display.display();
      sendCommand("land");
      break;

    default:
      if (CMDID != 0) {
        Serial.print(F("CMDID="));
        Serial.println(CMDID);

        display.print(F("CMDID="));
        display.println(String(CMDID));
        display.display();
      }
  }

  display.clearDisplay();
}

void sendCommand(String command) {
  Serial.print(F("[tello] cmd="));
  Serial.println(command);
  udp.beginPacket(TELLO_IP, CMD_PORT);
  udp.write((const unsigned char*)command.c_str(), command.length());
  udp.endPacket();
  delay(500);
}
