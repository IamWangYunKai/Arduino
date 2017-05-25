/*******************************************
*	文件名：KY-037.cpp
*	声音传感器库
*	created 2017.5.24
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "KY037.h"

/*********************************************
KY037构造函数，传入一个采样引脚，同时给mid赋值 
*********************************************/
KY037::KY037(int sensorPin){
	pin=sensorPin;
	//注意！不要把下面的代码写在构造函数里面！！！ 
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
