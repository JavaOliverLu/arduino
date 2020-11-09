#include <Adafruit_NeoPixel.h>
#define RGB    12  //RGB LED
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1,RGB,NEO_GRB + NEO_KHZ800);//設定RGB LED
byte R,G,B;

void setup()
{
  Serial.begin(9600);
  strip.begin();  //RGBLED初始化
}

void loop()
{
  RGBled(strip.Color(60, 60, 60));//R,G,B
  delay(1000);
  RGBled(strip.Color(120, 120, 120));//R,G,B
  delay(1000);
  RGBled(strip.Color(200, 200, 200));//R,G,B
  delay(1000);
  RGBled(strip.Color(200, 200, 0));//R,G,B
  delay(1000);
  RGBled(strip.Color(200, 0, 200));//R,G,B
  delay(1000);
  RGBled(strip.Color(0, 200, 200));//R,G,B
  delay(1000);
}

void RGBled(uint32_t c){
  strip.setPixelColor(0, c);
  strip.show();
}
