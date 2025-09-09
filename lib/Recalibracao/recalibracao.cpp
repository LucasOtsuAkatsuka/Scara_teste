#include "recalibracao.h"

void Recalibracao::begin(int pinSwitch) {
    _pinSwitch = pinSwitch;    
    pinMode(_pinSwitch, INPUT_PULLUP);
}

bool Recalibracao::recalibrar(Cinematica* braco) {
    Serial.println("iniciando recalibracao");
    braco->goToXY(445, 0);

    if (digitalRead(_pinSwitch) == LOW)
    {
        braco_1_recalibrado = true;
        Serial.println("braco 1 recalibrado");
        braco_2_recalibrado = true;
        Serial.println("braco 2 recalibrado");
    }
    
    while (!(braco_1_recalibrado && braco_2_recalibrado))
    {
        braco->moveSteps(1, -8);
        braco->moveSteps(2, -8);
        if(digitalRead(_pinSwitch) == LOW)
        {
            braco_1_recalibrado = true;
            braco_2_recalibrado = true;
            Serial.println("braco 1 recalibrado");
            Serial.println("braco 2 recalibrado");
        }

        if(digitalRead(_pinSwitch) == LOW){
            Serial.println("braco 2 recalibrado");
            braco_2_recalibrado = true;
            Serial.println("recalibrando...");
        }
        Serial.println("recalibrando...");
    }
    

    braco->setOrigin();
    Serial.println("recalibracao concluida");
    braco_1_recalibrado = false;
    braco_2_recalibrado = false;
    return true;

}