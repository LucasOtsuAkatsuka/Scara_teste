#include "Garra.h"

Garra garra;

void setup() {
    Serial.begin(9600);
    garra.begin(48, pinTRIG, pinECHO, 1);
    Serial.println("Garra Iniciada!");
    delay(2000);
}
void loop() {
    Serial.print("Distancia: ");
    Serial.print(garra.distancia());
    Serial.println(" cm");
    delay(500);
}