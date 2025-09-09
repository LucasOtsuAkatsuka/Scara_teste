#ifndef GARRA_H
#define GARRA_H

#define pinECHO 22
#define pinTRIG 23
#define angleOpen 180
#define angleClose 0
#define angleUp 90
#define angleDown 45

#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

class Garra {
public:
    void begin(int pinControl, int pinTrig, int pinEcho);
    void abrir(bool enable);
    void fechar(bool enable);
    void subir(bool enable);
    void descer(bool enable);
    float distancia();

private:
    Servo servo;
    float _distancia;
    long microseg;
    Ultrasonic ultrasonic = Ultrasonic(0, 0);
};

#endif