#ifndef INFRAVERMELHO_H
#define INFRAVERMELHO_H

// #define pinSw_2 6

#include "Cinematica.h"
#include <Arduino.h>
class Infravermelho {
public:
    void begin(int pinSensor);
    bool detected();
private:
    int _pinSensor; // <-- guarda o número do pino
    // bool braco_1_recalibrado = false;
    // bool braco_2_recalibrado = false;
};
#endif
