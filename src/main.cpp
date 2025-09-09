#include <Arduino.h>
#include "Garra.h"
#include "Cinematica.h"
#include "recalibracao.h"



// #define DEF_DIR11  20
// #define DEF_STEP11 21
#define DEF_DIR11  5
#define DEF_STEP11 2
#define DEF_DIR12  6
#define DEF_STEP12 3
#define DEF_EN    8
#define pinSw_1 32
//#define DEF_DIR21  16
//#define DEF_STEP21 17
//#define DEF_DIR22  14
//#define DEF_STEP22 15
#define pinControlServo_1 24
#define pinControlServo_2 25
#define botao1 30
#define botao2 31

Garra garraAF;
Garra garraSD;
Cinematica braco1(DEF_STEP11, DEF_DIR11, DEF_STEP12, DEF_DIR12, DEF_EN);
Recalibracao recalibracao;

void setup() {
   Serial.begin(9600);
   garraAF.begin(pinControlServo_1, pinTRIG, pinECHO);
   garraSD.begin(pinControlServo_2, pinTRIG, pinECHO);
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
   
   int botaoPressionado;

   botaoPressionado = 0;

   if (digitalRead(botao1) == LOW) botaoPressionado = 1;
   else if (digitalRead(botao2) == LOW) botaoPressionado = 2;

   switch (botaoPressionado) {
       case 1:
           Serial.println("botao 1 apertado");
           braco1.goToIndex(1);
           delay(1000);
           garraAF.abrir(true);
           delay(1000);
           garraSD.descer(true);
           delay(1000);
           garraAF.fechar(true);
           delay(1000);
           garraSD.subir(true);
           delay(1000);
           braco1.goToIndex(2);
           delay(1000);
           while (garraAF.distancia() > 3.00) {
               Serial.println("Nao ha objeto para soltar");
               delay(500);
           }
           garraAF.abrir(true);
           delay(1000);
           garraAF.fechar(true);
           break;
       case 2:
           Serial.println("botao 4 apertado");
           recalibracao.recalibrar(&braco1);
           break;
       default:
           Serial.println("...");
   }

   delay(500);

   //int braco1_comando;
   //int braco2_comando;
   //int garra1_comando;
   //int garra2_comando;
//
   //switch (braco1_comando) {
   //    case 1:
   //        Serial.println("botao 1 apertado");
   //        braco1.goToIndex(1);
   //        break;
   //    case 2:
   //        Serial.println("botao 2 apertado");
   //        braco1.goToIndex(2);           
   //        break;
   //    case 3:
   //        Serial.println("botao 3 apertado");  
   //        braco1.goToIndex(3);
   //        break;
   //    case 4:
   //        Serial.println("botao 4 apertado");  
   //        braco1.goToIndex(4);
   //        break;
   //    case 5:
   //        Serial.println("botao 5 apertado");  
   //        braco1.goToIndex(5);
   //        break;
   //    case 6:
   //        Serial.println("botao 6 apertado");
   //        recalibracao.recalibrar(&braco1);
   //        break;
   //    default:
   //        Serial.println("...");
   //}
//
   //switch (braco2_comando) {
   //    case 1:
   //        Serial.println("botao 1 apertado");
   //        braco2.goToIndex(1);
   //        break;
   //    case 2:
   //        Serial.println("botao 2 apertado");
   //        braco2.goToIndex(2);           
   //        break;
   //    case 3:
   //        Serial.println("botao 3 apertado");
   //        braco2.goToIndex(3);
   //        break;
   //    case 4:
   //        Serial.println("botao 4 apertado");  
   //        braco2.goToIndex(4);
   //        break;
   //    case 5:
   //        Serial.println("botao 5 apertado");
   //        braco2.goToIndex(5);
   //        break;
   //    case 6:
   //        Serial.println("botao 6 apertado");
   //        recalibracao.recalibrar(&braco2);
   //        break;
   //    default:
   //        Serial.println("...");
   //}
//
   //switch (garra1_comando) {
   //    case 1:
   //        Serial.println("botao 1 apertado");
   //        garra1.abrir(true);
   //        break;
   //    case 2:
   //        Serial.println("botao 2 apertado");
   //        garra1.fechar(true);  
   //        break;
   //    case 3:
   //        Serial.println("botao 3 apertado");  
   //        garra1.descer(true);
   //        break;
   //    case 4:
   //        Serial.println("botao 4 apertado");  
   //        garra1.subir(true);
   //        break;
   //    default:
   //        Serial.println("...");
   //}
//
   //switch (garra2_comando) {
   //    case 1:
   //        Serial.println("botao 1 apertado");
   //        garra2.abrir(true);
   //        break;
   //    case 2:
   //        Serial.println("botao 2 apertado");
   //        garra2.fechar(true);  
   //        break;
   //    case 3:
   //        Serial.println("botao 3 apertado");  
   //        garra2.descer(true);
   //        break;
   //    case 4:
   //        Serial.println("botao 4 apertado");  
   //        garra2.subir(true);
   //        break;
   //    default:
   //        Serial.println("...");
   //}


}