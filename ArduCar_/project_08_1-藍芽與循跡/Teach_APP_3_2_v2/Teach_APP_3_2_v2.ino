//APP:InnoSCar_V3
//前:70
//後:66
//左:76
//右:82
//GO:53
//X:83
//左上:49
//左下:52
//右上:50
//右下:51
//按鈕放掉:48

#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include "DoReMi.h"
//= 尋線用馬達轉速 =
byte MR_SL=200;
byte ML_SL=200;
//== 尋線轉彎轉速 ==
byte MR_S=150;
byte ML_S=150;
//= 藍芽用馬達轉速 
byte MR_Sbt=240 ;
byte ML_Sbt=240;
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
//== RGB  LED設定 ==
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1,RGB,NEO_GRB + NEO_KHZ800);//設定RGB LED
byte R,G,B;
byte TurnSPD=2;
//==== 藍芽設定 ====
SoftwareSerial BTSerial(TX,RX); // RX, TX
int BTR = 0;
//==================
int melody[] = {0,Do,Re,Mi,Fa,So,La,Si,HDo};
boolean RRv_IR,Rv_IR,Lv_IR,LLv_IR;
boolean LINE = false;
#define RRv 150 //最右邊尋跡紅外線數值,白底>黑線
#define Rv  150 //右邊尋跡紅外線數值,白底>黑線
#define Lv  150 //左邊尋跡紅外線數值,白底>黑線
#define LLv 150 //最左邊尋跡紅外線數值,白底>黑線
//==================
void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  strip.begin();  //RGBLED初始化
  pinMode(Buzzer,OUTPUT);
  pinMode(MR1,OUTPUT);
  pinMode(MR2,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(ML2,OUTPUT);
  pinMode(IR_RR,INPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_LL,INPUT);
  pinMode(B1,INPUT);
  pinMode(Trig,OUTPUT);    //使用按鈕2時註解這行
  //pinMode(B2,INPUT);     //使用超音波時註解這行
  pinMode(B3,INPUT);       //同時也是超音波的Echo
  pinMode(VR,INPUT);
  pinMode(CDS_R,INPUT);
  pinMode(CDS_L,INPUT);
  pinMode(VinDet,INPUT);
  digitalWrite(B1,HIGH);
  digitalWrite(B2,LOW);
  digitalWrite(B3,LOW);
}

void loop()
{
  if(BTSerial.available() > 0){
    BTR = BTSerial.read();
    //Serial.print("GET:");
    //Serial.println(BTR);
    switch (BTR){
      case 70://F
        ForwardBT();
      break;
      
      case 82://R
        Right();
      break;
      
      case 76://L
        Left();
      break;
      
      case 66://B
        Backward();
      break;
      
      case 53://GO
        RGBled(strip.Color(60, 60, 60));//R,G,B
        LINE=true;
        LINE_FOLLOW();
        Stop();
      break;
      
      case 83://S
        Stop();
      break;
      
      case 48://放開
        Stop();
      break;
    }
    delay(50);
  }
}

void RGBled(uint32_t c){
  strip.setPixelColor(0, c);
  strip.show();
}

void ForwardBT(){
  analogWrite(MR1,MR_Sbt);
  digitalWrite(MR2,LOW);
  analogWrite(ML1,ML_Sbt);
  digitalWrite(ML2,LOW);
}

void Forward(){
  analogWrite(MR1,MR_SL);
  digitalWrite(MR2,LOW);
  analogWrite(ML1,ML_SL);
  digitalWrite(ML2,LOW);
  R=0;   //0~255
  G=60;  //0~255
  B=0;   //0~255
  RGBled(strip.Color(R, G, B));
}

void Right(){
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,HIGH);
  digitalWrite(ML1,HIGH);
  digitalWrite(ML2,LOW);
  R=0;   //0~255
  G=0;   //0~255
  B=60;  //0~255
  RGBled(strip.Color(R, G, B));
}

void Left(){
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,HIGH);
  digitalWrite(MR1,HIGH);
  digitalWrite(MR2,LOW);
  R=60;  //0~255
  G=0;   //0~255
  B=0;   //0~255
  RGBled(strip.Color(R, G, B));
}

void Backward(){
  analogWrite(MR2,MR_Sbt);
  digitalWrite(MR1,LOW);
  analogWrite(ML2,ML_Sbt);
  digitalWrite(ML1,LOW);
  R=60; //0~255
  G=60; //0~255
  B=60; //0~255
  RGBled(strip.Color(R, G, B));
}

void Stop(){
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
  if(!LLv_IR || !Lv_IR || !Rv_IR || !RRv_IR)
    RGBled(strip.Color(0,0,0));
  delay(300);
}

void LINE_FOLLOW(){
  while(LINE){     
    GetIR();
    if(!Lv_IR && !Rv_IR)
      Forward();
    
    if(Lv_IR && !Rv_IR)
      Left_LINE();
  
    if(!Lv_IR && Rv_IR)
      Right_LINE();

    if(LLv_IR && Lv_IR && Rv_IR && RRv_IR){
      RGBled(strip.Color(60, 0, 0));
      Stop();
      BEEP();
    }
    
    if(BTSerial.available() > 0){
      BTR = BTSerial.read();
      if(BTR==53)
        LINE = false;
    }
  }
}

void GetIR(){
  if(analogRead(IR_RR) >= RRv)
    RRv_IR=false; //白底
  else
    RRv_IR=true;  //黑線
    
  if(analogRead(IR_R) >= Rv)
    Rv_IR=false; //白底
  else
    Rv_IR=true;  //黑線

  if(analogRead(IR_L) >= Lv)
    Lv_IR=false; //白底
  else
    Lv_IR=true;  //黑線
    
  if(analogRead(IR_LL) >= LLv)
    LLv_IR=false; //白底
  else
    LLv_IR=true;  //黑線
}

void Right_LINE(){
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
  analogWrite(ML1,ML_S);
  digitalWrite(ML2,LOW);
  RGBled(strip.Color(0, 0, 60));//R,G,B
}

void Left_LINE(){
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  analogWrite(MR1,MR_S);
  digitalWrite(MR2,LOW);
  RGBled(strip.Color(60, 0, 0));//R,G,B
}

void BEEP(){  //LDo,LRe,LMi,LFa,LSo,LLa,LSi,Do,Re,Mi,Fa,So,La,Si,HDo,HRe,HMi,HFa,HSo,HLa,HSi
    tone(Buzzer,melody[1],300);
    delay(300);
    tone(Buzzer,melody[2],300);
    delay(300);
    tone(Buzzer,melody[3],300);
    delay(300);
}
