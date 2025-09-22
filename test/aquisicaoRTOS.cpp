#include <Arduino.h>
#include "Cinematica.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


// Definições de pinos
#define DEF_DIR11  4
#define DEF_STEP11 2
#define DEF_DIR12  16
#define DEF_STEP12 17
#define DEF_EN     8
#define pinSw_1    32
#define pinSw_2    34
#define pinControlServo_1 48
#define pinControlServo_2 24
#define botao1     40
#define botao2     42

// Objeto do braço
Cinematica braco1(DEF_STEP11, DEF_DIR11, DEF_STEP12, DEF_DIR12, DEF_EN);

// Handle da task
TaskHandle_t taskCore1Handle;

void taskCore1(void *pvParameters) {
    unsigned long start, stop;

    for (;;) {
        start = millis();
        //braco1.moveSteps(2, 1600);
        stop = millis();

        Serial.print("Tempo decorrido: ");
        Serial.print((stop - start) / 1000.0);
        Serial.println(" s");

        vTaskDelay(pdMS_TO_TICKS(500)); // delay de 5s (não trava o FreeRTOS)
    }
}

void setup() {
    Serial.begin(115200);
    braco1.begin(true);

    Serial.println("#####################");
    Serial.println("Braco Scara Iniciado!");
    Serial.println("#####################");
    disableCore1WDT();
    // Cria task rodando na CPU1
    xTaskCreatePinnedToCore(
        taskCore1,       // função da task
        "TaskCore1",     // nome da task
        8192,            // tamanho da stack em words
        NULL,            // parâmetro
        1,               // prioridade
        &taskCore1Handle,// handle da task
        1                // core = 1 (CPU1)
    );
}

void loop() {
    // O loop fica livre, pode monitorar botões, etc.
    vTaskDelay(pdMS_TO_TICKS(1000));
}
