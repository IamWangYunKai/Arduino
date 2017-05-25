/*******************************************
*	文件名：PID.cpp 
*	PID控制库 
*	created 2016.7.30
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "PID.h"
 
PID::PID(int mode,float _set,float _p,float _i,float _d){
	flag=mode;
	set=_set;
	p=_p;
	i=_i;
	d=_d;
}

int PID::pidRead(int pin){
	inputPin=pin;
	read=analogRead(pin);
	return read; 
} 

int PID::pidWrite(int pin){ 
	if(flag=-2){				//	位置型PID控制
		Error=set-read;			// 偏差
		sumError += Error;		// 积分
		dError=Error-lastError;	// 当前微分
		prevError=lastError;	//更新变量 
		lastError=Error;		//更新变量
		write= p*Error+i*sumError+d*dError;	//计算控制量 
	}
	else if(flag=-1){			//	增量型PID控制 
		Error=set-read;			// 偏差
		write= p*Error-i*lastError-d*prevError;	//计算控制量
		prevError=lastError;	//更新变量 
		lastError=Error;		//更新变量
	}
	if(pin!=-1){
		outputPin=pin;
		analogWrite(write,pin);
	}	
	return (int)write; 
}

void PID::still(unsigned long time){
	unsigned long beginTime=millis();
	unsigned long now=millis();
	while((now-beginTime)<time){
		pidRead(inputPin);
		pidWrite(outputPin);
		now=millis();
	}	
}

void PID::clear(void){
	Error=0; 
	lastError=0;
	prevError=0;
	sumError=0;	
	dError=0;	
}
