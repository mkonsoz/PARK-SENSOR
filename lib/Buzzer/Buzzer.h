#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
public:
    Buzzer(uint8_t pin);
    void begin();
    
    void beepOnce(int beepTime = 100);               
    void beepWithDelay(int beepTime, int delayTime); 
    void stop();                                      

private:
    uint8_t buzzerPin;
};

#endif

