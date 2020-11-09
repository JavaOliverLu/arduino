/*
Do(523Hz)
Re(587Hz)
Mi(659Hz)
Fa(698Hz)
So(784Hz)
La(880Hz)
Si(988Hz)
高音 Do (1047Hz)
*/
const byte Buzzer = 3; // 蜂鳴器的接腳 D3

void setup() {
  pinMode(Buzzer,OUTPUT);
}

void loop() {
  tone(Buzzer, 523, 100);
  delay(500);
}
