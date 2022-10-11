#include <Arduino.h>

#include "./ENC.h"

ENC channel1(A0, A1);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println(channel1.returnPosition());
    delay(10);
}