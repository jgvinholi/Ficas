#include "ESPWifi.h"
ESPWifi::ESPWifi(int pn) : Sensor(pn){}

int ESPWifi::init(){
    Sensor::sWrite("\n");
}

void ESPWifi::loop(){

}

ESPWifi::~ESPWifi(){}