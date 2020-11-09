#include <Adafruit_NeoPixel.h>

#define PIN 12
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
int R = 0;
int G = 0;
int B = 0;
int TurnSPD = 2;


void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
  
}

void loop() {
  TurnRED();
  TurnORANGE();//
  TurnYELLOW();
  TurnGREEN();
  TurnBlue();
  TurnPURPLE();//
  TurnWHITE();//
  TurnCyan();//
  TurnOlivine();//
  delay(1000);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void TurnRED(){
  do{
    if(R<=254)
      R+=1;
    if(G>0)
      G-=1;
    if(B>0)
      B-=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R<=254 || G>0 || B>0);
}


void TurnGREEN(){
  do{
    if(R>0)
      R-=1;
    if(G<=254)
      G+=1;
    if(B>0)
      B-=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(G<=254 || R>0 || B>0);
}

void TurnBlue(){
  do{
    if(R>0)
      R-=1;
    if(G>0)
      G-=1;
    if(B<=254)
      B+=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(B<=254 || R>0 || G>0);
}

void TurnYELLOW(){
  do{
    if(R<=254)
      R+=1;
    if(G<=254)
      G+=1;
    if(B>0)
      B-=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R<=254 || G<=254 || B>0);
}

void TurnPURPLE(){
  do{
    if(R<=254)
      R+=1;
    if(G>0)
      G-=1;
    if(B<=254)
      B+=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R<=254 || G>0 || B<=254);
}

void TurnORANGE(){
  do{
    if(R<=254)
      R+=1;
    if(G>=129)
      G-=1;
    if(G<=127)
      G+=1;
    if(B>0)
      B-=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R<=254 || G!=128 || B>0);
}

void TurnCyan(){
  do{
    if(R>0)
      R-=1;
    if(G>=129)
      G-=1;
    if(G<=127)
      G+=1;
      
    if(B>=129)
      B-=1;
    if(B<=127)
      B+=1;
      
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R>0 || G!=128 || B!=128);
}

void TurnOlivine(){
  do{
    if(R>=129)
      R-=1;
    if(R<=127)
      R+=1;

    if(G<=254)
      G+=1;
      
    if(B>0)
      B-=1;
      
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R!=128 || G<=254 || B>0);
}

void TurnWHITE(){
  do{
    if(R<=254)
      R+=1;
    if(G<=254)
      G+=1;
    if(B<=254)
      B+=1;
    colorWipe(strip.Color(R, G, B), TurnSPD);
  }while(R<=254 || G<=254 || B<=254);
}

void showCOLOR(){
  Serial.print("R:");
  Serial.println(R);
  Serial.print("G:");
  Serial.println(G);
  Serial.print("B:");
  Serial.println(B);
}

