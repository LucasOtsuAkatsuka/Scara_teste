#include "infravermelho.h"

void Infravermelho::begin(int pinSensor) 
{
    pinMode(pinSensor, INPUT);
    _pinSensor = pinSensor;
}

bool Infravermelho::detected() {
    return digitalRead(_pinSensor) == LOW;
}