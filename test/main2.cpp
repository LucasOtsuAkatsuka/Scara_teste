#include <Arduino.h>
#include "Garra.h"
#include "Cinematica.h"
#include "recalibracao.h"
#include "infravermelho.h"

#define DEF_DIR11  3
#define DEF_STEP11 2
#define DEF_DIR12  5
#define DEF_STEP12 4
#define DEF_EN    8
#define pinSw_1 32

#define pinSensorCaneta 42
//#define DEF_DIR21  16
//#define DEF_STEP21 17
//#define DEF_DIR22  14
//#define DEF_STEP22 15
#define pinControlServo_1 48
#define pinControlServo_2 24
// #define botao1 40
// #define botao2 42
// #define pinInfravermelho 42

Garra garraAF;
Garra garraSD;
Cinematica braco1(DEF_STEP11, DEF_DIR11, DEF_STEP12, DEF_DIR12, DEF_EN);
Recalibracao recalibracao;
Infravermelho sensorCaneta;
String command = "default";

void setup() {
   Serial.begin(9600);
   garraAF.begin(pinControlServo_1, pinTRIG, pinECHO, 1);
   garraSD.begin(pinControlServo_2, pinTRIG, pinECHO, 2);
   braco1.begin(true);
   recalibracao.begin(pinSw_1);

//    Serial.println("#####################");
//    Serial.println("Braco Scara Iniciado!");
//    Serial.println("#####################");

   delay(2000);

   Serial.println("ArduinoOK1");
}

void loop()
{
    if(Serial.available() > 0)
    {
        command = Serial.readStringUntil('\n');
        command.trim();
        //Serial.println(command);
    }
    if(command == "MoveBraco2")
    {
        braco1.moveSteps(2, 13333);
        braco1.moveSteps(1, 5000);
        delay(1000);
        Serial.println("BracoEmPosicao2");
    }
    else if(command == "MoveBraco3")
    {
        braco1.moveSteps(2, 2000);
        braco1.moveSteps(1, 2000);
        delay(1000);
        Serial.println("BracoEmPosicao3");
    }
    else if(command == "MoveBraco1")
    {
        braco1.moveSteps(2, 20000);
        braco1.moveSteps(1, 20000);
        delay(1000);
        Serial.println("BracoEmPosicao1");
    }
}