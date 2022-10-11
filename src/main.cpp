#include <Arduino.h>

#include "./ENC.h"

void setup() {
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < 4; i++) {
        printf("%d\t", enc[i].returnPosition());
    }
    printf("\n");

    delay(10);
}