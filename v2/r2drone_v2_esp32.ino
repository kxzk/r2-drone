#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include "DFRobot_DF2301Q.h"
#include "Tello.h"


DFRobot_DF2301Q_I2C voice;
Tello tello;

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static const char* SSID PROGMEM = "TELLO-9C5041";
static const char* PASS PROGMEM = "";

bool connected = false;


void setup() {
  Serial.begin(9600);

  initOLED();
  initVoice();
  initWIFI();
}

void loop() {
  delay(1000);

  uint8_t CMDID = voice.getCMDID();

  if (CMDID != 0) {
    Serial.print(F("CMDID="));
    Serial.println(CMDID);
  }

  switch (CMDID) {
    case 1:
      displayMessage(F("R2 INIT"));
      if (!connected) {
        tello.init();
        if (tello.isConnected) {
          connected = true;
        }
      }
      break;

    case 5:
      displayMessage(F("TAKEOFF"));
      tello.takeoff();
      break;

    case 6:
      displayMessage(F("LAND"));
      tello.land();
      break;

    case 7:
      displayMessage(F("GO UP"));
      tello.go_up();
      break;

    case 8:
      displayMessage(F("MOVE LEFT"));
      tello.move_left();
      break;

    case 9:
      displayMessage(F("GO DOWN"));
      tello.go_down();
      break;

    case 10:
      displayMessage(F("MOVE RIGHT"));
      tello.move_right();
      break;

    case 11:
      displayMessage(F("GO FORWARD"));
      tello.go_forward();
      break;

    case 12:
      displayMessage(F("GO BACK"));
      tello.go_back();
      break;

    case 13:
      displayMessage(F("TURN RIGHT"));
      tello.turn_right();
      break;

    case 14:
      displayMessage(F("TURN LEFT"));
      tello.turn_left();
      break;

    default:
      displayMessage(String(CMDID));
  }
}

void initOLED() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("[error] oled display failed"));
    for (;;)
      ;
  }
  Serial.println(F("[info] oled connected"));

  display.display();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println(F("R2 ONLINE"));
  display.display();
}

void initVoice() {
  while (!(voice.begin())) {
    Serial.println(F("[error] voice recognition sensor failed"));
    delay(500);
  }
  Serial.println(F("[info] voice connected"));

  voice.setVolume(7);
}

void initWIFI() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("[info] connecting ~~~ wifi"));
    WiFi.mode(WIFI_STA);  // Set the Wi-Fi mode to Station Mode
    WiFi.begin(SSID, PASS);
    delay(3000);
  }
  Serial.println("[info] connected wifi");
  Serial.print("[info] wifi_status=");
  Serial.println(WiFi.status());
}

void displayMessage(const String& message) {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("CMD");
  display.println(message);
  display.display();
}
