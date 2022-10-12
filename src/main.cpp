#include <Arduino.h>
// #include <STM32FreeRTOS.h>

// void readEncoderVelocity(void *pvParameters);
// void taskSerial(void *pvParameters);

// TaskHandle_t handle_readEncoderVelocity;
// TaskHandle_t handle_taskSerial;

#include "./ENC.h"

void setup() {
    Serial.begin(9600);

    // xTaskCreate(readEncoderVelocity, "readEncoderVelocity", 128, NULL, 1,
    //             &handle_readEncoderVelocity);
    // xTaskCreate(taskSerial, "taskSerial", 128, NULL, 0, &handle_taskSerial);
    // vTaskStartScheduler();
}

void loop() {
    for (int i = 0; i < 4; i++) {
        printf("%d\t", enc[i].returnPosition());
    }
    printf("\n");

    delay(10);
}

// void taskSerial(void *pvParameters) {
//     for (int i = 0; i < 4; i++) {
//         printf("%d\t", enc[i].returnPosition());
//     }
//     printf("\n");

//     delay(50);
// }

// void readEncoderVelocity(void *pvParameters) {
// }