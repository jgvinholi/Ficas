#include "Thermistor.h"
Thermistor::Thermistor(int pn) : Sensor(pn){
    port = pn;
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
    resistance = 10000*v0/(VREF-v0);
    inverse_temp = 1/T0 + 1/BETA_COEFF*log(resistance/R0);
    temp_c = 1/inverse_temp - 273.15;
    if(temp_c>40.0){
        sWrite("Catching Fire.\n");
        digitalWrite(LED1,1);
        digitalWrite(BUZZ,1);   
    }
    else{
        sWrite("Everything ok.\n");
        digitalWrite(LED1,0);
        digitalWrite(BUZZ,1);
    }
    delay(5000);
}