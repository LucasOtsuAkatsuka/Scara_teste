#include <Arduino.h>
#include "Cinematica.h"


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

Cinematica braco1(DEF_STEP11, DEF_DIR11, DEF_STEP12, DEF_DIR12, DEF_EN);

int step = 9600;
void setup()
{
    Serial.begin(9600);
    braco1.begin(true);
    Serial.println("#####################");
    Serial.println("Braco Scara Iniciado!");
    Serial.println("#####################");
    delay(5000);
}

void loop()
{
    
    unsigned long start, stop;
    start = millis();
    braco1.moveSteps(2, 13333);
    stop = millis();
    //Serial.print("Tempo decorrido: ");
    Serial.print((stop - start));
    //Serial.println(" s");
    Serial.print(",");
    Serial.print(step);
    Serial.println();
    // step = step + 100;
    delay(500);
    
}
