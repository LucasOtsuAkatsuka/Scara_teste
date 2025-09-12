#ifndef GARRA_H
#define GARRA_H

#define pinECHO 9
#define pinTRIG 8
#define angleOpen 10
#define angleClose 100
#define angleUp 45
#define angleDown 0

#include <Arduino.h>
#include <Servo.h>
#include <Ultrasonic.h>

class Garra {
public:
    void begin(int pinControl, int pinTrig, int pinEcho, int flag);
    void abrir(bool enable);
    void fechar(bool enable);
    void subir(bool enable);
    void descer(bool enable);
    float distancia();

private:
    Servo servo;
    float _distancia;
    long microseg;
    int flag;
    Ultrasonic ultrasonic = Ultrasonic(0, 0);
};

#endif