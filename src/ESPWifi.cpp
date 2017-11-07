#include "ESPWifi.h"
ESPWifi::ESPWifi(int pn) : Sensor(pn){}

int ESPWifi::init(){
    Sensor::sWrite("\n");
    return 1;
}

void ESPWifi::loop(){

}

ESPWifi::~ESPWifi(){}