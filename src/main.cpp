#include <Arduino.h>

#include "./ENC.h"

void setup() {
    Serial.begin(115200);
}

void loop() {
    for (int i = 0; i < 4; i++) {
        enc[i].calcVelocity();
        printf("%d\t%d\t", enc[i].returnPosition(), enc[i].returnVelocity());
    }
    printf("\n");

    delay(10);
}