#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
  private:
        int Trig_Pin;
        int Echo_Pin;
      
  public:
  UltrasonicSensor(int trig, int echo);
  int getDistance();
  
};

#endif