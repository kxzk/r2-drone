#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DFRobot_DF2301Q.h"

// oled --> I2C: 0x3C
// vrs --> I2C: 0x64

DFRobot_DF2301Q_I2C vrs;

// OLED display
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // init OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    //Serial.println(F("[error] SSD1306 allocation failed"));
    for (;;)
      ;
  }
  //Serial.println("[oled] connected");

  // init VRS
  while (!(vrs.begin())) {
    //Serial.println("[error] Voice Recognition Sensor (VRS) connection failed");
    delay(3000);
  }
  //Serial.println("[vrs] connected");

  vrs.setVolume(7);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);

  uint8_t CMDID = vrs.getCMDID();

  switch (CMDID) {
    case 1:
      display.println("R2 INIT");
      display.display();
      Serial.println("command\n");
      break;

    case 5:
      display.println("TAKEOFF");
      display.display();
      Serial.println("takeoff\n");
      break;

    // id -> 76 (turn off the fan)
    case 6:
      display.println("LAND");
      display.display();
      Serial.println("land\n");
      break;

    case 82:
      display.println("RESET");
      display.display();
      Serial.println("reset\n");
      break;

    default:
      if (CMDID != 0) {
        //Serial.print("CMDID=");
        //Serial.println(CMDID);

        display.print("CMDID=");
        display.println(String(CMDID));
        display.display();
      }
  }

  display.clearDisplay();

  delay(300);
}

