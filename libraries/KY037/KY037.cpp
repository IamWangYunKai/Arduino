/*******************************************
*	�ļ�����KY-037.cpp
*	������������
*	created 2017.5.24
*	by ���ƿ�
*	Email�� 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "KY037.h"

/*********************************************
KY037���캯��������һ���������ţ�ͬʱ��mid��ֵ 
*********************************************/
KY037::KY037(int sensorPin){
	pin=sensorPin;
	//ע�⣡��Ҫ������Ĵ���д�ڹ��캯�����棡���� 
	/*
	pinMode(pin,INPUT);
	sum=0;
	for(int i=0;i<50;i++){
		sum += analogRead(pin);
	}
	//mid=(int)(sum/50);
	mid=analogRead(A1);
	*/
}

void KY037::begin(void){
	pinMode(pin,INPUT);
	long sum=0;
	for(int i=0;i<50;i++){
		sum += analogRead(pin);
	}
	mid=(int)(sum/50);
}

void KY037::test(void){
	val=analogRead(pin);
	/*
	if(abs(val-mid)>14){
		Serial.println("BIG noise");
	}
	else if(abs(val-mid)>7){
		Serial.println("small noise");
	}
	*/
}

int KY037::getMid(void){
	return mid;
}

void KY037::setMid(int value){
	mid=value;
}
