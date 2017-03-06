#pragma once

#include <Arduino.h>

//https://github.com/256dpi/arduino-mqtt
#include <YunMQTTClient.h>

class ShiftrConnector {

  public :
    void sendMessage(int color);

    void init();

    void loop();

    //default constructor
    ShiftrConnector() {};

  private :
    YunMQTTClient client;

    void connect();
};

