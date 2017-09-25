#pragma once
#include <ESP8266WiFi.h>
#include "Global_Includes.h"
#include "Sensor.h"

class ESPWifi:
    public Sensor
{
private:
    void loop();
public:
    int init();
    ESPWifi(int pn);
    ~ESPWifi();
}