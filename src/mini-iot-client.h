#ifndef MINIIOTCLIENT_H
#define MINIIOTCLIENT_H

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

class MiniIotClient {
 private:
  const char* clientHostName;
  const char* serverHostName;
  const char* wifiSsid;
  const char* wifiPass;
  uint16_t wifiWaitDelay;
  Stream* debugStream;

  int postData(String filename, String payload, boolean append, boolean tsprefix);

 public:
  MiniIotClient(const char* clientHostName, const char* serverHostName, const char* wifiSsid, const char* wifiPass);
  void setWifiWaitDelay(uint16_t delay);
  void setDebugStream(Stream * stream);

  void connectToWifi();
  void checkWifi();
  void disableWifi();

  int save(String filename, String data);
  int saveWithTimestamp(String filename, String data);

  int append(String filename, String line);
  int appendWithTimestamp(String filename, String line);
};

#endif