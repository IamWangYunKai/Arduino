/*******************
 * 传感器---arduino
 * PIN6-----Trig
 * PIN7-----Echo
 * Vcc------5V
 * Gnd------GND
 ******************/
#include "Wave.h"
Wave Ceju(6,7); //创建对象：Ceju，注意构造函数写在setup外
float val; 
void setup() {
  Serial.begin(9600);
  Serial.println("Ultrasonic sensor:");
}

void loop() {
  val=Ceju.distance();//读取所测距离
  delay(1000);
}
