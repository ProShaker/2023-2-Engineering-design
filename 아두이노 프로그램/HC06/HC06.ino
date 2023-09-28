#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX (수신 핀), TX (송신 핀)

void setup() {
  Serial.begin(9600);     // 시리얼 통신 초기화
  BTSerial.begin(9600);   // 블루투스 모듈 시리얼 통신 초기화
}

void loop() {
  if (BTSerial.available()) {  // 블루투스 모듈로부터 데이터가 수신되면
    char receivedChar = BTSerial.read();  // 데이터를 읽어들임
    Serial.print(receivedChar);  // 시리얼 모니터에 데이터 출력
  }
  
  if (Serial.available()) {  // 시리얼 모니터로부터 데이터가 입력되면
    char sendChar = Serial.read();  // 데이터를 읽어들임
    BTSerial.print(sendChar);  // 블루투스 모듈로 데이터 전송
  }
}
