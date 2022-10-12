//.hと.cppを分けるのがめんどかった

#include <Arduino.h>

class ENC {
   public:
    ENC(int A, int B);

    long returnPosition(void);
    // int returnVelocity(void);

    void counter(void);
    // void calcVelocity(void);

    const uint16_t dt = 5;

   private:
    int A_pin;
    int B_pin;

    bool _val;

    long _position = 0;
    int _velocity  = 0;
};

ENC enc[] = {{A0, A1}, {7, 8}, {5, 4}, {14, 15}};

void ENC_check(void);

void ENC::counter(void) {
    if (digitalRead(A_pin) != _val) {
        _val = !_val;
        if (_val ^ digitalRead(B_pin)) {
            _position++;
        } else {
            _position--;
        }
    }
}

long ENC::returnPosition(void) {
    return this->_position;
}

// int ENC::returnVelocity(void) {
//     return this->_velocity;
// }

// void ENC::calcVelocity(void) {
//     //✨👉😁👈✨
// }

ENC::ENC(int A, int B) {
    A_pin = A;
    B_pin = B;

    pinMode(A_pin, INPUT);
    pinMode(B_pin, INPUT);

    attachInterrupt(digitalPinToInterrupt(A_pin), ENC_check, CHANGE);
}

//  非メンバ関数

void ENC_check(void) {
    for (int i = 0; i < 4; i++) {
        enc[i].counter();
    }
}