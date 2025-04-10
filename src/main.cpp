#define RXD2  16
#define TXD2  17


#include <Arduino.h>
#include "UltrasonicSensor.h"
#include "Nextion.h"
#include "Buzzer.h"

Buzzer buzzer_f(15);
Buzzer buzzer_b(2);
Buzzer buzzer_r(4);

Nextion nex(Serial2);
TaskHandle_t SensorTask;
TaskHandle_t PageTask;
TaskHandle_t DisplayTask;
SemaphoreHandle_t xMutex;

int currentPage=0;

volatile int mesafe_f=0;
volatile int mesafe_b=0;
volatile int mesafe_l=0;
volatile int mesafe_r=0;


UltrasonicSensor sensor_f(21, 25);
UltrasonicSensor sensor_b(18, 27);
UltrasonicSensor sensor_l(33, 32);
UltrasonicSensor sensor_r(19, 26);

bool buzzerEnabled_f=true;
bool buzzerEnabled_b=true;
bool buzzerEnabled_l=true;
bool buzzerEnabled_r=true;

void sensorTask(void * parameter){
  while (true)
  {
   if( currentPage==4 || currentPage == 5 || currentPage==6 || currentPage==7 || currentPage==8){    
    mesafe_f = sensor_f.getDistance();
    mesafe_b = sensor_b.getDistance();
    mesafe_l = sensor_l.getDistance();
    mesafe_r = sensor_r.getDistance();
   }    
    
     vTaskDelay(pdMS_TO_TICKS(100));
  }
}
void pageTask(void * parameter){
  while (true)
  {
    
    if(Serial2.available() >=4){
      if(xSemaphoreTake(xMutex, portMAX_DELAY)==pdTRUE){
      int header = Serial2.read();
      int type   = Serial2.read();
      int buttonID = Serial2.read();
      int lastID   = Serial2.read();
       
      if (header != 0x65) {
          Serial.println("buffer temizleniyor!");
          Serial2.flush(); 
          xSemaphoreGive(xMutex);
          continue; 
        }
      Serial.print("Gelen Veri:   ");
      Serial.print(header, HEX); Serial.print(" ");
     
      Serial.print(type, HEX);   Serial.print(" ");
     
      Serial.print(buttonID, HEX); Serial.print(" ");
      Serial.print(lastID, HEX);

        delay(50);
        
        if(header == 0x65 && type==0x00 && buttonID==0x02  && lastID == 0x00){
              nex.changePage(1);
              currentPage=1;
           

       } 
       else if(header == 0x65 && type==0x01 && buttonID==0x02 && lastID == 0x00){
              
              nex.changePage(2);
              currentPage=2;
             
              
       }
       else if(header == 0x65 && type==0x01 && buttonID==0x03 && lastID == 0x00){
              nex.changePage(3);
              currentPage=3;
            
       }
       else if(header == 0x65 && type==0x02 && buttonID==0x02 && lastID == 0x00){
              
              nex.changePage(4);
               for(int i= 2 ; i<=21; i++){
               nex.hideImage(i);
              delay(10);
              }

              currentPage=4;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
       
       }
       else if(header == 0x65 && type==0x02 && buttonID==0x03 && lastID == 0x00){
              nex.changePage(5);
              
               for(int i= 2 ; i<=21; i++){
               nex.hideImage(i);
              delay(10);
              }
              currentPage=5;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
        
       }
       else if(header == 0x65 && type==0x02 && buttonID==0x04 && lastID == 0x00){
              nex.changePage(6);
       
               for(int i= 2 ; i<=21; i++){
               nex.hideImage(i);
               delay(10);
              }
              currentPage=6;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
          
       }
       else if(header == 0x65 && type==0x02 && buttonID==0x05 && lastID == 0x00){
              nex.changePage(7);
              
               for(int i= 2 ; i<=21; i++){
               nex.hideImage(i);
              delay(10);
              }
              currentPage=7;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
      
       }
       else if(header == 0x65 && type==0x02 && buttonID==0x06 && lastID == 0x00){
              nex.changePage(8);
             
               for(int i= 2 ; i<=21; i++){
               nex.hideImage(i);
              delay(10);
              }
              currentPage=8;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
      
       } 
       else if(header == 0x65 && type==0x03 && buttonID==0x02 && lastID == 0x00){
              nex.changePage(4);
       
              currentPage=4;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
      
       }  
       else if(header == 0x65 && type==0x03 && buttonID==0x03 && lastID == 0x00){
              nex.changePage(5);
              currentPage=5;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
       
       }
       else if(header == 0x65 && type==0x03 && buttonID==0x04 && lastID == 0x00){
              nex.changePage(6);
              currentPage=6;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
       
       }
       else if(header == 0x65 && type==0x03 && buttonID==0x05 && lastID == 0x00){
              nex.changePage(7);
              currentPage=7;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
      
       }
       else if(header == 0x65 && type==0x03 && buttonID==0x06 && lastID == 0x00){
              nex.changePage(8);
              currentPage=8;
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
      
       }
       else if(header == 0x65 && type==0x04 && buttonID==0x1A && lastID == 0x00){
             
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              nex.changePage(1);
              currentPage=1;
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
                                     
       }
       else if(header == 0x65 && type==0x05 && buttonID==0x1A && lastID == 0x00){
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
              nex.changePage(1);
              currentPage=1;
      
       }
       else if(header == 0x65 && type==0x06 && buttonID==0x1A && lastID == 0x00){
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
              nex.changePage(1);
              currentPage=1;
       
       }
       else if(header == 0x65 && type==0x07 && buttonID==0x1A && lastID == 0x00){
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
              nex.changePage(1);
              currentPage=1;
       
       }
       else if(header == 0x65 && type==0x08 && buttonID==0x1A && lastID == 0x00){
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
              nex.changePage(1);
              currentPage=1;
       }
        else if(header == 0x65 && type==0x04 && buttonID==0x1C && lastID == 0x00){
               buzzer_f.stop();
               buzzer_b.stop();
               buzzer_r.stop();
               nex.hideImage(28);
               buzzerEnabled_f=false;
               buzzerEnabled_b=false;
               buzzerEnabled_l=false;
               buzzerEnabled_r=false;
       }
       else if(header == 0x65 && type==0x04 && buttonID==0x1B && lastID == 0x00){
               nex.showImage(28);
               buzzerEnabled_f=true;
       }
       else if(header == 0x65 && type==0x05 && buttonID==0x1C && lastID == 0x00){
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              nex.hideImage(28);
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
      }
      else if(header == 0x65 && type==0x05 && buttonID==0x1B && lastID == 0x00){
             nex.showImage(28);
             buzzerEnabled_f=true;
             buzzerEnabled_b=true;
             buzzerEnabled_l=true;
             buzzerEnabled_r=true;
      }
      else if(header == 0x65 && type==0x06 && buttonID==0x1C && lastID == 0x00){
                buzzer_f.stop();
               buzzer_b.stop();
               buzzer_r.stop();
               nex.hideImage(28);
               buzzerEnabled_f=false;
               buzzerEnabled_b=false;
               buzzerEnabled_l=false;
               buzzerEnabled_r=false;
       }
       else if(header == 0x65 && type==0x06 && buttonID==0x1B && lastID == 0x00){
       nex.showImage(28);
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
      }   else if(header == 0x65 && type==0x07 && buttonID==0x1C && lastID == 0x00){
               buzzer_f.stop();
               buzzer_b.stop();
               buzzer_r.stop();
               nex.hideImage(28);
               buzzerEnabled_f=false;
               buzzerEnabled_b=false;
               buzzerEnabled_l=false;
               buzzerEnabled_r=false;
       }
       else if(header == 0x65 && type==0x07 && buttonID==0x1B && lastID == 0x00){
              nex.showImage(28);
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
       }
       else if(header == 0x65 && type==0x08 && buttonID==0x1C && lastID == 0x00){
              buzzer_f.stop();
              buzzer_b.stop();
              buzzer_r.stop();
              nex.hideImage(28);
              buzzerEnabled_f=false;
              buzzerEnabled_b=false;
              buzzerEnabled_l=false;
              buzzerEnabled_r=false;
       }
       else if(header == 0x65 && type==0x08 && buttonID==0x1B && lastID == 0x00){
              nex.showImage(28);
              buzzerEnabled_f=true;
              buzzerEnabled_b=true;
              buzzerEnabled_l=true;
              buzzerEnabled_r=true;
       }
       
            nex.readNextionData();
            xSemaphoreGive(xMutex);
          } 
       }
           
        
      vTaskDelay(pdMS_TO_TICKS(10));
   }     
  }
  





