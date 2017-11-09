#include "Global_Includes.h"
#include "Thermistor.h"

int temp;
const int LED1 = 10; //D12
const int BUZZ = 9; //D11
const int THERM = 0; //A0
Thermistor* therm;
void setup() {
    pinMode(LED1,OUTPUT);
    pinMode(BUZZ,OUTPUT);
    Thermistor* therm = new Thermistor(THERM);
}

void loop() {
    temp = 0;
    for (int i=0; i<10; i++){
        temp+=therm->do_measure();
    }
    temp = temp/10;
    if(temp>40.0){
        therm->sWrite("Catching Fire.\n");
        digitalWrite(LED1,1);
        digitalWrite(BUZZ,1);
        therm->openValve();  
    }
    else{
        therm->sWrite("Everything ok.\n");
        digitalWrite(LED1,0);
        digitalWrite(BUZZ,0);
        therm->closeValve();
    }
    delay(5000);
}