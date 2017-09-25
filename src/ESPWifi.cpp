#include "ESPWifi.h"
ESPWifi::ESPWifi(int pn) : Sensor (pn){}

int ESPWifi::init(){
    Sensor::sWrite("\n");
    WiFi.begin();
}

void ESPWifi::loop(){

}

ESPWifi::~ESPWifi(){}