void displayTask(void * parameter){
       
  while (true)
  {
    
          

    nex.updateDistanceOnDisplay(mesafe_f,mesafe_l,mesafe_b,mesafe_r);
    
   

    if (mesafe_f > 65) { 
            buzzer_f.stop();
            nex.hideImage(12);  
            nex.hideImage(13);
            nex.hideImage(14);
            nex.hideImage(15);
            nex.hideImage(16);
         
     }
 
    else if (mesafe_f > 55 && mesafe_f <= 65) {
       if (buzzerEnabled_f) buzzer_f.beepWithDelay(100, 300);
            nex.showImage(12);  
            nex.hideImage(13);
            nex.hideImage(14);
            nex.hideImage(15);
            nex.hideImage(16);
         
     } 
     else if (mesafe_f > 45 && mesafe_f <= 55) {
       if (buzzerEnabled_f)buzzer_f.beepWithDelay(100,200);
            nex.showImage(12);  
            nex.showImage(13);
            nex.hideImage(14);
            nex.hideImage(15);
            nex.hideImage(16);
         
         
     } 
     else if (mesafe_f>38 && mesafe_f<=45) {
       if (buzzerEnabled_f)buzzer_f.beepWithDelay(60,50);
            nex.showImage(12);  
            nex.showImage(13);
            nex.showImage(14);
            nex.hideImage(15);
            nex.hideImage(16);
     }
     else if (mesafe_f>30 && mesafe_f<=38) {
       if (buzzerEnabled_f) buzzer_f.beepWithDelay(30,20);
            nex.showImage(12);  
            nex.showImage(13);
            nex.showImage(14);
            nex.showImage(15);
            nex.hideImage(16);
     }
     else if (mesafe_f>20 && mesafe_f<=30) {
      
       if (buzzerEnabled_f)buzzer_f.beepOnce(5000);
            nex.showImage(12);  
            nex.showImage(13);
            nex.showImage(14);
            nex.showImage(15);
            nex.showImage(16);
     }
     //***************************************************************************
     if (mesafe_b > 65) {
            buzzer_b.stop();
            nex.hideImage(7);  
            nex.hideImage(8);
            nex.hideImage(9);
            nex.hideImage(10);
            nex.hideImage(11);
         
        
     }
 
    else if (mesafe_b > 55 && mesafe_b <= 65) {
       if (buzzerEnabled_b) buzzer_b.beepWithDelay(100, 300);
            nex.showImage(7);  
            nex.hideImage(8);
            nex.hideImage(9);
            nex.hideImage(10);
            nex.hideImage(11);
     } 
     else if (mesafe_b > 45 && mesafe_b <= 55) {
       if (buzzerEnabled_b) buzzer_b.beepWithDelay(100, 200);
            nex.showImage(7);  
            nex.showImage(8);
            nex.hideImage(9);
            nex.hideImage(10);
            nex.hideImage(11);
     } 
     else if (mesafe_b>38 && mesafe_b<=45) {
       if (buzzerEnabled_b) buzzer_b.beepWithDelay(60, 50);
            nex.showImage(7);  
            nex.showImage(8);
            nex.showImage(9);
            nex.hideImage(10);
            nex.hideImage(11);
     }
      else if (mesafe_b>30 && mesafe_b<=38) {
       if (buzzerEnabled_b) buzzer_b.beepWithDelay(30, 20);
            nex.showImage(7);  
            nex.showImage(8);
            nex.showImage(9);
            nex.showImage(10);
            nex.hideImage(11);
     }
     else if (mesafe_b>20 && mesafe_b<=30) {
       if (buzzerEnabled_b) buzzer_b.beepOnce(5000);
            nex.showImage(7);  
            nex.showImage(8);
            nex.showImage(9);
            nex.showImage(10);
            nex.showImage(11);
        }
       //****************************************************************
   if (mesafe_l > 65) {
            
            nex.hideImage(17);  
            nex.hideImage(18);
            nex.hideImage(19);
            nex.hideImage(20);  
            nex.hideImage(21);

            
     }
 
    else if (mesafe_l > 55 && mesafe_l <= 65) {
            nex.showImage(17);  
            nex.hideImage(18);
            nex.hideImage(19);
            nex.hideImage(20);  
            nex.hideImage(21);
     } 
     else if (mesafe_l > 45 && mesafe_l <= 55) {
            nex.showImage(17);  
            nex.showImage(18);
            nex.hideImage(19);  
            nex.hideImage(20);  
            nex.hideImage(21);
     }
     else if (mesafe_l>38 && mesafe_l<=45)  {
            nex.showImage(17);  
            nex.showImage(18);
            nex.showImage(19);
            nex.hideImage(20);  
            nex.hideImage(21);
}
    else if (mesafe_l>30 && mesafe_l<=38)  {
           nex.showImage(17);  
           nex.showImage(18);
           nex.showImage(19);
           nex.showImage(20);  
           nex.hideImage(21);
}
       else if (mesafe_l>20 && mesafe_l<=30){
           nex.showImage(17);  
           nex.showImage(18);
           nex.showImage(19);
           nex.showImage(20);  
           nex.showImage(21);
} 
     //*******************************************************
   if (mesafe_r > 65) {
            buzzer_r.stop();
            nex.hideImage(2);
            nex.hideImage(3);
            nex.hideImage(4);
            nex.hideImage(5);  
            nex.hideImage(6);   
     }
 
    else if (mesafe_r > 55 && mesafe_r <= 65) {
       if (buzzerEnabled_r) buzzer_r.beepWithDelay(100, 300);
            nex.showImage(2);
            nex.hideImage(3);
            nex.hideImage(4);
            nex.hideImage(5);  
            nex.hideImage(6);  
           
     } 
    
     else if (mesafe_r > 45 && mesafe_r <= 55) {
       if (buzzerEnabled_r) buzzer_r.beepWithDelay(100, 200);
            nex.showImage(2);
            nex.showImage(3);
            nex.hideImage(4);
            nex.hideImage(5);  
            nex.hideImage(6); 
     } 
     else if (mesafe_r>38 && mesafe_r<=45) {
       if (buzzerEnabled_r) buzzer_r.beepWithDelay(60, 50);
            nex.showImage(2);
            nex.showImage(3);
            nex.showImage(4);
            nex.hideImage(5);  
            nex.hideImage(6); 
     }  
     else if (mesafe_r>30 && mesafe_r<=38) {
       if (buzzerEnabled_r) buzzer_r.beepWithDelay(30, 20);
            nex.showImage(2);
            nex.showImage(3);
            nex.showImage(4);
            nex.showImage(5);  
            nex.hideImage(6); 
     }  
     else if (mesafe_r>20 && mesafe_r<=30) {
       if (buzzerEnabled_r) buzzer_r.beepOnce(5000);
            nex.showImage(2);
            nex.showImage(3);
            nex.showImage(4);
            nex.showImage(5);  
            nex.showImage(6); 
     }  
//    }   
     vTaskDelay(pdMS_TO_TICKS(50)); 
  }
}
  


void setup() {
 Serial.begin(9600);
 Serial2.begin(9600,SERIAL_8N1,16,17);
 xMutex = xSemaphoreCreateMutex();

  if (xMutex == NULL) {
    Serial.println("HATA: Mutex oluşturulamadı! Bellek yetersiz olabilir.");
    while (1); 
  }
 
 Serial.println("Mutex başarıyla oluşturuldu!");
  
 currentPage=0;
 nex.changePage(0);
 delay(100);
 buzzer_f.begin();
 buzzer_b.begin();
 buzzer_r.begin();
 
 nex.updateDistanceOnDisplay(0,0,0,0);
  xTaskCreatePinnedToCore(
    sensorTask,
    "SensorTask", 
    4096,
    NULL,
    1,
    NULL,
    0
    );
  xTaskCreatePinnedToCore(
    pageTask,
   "PageTask", 
    4096,
    NULL,
    1,
    NULL,
    1
   );
   xTaskCreatePinnedToCore(
    displayTask,
   "DisplayTask", 
    4096,
    NULL,
    1,
    NULL,
    0
   );

}

void loop() {
 // vTaskDelay(pdMS_TO_TICKS(1000));
}

