/*******************************************
*	文件名：Wave.cpp
*	超声波测距库
*	created 2016.7.14
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 

#include <Arduino.h>
#include "Wave.h"

/********************************************
*	Wave类构造函数
*	函数功能：定义超声波输入输出引脚
*	入口参数：trig表示输出引脚，echo表示输入引脚 
*********************************************/
Wave::Wave(int trig, int echo)
{
	TrigPin=trig;
	EchoPin=echo;
	pinMode(TrigPin, OUTPUT);  
	pinMode(EchoPin, INPUT);
}

/********************************************
*	检测距离子函数
*	函数功能：发出脉冲，检测距离 
*	入口参数：无
*	返回值：表示测得的距离，厘米为单位 
*********************************************/
float Wave::distance()
{
	// 产生一个10us的高脉冲去触发TrigPin 
  digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW); 
  // 检测脉冲宽度，并计算出距离
  return pulseIn(EchoPin, HIGH) / RATE;
} 
