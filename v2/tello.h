#pragma once

// #include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <pgmspace.h>

class Tello {
private:
  WiFiUDP *udpClient;
  String getCommandFromTable(uint8_t index);
  String sendCommand(String command);

public:
  Tello();
  ~Tello();

  bool isConnected;

  void init();

  // auto handled by Tello
  bool takeoff();
  bool land();

  // hardcoded `x` values for now (15cm ~= 6inch)
  // 90 degrees for rotate fns
  bool go_up();
  bool go_down();
  bool move_left();
  bool move_right();
  bool go_forward();
  bool go_back();
  bool turn_right();
  bool turn_left();
};
