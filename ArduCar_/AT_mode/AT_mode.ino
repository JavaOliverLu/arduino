#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9); // Rx, Tx腳
char val;  // 儲存接收資料的變數
 
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  // HC-05需設38400 baud rate with NL&CR 而 HC-06為9600, with  “沒有行結尾” 而且可能要用大寫的AT
  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  // 如果是HC-06，請改成9600
  BT.begin(9600);
}
 
void loop() {
  // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
  }
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }
}

