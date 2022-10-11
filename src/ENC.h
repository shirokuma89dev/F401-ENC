#include <Arduino.h>

class ENC {
   public:
    ENC(int A, int B);

    long returnPosition(void);

   private:
    int A_pin;
    int B_pin;

    long position = 0;

    void counter(void);
};

void ENC::counter(void) {
    if (digitalRead(A_pin) ^ digitalRead(B_pin)) {
        position++;
    } else {
        position--;
    }
}

long ENC::returnPosition(void) {
    return this->position;
}

ENC::ENC(int A, int B) {
    A_pin = A;
    B_pin = B;

    pinMode(A_pin, INPUT);
    pinMode(B_pin, INPUT);

    attachInterrupt(digitalPinToInterrupt(A_pin), this->counter, CHANGE);
}