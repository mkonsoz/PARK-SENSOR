#include "Nextion.h"

Nextion::Nextion(HardwareSerial &serial):serialPort(serial){
    serialPort.begin(9600);
    delay(100);
}

void Nextion::changePage(int pageNumber){
    

    String cmd = "page " + String( pageNumber);
    sendCommand(cmd.c_str());
     

   sendCommand(cmd.c_str());
   
}

 void Nextion::showImage(int id){
    String cmd = "vis " + String(id)+ ",1";
    sendCommand(cmd.c_str());
    delay(20);
}
void Nextion::hideImage(int id){
    String cmd = "vis " + String(id) + ",0";
    sendCommand(cmd.c_str()); 
    delay(20);
    
}
void Nextion::updateDistanceOnDisplay( volatile int mesafe_f, volatile int mesafe_b, volatile int mesafe_l, volatile int mesafe_r){
  String cmd1= "t0.txt=\"" + String(mesafe_f)+ " cm\"";
  sendCommand(cmd1.c_str());
 // delay(20);
  String cmd2= "t1.txt=\""+ String(mesafe_l)+ " cm\"";
  sendCommand(cmd2.c_str());
 // delay(20);
  String cmd3 = "t2.txt=\""+ String(mesafe_b)+ " cm\"";
  sendCommand(cmd3.c_str());
 //  delay(20);
  String cmd4 = "t3.txt=\"" + String(mesafe_r)+ " cm\"";
  sendCommand(cmd4.c_str());
 //  delay(20);
}
void Nextion::sendCommand(const char* cmd){
  Serial2.print(cmd);
  Serial2.write(0xFF);
  Serial2.write(0xFF);
  Serial2.write(0xFF);
  serialPort.flush();
   delay(50);
}
void Nextion::readNextionData(){
  while (Serial2.available()) {
    int data = Serial2.read();
    Serial.print(data, HEX);
    Serial.print(" ");
}
Serial.println();
}
