#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trig, int echo){
    Trig_Pin = trig;
    Echo_Pin = echo;
    pinMode(Trig_Pin, OUTPUT);
    pinMode(Echo_Pin, INPUT);
    
}
int UltrasonicSensor::getDistance(){

    digitalWrite(Trig_Pin,LOW);
    delayMicroseconds(2);
    digitalWrite(Trig_Pin,HIGH);
    delayMicroseconds(10);
    int duration = pulseIn(Echo_Pin, HIGH,30000);
    return duration * 0.034/2;    
 
}

