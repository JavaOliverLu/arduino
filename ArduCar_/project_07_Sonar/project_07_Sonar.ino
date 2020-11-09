#include <Ultrasonic.h>
#define Trig   7   //SR-04超音波Trig
#define Echo   13  //SR-04超音波Echo
Ultrasonic ultrasonic(Trig,Echo);
float Dis = 0;

void setup(){
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);    //使用按鈕2時註解這行
  pinMode(Echo,INPUT);       //同時也是超音波的Echo
}

void loop(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Dis = cmMsec;
  Serial.print("CM: ");
  Serial.println(cmMsec);
  delay(500);
}
