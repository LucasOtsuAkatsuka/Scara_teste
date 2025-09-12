#include "Garra.h"

void Garra::begin(int pinControl, int pinTrig, int pinEcho, int flag) {
   servo.attach(pinControl);
   
   ultrasonic = Ultrasonic(pinTrig, pinEcho);

   if (flag == 1){
      servo.write(100);
   }else if(flag == 2){
      servo.write(0);
   }
}

void Garra::abrir(bool enable)
{
   if (enable) {
       servo.write(angleOpen);
       Serial.println("abrir garra");
   }
}
void Garra::fechar(bool enable)
{
   if (enable) {
       servo.write(angleClose);
       Serial.println("fechar garra");
   }
}
void Garra::subir(bool enable)
{
   if (enable) {
       servo.write(angleUp);
       Serial.println("subir garra");
   }
}

void Garra::descer(bool enable)
{
   if (enable) {
       servo.write(angleDown);
       Serial.println("descer garra");
   }
}

float Garra::distancia()
{
   _distancia = ultrasonic.read();
   return _distancia;
}