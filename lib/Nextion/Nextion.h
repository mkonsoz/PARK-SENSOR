#ifndef  NEXTION_H
#define  NEXTION_H

#include<Arduino.h>

class Nextion{
public:
    Nextion(HardwareSerial &serial);
    void changePage(int pageNumber);
    void updateDistanceOnDisplay(int mesafe_f, int mesafe_b,int mesafe_l, int mesafe_r);
    void showImage(int id);
    void hideImage(int id);
    void readNextionData();
    
private: 
HardwareSerial &serialPort;
void sendCommand(const char* cmd);

};




#endif