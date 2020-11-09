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
#define LightL 260   //光線感度
#define LightR 260   //光線感度
#define SpeedL 210   //馬達速度(0-255)
#define SpeedR 210   //馬達速度(0-255)
int CR,CL;
void setup()
{
  Serial.begin(9600);
  pinMode(CDS_R,INPUT);
  pinMode(CDS_L,INPUT);
  pinMode(VinDet,INPUT);
}

void loop()
{
  CR=analogRead(CDS_R);
  CL=analogRead(CDS_L);
  Serial.print("R:");
  Serial.println(CR);
  Serial.print("L:");
  Serial.println(CL);
  
  if(CR>LightR){
    analogWrite(MR1,SpeedR);
    digitalWrite(MR2,LOW);
    digitalWrite(ML1,LOW);
    analogWrite(ML2,SpeedL); 
    delay(1000);   
  }
      
  if(CL>LightL){
    analogWrite(ML1,SpeedL);
    digitalWrite(ML2,LOW);  
    digitalWrite(MR1,LOW);
    analogWrite(MR2,SpeedR);
    delay(1000);
  }
    
    digitalWrite(MR1,LOW);
    digitalWrite(MR2,LOW);
    digitalWrite(ML1,LOW);
    digitalWrite(ML2,LOW);
    delay(100);
}
