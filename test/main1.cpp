#include <Arduino.h>
#include "Garra.h"
#include "Cinematica.h"
#include "recalibracao.h"
#include "infravermelho.h"



// #define DEF_DIR11  20
// #define DEF_STEP11 21
#define DEF_DIR11  3
#define DEF_STEP11 2
#define DEF_DIR12  5
#define DEF_STEP12 4
#define DEF_EN    8
#define pinSw_1 32
//#define pinSw_2 34
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
 String estado = "inicio";
 bool cicloFinalizado = false;

void setup() {
    delay(10000);
   Serial.begin(9600);
   garraAF.begin(pinControlServo_1, pinTRIG, pinECHO, 1);
   garraSD.begin(pinControlServo_2, pinTRIG, pinECHO, 2);
   braco1.begin(true);
   sensorCaneta.begin(pinSensorCaneta);
   recalibracao.begin(pinSw_1);

//    Serial.println("#####################");
//    Serial.println("Braco Scara Iniciado!");
//    Serial.println("#####################");

   

//    pinMode(botao1, INPUT_PULLUP);
//    pinMode(botao2, INPUT_PULLUP);
garraAF.abrir(true);
    delay(1000);
garraAF.fechar(true);
    delay(1000);
garraSD.subir(true);
    delay(1000);
garraSD.descer(true);
    delay(1000);

   Serial.println("ArduinoOK1");
}

void loop()
{

     Serial.println("ArduinoOK1");

    // if(!sensorCaneta.detected())
    // {
    //     long start = millis();
    //     while(!sensorCaneta.detected())
    //     {
    //         if(millis() - start > 1500)
    //         {
    //             Serial.println("SensorCaneta0");
    //             Serial.println("ArduinoOK0");
    //             break;
    //         }
    //     }
    // }
    // else
    // {
    //     Serial.println("SensorCaneta1");
    //     Serial.println("ArduinoOK1");
    // }
    if(sensorCaneta.detected())
    {
        Serial.println("SensorCaneta1");
    } 

    if(Serial.available() > 0)
    {
        command = Serial.readStringUntil('\n');
        command.trim();
    }

    if(command == "MoveBraco2")
    // if(command == "MotorOmbro2")
    {
        Serial.println("MovendoBraco2");
        braco1.moveSteps(2, 13333);
        braco1.moveSteps(1, 5000);
        Serial.println("BracoEmPosicao2");
        command = "default";
    }
    else if(command == "MotorGarra1")
    {
        Serial.println("MovendoGarra1");
        garraAF.fechar(true);
        command = "default";
    }
    else if(command == "MotorAlavanca1")
    {
        Serial.println("MovendoAlavanca1");
        garraSD.subir(true);
        command = "default";
    }
    else if(command == "MoveBraco3")
    {
        Serial.println("MovendoBraco3");
        braco1.moveSteps(2, 13333);
        braco1.moveSteps(1, 5000);
        Serial.println("BracoEmPosicao3");
        command = "default";
    }
    else if(command == "MotorAlavanca2")
    {
        Serial.println("MovendoAlavanca2");
        garraSD.descer(true);
        command = "default";
    }
    else if(command == "MotorGarra2")
    {
        Serial.println("MovendoGarra2");
        garraAF.abrir(true);
        command = "default";
    }
    else if(command == "MoveBraco1")
    {
        Serial.println("MovendoBraco1");
        braco1.moveSteps(2, 13333);
        braco1.moveSteps(1, 5000);
        Serial.println("BracoEmPosicao1");
        command = "default";
        //estado = "recalibrar";

    }

    else if(estado == "recalibrar")
    {
         if(recalibracao.recalibrar(&braco1))
        {
            Serial.println("BracoEmPosicao1");
            command = "default";
            estado = "iddle";
        }
    }

    else if(garraAF.distancia() < 3.00)
    {
        Serial.println("SensorPresenca1");
        //estado = "iddle";
    }
    delay(500);
    
}