#include <Bridge.h>

#include "constants.h"
#include "logger.h"

#include "shiftrConnector.h"
ShiftrConnector shiftrConnector;

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);

  Bridge.begin(); // Yun bridge
  logger->init();

  //setup the IoT platforms
  logger->log("Start setup connection with IoT platform...\n");
  shiftrConnector.init();

  //Everything seems to be ok, let's start !
  logger->log("\nApplicationr up, Let's start to play :) !!!\n");

  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_BLUE, LOW);
}

/**
   Arduino loop...
*/
void loop() {
  //need to refresh shiftr API in order to send and receive new messages
  shiftrConnector.loop();

  

}

void toggleLed(int color) {
  int state = digitalRead(color);
  digitalWrite(color, 1 - state);
}

