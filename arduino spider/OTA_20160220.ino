#include <Servo.h>

Servo mtr[12];
int svNum[] = {2,3,4,5,6,7,8,9,10,11,12,13};
int moveStep[] = {0,0,0,0,0,0,0,0,0};
byte cmd[9][10][13], idx = 0;
bool singleMode = true;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 12; i++)
    mtr[i].attach(svNum[i]);
}

void loop() {
  if(singleMode){
    if(Serial.available()>0){
      byte tmp = (byte)(Serial.read());
      delay(10);
      if(tmp<240){
        mtr[idx++].write(tmp);
        if(idx == 13) idx = 0;
      }else if(tmp == 255){
        byte moves = (byte)(Serial.read());
        delay(10);
        for(int i = 0; i < moves; i++){
          for(int j = 0; j < 13; j++){
            while(Serial.available()==0);
            cmd[1][i][j] = (byte)(Serial.read());
          }
          Serial.write(250);
        }
        for(int i = 0; i < moves; i++){
          for(int j = 0; j < 12; j++){
            mtr[j].write(cmd[1][i][j]);
            delay(5);
          }
          delay(cmd[1][i][12]*10);
        }
      }else if(tmp == 240){
        byte actions = (byte)(Serial.read());
        delay(10);
        for(int i = 0; i < actions; i++){
          while(Serial.available()==0);
          moveStep[i] = (byte)(Serial.read());
        }
        Serial.write(250);
        for(int i = 0; i < actions; i++)
          for(int j = 0; j < moveStep[i]; j++){
            for(int k = 0; k < 13; k++){
              while(Serial.available()==0);
              cmd[i][j][k] = (byte)(Serial.read());
            }
            Serial.write(250);
          }
        singleMode = false;
      }
    }else idx = 0;
  }else{ // command mode
    if(Serial.available()>0){
      byte tmp = (byte)(Serial.read());
      if(tmp == 224) singleMode = true;
      else{
        int reverse = 254-tmp;
        for(int i = 0; i < moveStep[reverse]; i++){
          for(int j = 0; j < 12; j++){
            mtr[j].write(cmd[reverse][i][j]);
            delay(5);
          }
          delay(cmd[reverse][i][12]*10);
        }
        Serial.write(250);
      }
    }
  }
}
