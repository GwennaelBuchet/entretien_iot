#include "shiftrConnector.h"

#include <Arduino.h>

#include "logger.h"
#include "constants.h"

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  logger->log("Receiving from Shiftr.io...");
  logger->log(" done. \n");
}

void ShiftrConnector::init()
{
  client.begin("broker.shiftr.io");

  this->connect();

  client.subscribe(SHIFTR_NAMESPACE);
}

void ShiftrConnector::connect() {
  logger->log("\nTry to connect to Shiftr ...");

  while (!client.connect("arduino", SHIFTR_DEVICE_LOGIN, SHIFTR_DEVICE_PWD)) {
    logger->log(".");
    delay(50);
  }

  logger->log(" Done ! \n");
}

void ShiftrConnector::loop()
{
  client.loop();

  if (!client.connected()) {
    connect();
  }
}

void ShiftrConnector::sendMessage(String sender, int color)
{
  logger->log("Sending to Shiftr...");

  String msg = "{\"toggle\" : " + String(color) + "}";

  client.publish(SHIFTR_NAMESPACE, msg);
  logger->log(" done. \n");
}
