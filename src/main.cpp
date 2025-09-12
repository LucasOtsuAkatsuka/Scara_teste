#include <Arduino.h>
#include "Garra.h"
#include "Cinematica.h"
#include "recalibracao.h"



// #define DEF_DIR11  20
// #define DEF_STEP11 21
#define DEF_DIR11  4
#define DEF_STEP11 2
#define DEF_DIR12  5
#define DEF_STEP12 3
#define DEF_EN    8
#define pinSw_1 32
#define pinSw_2 34
//#define DEF_DIR21  16
//#define DEF_STEP21 17
//#define DEF_DIR22  14
//#define DEF_STEP22 15
#define pinControlServo_1 48
#define pinControlServo_2 24
#define botao1 40
#define botao2 42

Garra garraAF;
Garra garraSD;
Cinematica braco1(DEF_STEP11, DEF_DIR11, DEF_STEP12, DEF_DIR12, DEF_EN);
Recalibracao recalibracao;

void setup() {
   Serial.begin(9600);
   garraAF.begin(pinControlServo_1, pinTRIG, pinECHO, 1);
   garraSD.begin(pinControlServo_2, pinTRIG, pinECHO, 2);
   braco1.begin(true);
   recalibracao.begin(pinSw_1);

   Serial.println("#####################");
   Serial.println("Braco Scara Iniciado!");
   Serial.println("#####################");

   delay(2000);


   pinMode(botao1, INPUT_PULLUP);
   pinMode(botao2, INPUT_PULLUP);
   
}

void loop() {
   
   //int botaoPressionado;
//
   //botaoPressionado = 0;
//
   //if (digitalRead(botao1) == LOW) botaoPressionado = 1;
   //else if (digitalRead(botao2) == LOW) botaoPressionado = 2;

   if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    if ((comando == "A1"))
    {
        Serial.println("botao 1 apertado");
        garraAF.abrir(true);
        delay(1000);
        braco1.goToIndex(1);
        delay(1000);
        garraAF.fechar(true);
        delay(1000);
        garraSD.subir(true);
        delay(1000);
        braco1.goToIndex(2);
        delay(1000);
        garraSD.descer(true);
        delay(1000);
        while (garraAF.distancia() > 3.00) {
            Serial.println("Nao ha objeto para soltar");
            delay(500);
        }
        garraAF.abrir(true);
        delay(1000);
        garraAF.fechar(true);
        Serial.println(8);
        comando = "";
    } else if ((comando == "A2"))
    {
        Serial.println("botao 4 apertado");
        recalibracao.recalibrar(&braco1);
        comando = "";
    }else{
        Serial.println("...");
    }
   }

   delay(500);
}