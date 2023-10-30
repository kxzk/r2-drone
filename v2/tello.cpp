#include "Tello.h"

// tello info
static const char *TELLO_IP PROGMEM = "192.168.10.1";
static const int CMD_PORT = 8889;
static const int MAX_RESPONSE_SIZE = 16;

Tello::Tello() { isConnected = false; }

Tello::~Tello() {}

void Tello::init() {
  udpClient = new WiFiUDP();
  Serial.println("[info] connecting ~ udp");
  udpClient->begin(CMD_PORT);
  Serial.println("[info] connected = udp");

  delay(1000);

  String response = sendCommand("command");
  delay(2000);
  Serial.print("[info] sendCommand(`command`)__response=");
  Serial.println(response);

  if (response.equals("ok")) {
    isConnected = true;
  }
}

String Tello::sendCommand(String command) {
  // send command to drone
  udpClient->beginPacket(TELLO_IP, CMD_PORT);
  udpClient->write((const unsigned char *)command.c_str(), command.length());
  udpClient->endPacket();
  Serial.print("[info] sendCommand=");
  Serial.println(command);

  delay(2000);

  // read response back from drone
  char buffer[MAX_RESPONSE_SIZE] = {0};
  if (udpClient->parsePacket() > 0) {
    int n = udpClient->read(buffer, MAX_RESPONSE_SIZE -
                                        1); // leave space for null terminator
    if (n > 0) {
      buffer[n] = '\0';
    }
  }

  return String(buffer);
}

bool Tello::takeoff() {
  String response = sendCommand(F("takeoff"));
  return response.equals("ok");
}

bool Tello::land() {
  String response = sendCommand(F("land"));
  return response.equals("ok");
}

bool Tello::go_up() {
  String response = sendCommand(F("up 15"));
  return response.equals("ok");
}

bool Tello::go_down() {
  String response = sendCommand(F("down 15"));
  return response.equals("ok");
}

bool Tello::move_left() {
  String response = sendCommand(F("left 15"));
  return response.equals("ok");
}

bool Tello::move_right() {
  String response = sendCommand(F("right 15"));
  return response.equals("ok");
}

bool Tello::go_forward() {
  String response = sendCommand(F("forward 15"));
  return response.equals("ok");
}

bool Tello::go_back() {
  String response = sendCommand(F("back 15"));
  return response.equals("ok");
}

bool Tello::turn_right() {
  String response = sendCommand(F("cw 90"));
  return response.equals("ok");
}

bool Tello::turn_left() {
  String response = sendCommand(F("ccw 90"));
  return response.equals("ok");
}
