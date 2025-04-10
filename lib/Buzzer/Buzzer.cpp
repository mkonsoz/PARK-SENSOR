#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) {
    buzzerPin = pin;
}

void Buzzer::begin() {
    pinMode(buzzerPin, OUTPUT);
    digitalWrite(buzzerPin, LOW);
}

void Buzzer::beepOnce(int beepTime) {
    digitalWrite(buzzerPin, HIGH);
    delay(beepTime);
    digitalWrite(buzzerPin, LOW);
}

void Buzzer::beepWithDelay(int beepTime, int delayTime) {
    beepOnce(beepTime);
    delay(delayTime);
}

void Buzzer::stop() {
    digitalWrite(buzzerPin, LOW);
}
