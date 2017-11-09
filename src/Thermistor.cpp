#include "Thermistor.h"
#define VALVE 12
#include <string.h>


Thermistor::Thermistor(int pn) : Sensor(pn){
    port = pn;
    pinMode(VALVE,OUTPUT);
}

double Thermistor::do_measure(){
    loop();
    return temp_c;
}

void Thermistor::loop(){
    for(int i = 0; i<10; i++){
        analog_sum+=analogRead(port);
        delay(10);
    }
    v0 = (analog_sum/10)*VREF/1023; // = Vref*R/(R+10K) 
    resistance = 20000*v0/(VREF-v0);
    inverse_temp = 1/T0 + 1/BETA_COEFF*log(resistance/R0);
    temp_c = 1/inverse_temp - 273.15;
    String Temp_C(analogRead(port));
    sWrite(Temp_C.c_str());
    sWrite("\n");
}

void Thermistor::openValve(){
    digitalWrite(VALVE,1);
    sWrite("Válvula aberta. \n");
}

void Thermistor::closeValve(){
    digitalWrite(VALVE,0);
    sWrite("Válvula fechada. \n");
}

Thermistor::~Thermistor(){}