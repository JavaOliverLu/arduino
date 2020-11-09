#include "DoReMi.h"
//==== 接腳定義 ====
#define TX     2   //HC-06藍芽TX
#define Buzzer 3   //蜂鳴器
#define RX     4   //HC-06藍芽RX
#define MR2    5   //右馬達輸入2
#define MR1    6   //右馬達輸入1
#define Trig   7   //SR-04超音波Trig
#define B2     7   //按鈕2
#define B1     8   //按鈕1
#define servo  9   //伺服機訊號腳
#define ML1    10  //左馬達輸入1
#define ML2    11  //左馬達輸入2
#define RGB    12  //RGB LED
#define B3     13  //按鈕3
#define Echo   13  //SR-04超音波Echo
#define VR     A0  //可變電阻
#define CDS_R  A1  //光敏電阻(右)
#define IR_RR  A2  //TCRT5000紅外線尋跡(最右)
#define IR_R   A3  //TCRT5000紅外線尋跡(右)
#define IR_L   A4  //TCRT5000紅外線尋跡(左)
#define IR_LL  A5  //TCRT5000紅外線尋跡(最左)
#define CDS_L  A6  //光敏電阻(左)
#define VinDet A7  //電池電壓偵測
//==================
int melody[] = {0,Do,Re,Mi,Fa,So,La,Si,HDo};

void setup()
{
  pinMode(Buzzer,OUTPUT);
      tone(Buzzer,melody[5],300);
    delay(1300);
    tone(Buzzer,melody[3],300);
    delay(1300);
    tone(Buzzer,melody[3],600);
    delay(1600);
    
    tone(Buzzer,melody[4],300);
    delay(1300);
    tone(Buzzer,melody[2],300);
    delay(1300);
    tone(Buzzer,melody[2],600);
    delay(1600);
    
    tone(Buzzer,melody[1],300);
    delay(1300);
    tone(Buzzer,melody[2],300);
    delay(1300);
    tone(Buzzer,melody[3],300);
    delay(1300);
    tone(Buzzer,melody[4],300);
    delay(1300);
    
    tone(Buzzer,melody[5],300);
    delay(1300);
    tone(Buzzer,melody[5],300);
    delay(1300);
    tone(Buzzer,melody[5],600);
    delay(1600);

}

void loop()
{
 

}
