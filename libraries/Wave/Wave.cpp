/*******************************************
*	�ļ�����Wave.cpp
*	����������
*	created 2016.7.14
*	by ���ƿ�
*	Email�� 615349118@qq.com 
********************************************/ 

#include <Arduino.h>
#include "Wave.h"

/********************************************
*	Wave�๹�캯��
*	�������ܣ����峬���������������
*	��ڲ�����trig��ʾ������ţ�echo��ʾ�������� 
*********************************************/
Wave::Wave(int trig, int echo)
{
	TrigPin=trig;
	EchoPin=echo;
	pinMode(TrigPin, OUTPUT);  
	pinMode(EchoPin, INPUT);
}

/********************************************
*	�������Ӻ���
*	�������ܣ��������壬������ 
*	��ڲ�������
*	����ֵ����ʾ��õľ��룬����Ϊ��λ 
*********************************************/
float Wave::distance()
{
	// ����һ��10us�ĸ�����ȥ����TrigPin 
  digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW); 
  // ��������ȣ������������
  return pulseIn(EchoPin, HIGH) / RATE;
} 
