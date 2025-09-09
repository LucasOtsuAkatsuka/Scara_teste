#ifndef RECALIBRACAO_H
#define RECALIBRACAO_H

//#define pinSw_2 6

#include "Cinematica.h"
#include <Arduino.h>
class Recalibracao {
public:
    void begin(int pinSwitch);
    bool recalibrar(Cinematica* braco);
private:
    int _pinSwitch; // <-- guarda o número do pino
    bool braco_1_recalibrado = false;
    bool braco_2_recalibrado = false;
};
#endif
