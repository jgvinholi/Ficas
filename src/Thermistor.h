#pragma once
#include "Global_Includes.h"
#include "Sensor.h"

class Thermistor:
    public Sensor
{
private:
    const double VREF = 5;
    const double T0 = 298.15;
    const double BETA_COEFF = 3950; //to confirm
    const double R0 = 10000; //resistance at room temp
    void loop();
    int port;
    double analog_sum;
    double v0;
    double resistance;
    double inverse_temp;
    double temp_c;
public:
    double do_measure();
    Thermistor(int pn);
    ~Thermistor();
};