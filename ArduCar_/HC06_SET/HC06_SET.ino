/*
9600 是 HC-06 出廠後的預設 baud rate，如果已經改過了，必須自己置換掉，不然，可能無法正常連線。
Arduino firmware upload 完畢，關掉 Arduino IDE 程式後，我們就可以用終端機軟體連 Arduino 的序列埠(以 9600 來連線)。
成功和 Arduino 連上線，畫面上應該會出現Enter AT commands:」的訊息
如果輸入「AT」，HC-06 應該會回應「OK」，如果沒有回應，就要檢查一下接腳是否正確，或是將「BTSerial.begin(9600)」中的 9600 要換成別的連線速率試試。
HC-06 的 AT command 只有簡單的幾項，而且不像 HC-05 必須按 Enter 鍵送出「\r\n」才會執行並回應。所以，我們一按完「AT」兩個按鍵，它馬上就回應「OK」了。

//============= 接腳 ==============
藍芽模組的VCC -> 5V
藍芽模組的GND -> GND
藍芽模組的TXD -> 10
藍芽模組的RXD -> 11
藍芽模組的KEY -> 5V  (HC-05)
//==========  HC-06 指令 ==========
注意!!! HC-06 請將鮑率設為9600 : BTSerial.begin(9600);
AT：測試，回應「OK」
AT+VERSION：回應靭體的版本。
AT+NAMExyz：將裝置名稱改為「xyz」                         
AT+PIN1234：將連線密碼換為「1234」
AT+BAUD4：將 baud rate 換為 9600
AT+BAUD5：將 baud rate 換為 19200
AT+BAUD6：將 baud rate 換為 38400
AT+BAUD7：將 baud rate 換為 57600
//=================================

//==========  HC-05 指令 ==========
注意!!! HC-05 請將鮑率設為38400 : BTSerial.begin(38400);
注意!!! Serial Monitor 右下角請選擇[Both NL & CR]
AT        :測試，回應「OK」
AT+ORGL   :回復成出廠值
AT+NAME?  :回傳藍芽名字
AT+NAME=名字  :設定藍芽名字
AT+PSWD?      :回傳藍芽配對密碼
AT+PSWD=密碼  :設定藍芽配對密碼
AT+UART?      :回傳UART設定
AT+UART=_,_,_ :設定UART
//*****************
空格1
baud rate(bits/s):
4800
9600
19200
38400
57600
115200

空格2
stop bit:
0----1 bit
1----2 bits 

空格3
parity bit:
0----None
1----Odd parity
2----Even parity

Default: 9600, 0, 0 
//*****************


AT+ROLE?  :回傳模組角色
AT+ROLE=_ :設定模組角色
//*****************
0:Slave role
1:Master role
2:Slave-Loop role

Default: 0
//*****************


AT+CMODE?  :回傳連接模式
AT+CMODE=_ :設定連接模式
//*****************
0:連結綁定位址
1:連結任意位址
2:Slave-Loop

Default connection mode: 1
//*****************

AT+ADDR?  :回傳藍芽位址
AT+BIND?  :回傳綁定位址
AT+BIND=_ :設定綁定位址

Default address:
0:0:0
//=================================
*/
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 4); // RX | TX
void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  // HC-06 current bound rate (default 9600)
  // HC-05 current bound rate (default 38400)
  BTSerial.begin(9600);
}
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
    BTSerial.write(Serial.read());
}
