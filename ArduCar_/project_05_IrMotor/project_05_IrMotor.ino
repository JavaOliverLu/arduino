//==== 接腳定義 ====

#define MR2    5   //右馬達輸入2
#define MR1    6   //右馬達輸入1
#define ML1    10  //左馬達輸入1
#define ML2    11  //左馬達輸入2

#define IR_RR  A2  //TCRT5000紅外線尋跡(最右)
#define IR_R   A3  //TCRT5000紅外線尋跡(右)
#define IR_L   A4  //TCRT5000紅外線尋跡(左)
#define IR_LL  A5  //TCRT5000紅外線尋跡(最左)

//========調整參數==========

#define Speed 150   //馬達速度(0-255)
int  IR =    200;   //紅外線臨界值
int S1,S2,S3,S4;


void setup()
{
  Serial.begin(9600);
  pinMode(IR_RR,INPUT);
  pinMode(IR_R,INPUT);
  pinMode(IR_L,INPUT);
  pinMode(IR_LL,INPUT);
}

void loop()
{
  S1=analogRead(IR_LL);
  S2=analogRead(IR_L);
  S3=analogRead(IR_R);
  S4=analogRead(IR_RR);
  
 analogWrite(ML1,Speed);
 digitalWrite(ML2,LOW);
 analogWrite(MR1,Speed);
 digitalWrite(MR2,LOW);
  //delay(1); 

  if(S2<IR) {
 analogWrite(ML1,LOW);
 digitalWrite(ML2,LOW);
 analogWrite(MR1,Speed);
 digitalWrite(MR2,LOW);
  //delay(1);
  }
  
  if(S3<IR) {
 analogWrite(ML1,Speed);
 digitalWrite(ML2,LOW);
 analogWrite(MR1,LOW);
 digitalWrite(MR2,LOW);
  //delay(1);
  }
 if(S3<IR & S2<IR) {
 analogWrite(ML1,LOW);
 digitalWrite(ML2,LOW);
 analogWrite(MR1,LOW);
 digitalWrite(MR2,LOW);
  //delay(1);
  }
 


  
}
