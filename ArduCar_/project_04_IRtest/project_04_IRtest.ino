//==== 接腳定義 ====

#define IR_RR  A2  //TCRT5000紅外線尋跡(最右)
#define IR_R   A3  //TCRT5000紅外線尋跡(右)
#define IR_L   A4  //TCRT5000紅外線尋跡(左)
#define IR_LL  A5  //TCRT5000紅外線尋跡(最左)

//==================
int S1,S2,S3,S4;
void setup()
{
  Serial.begin(9600);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
}

void loop()
{
  S1=analogRead(IR_LL);
  S2=analogRead(IR_L);
  S3=analogRead(IR_R);
  S4=analogRead(IR_RR);
  Serial.print("IR_LL:");
  Serial.println(S1);
  Serial.print("IR_L:");
  Serial.println(S2);
  Serial.print("IR_R:");
  Serial.println(S3);
  Serial.print("IR_RR:");
  Serial.println(S4);
  
  delay(1000);
  
}
