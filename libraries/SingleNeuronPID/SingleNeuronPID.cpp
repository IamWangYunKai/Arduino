/*******************************************
*	文件名：SingleNeuronPID.cpp 
*	PID控制库 
*	created 2016.9.4
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "SingleNeuronPID.h"

SNPID::SNPID(float _set,float _p,float _i,float _d,float _rp,float _ri,float _rd)
{
	set=_set;
	p=_p;
	i=_i;
	d=_d;
	rp=_rp;
	ri=_ri;
	rd=_rd;
}

void SNPID::learn(void){
	p+=rp*Error*x1;
	i+=ri*Error*x2;
	d+=rd*Error*x3;
	Error=set-read;
	x1=Error-lastError;
	x2=Error;
	x3=Error-2*lastError+prevError;
}

int SNPID::pidRead(int pin){
	inputPin=pin;
	read=analogRead(pin);
	return read; 
} 

int SNPID::pidWrite(int pin){
	learn();
	write= p*x1+i*x2+d*x3;	//计算控制量
	prevError=lastError;	//更新变量 
	lastError=Error;		//更新变量
	
	if(pin!=-1){
		outputPin=pin;
		analogWrite(write,pin);
	}	
	return (int)write; 
}

void SNPID::clear(void){
	Error=0; 
	lastError=0;
	prevError=0;
	sumError=0;	
	dError=0;
	rp=0;
	ri=0;
	rd=0;
	x1=0;
	x2=0;
	x3=0;
}

void SNPID::still(unsigned long time){
	unsigned long beginTime=millis();
	unsigned long now=millis();
	while((now-beginTime)<time){
		pidRead(inputPin);
		pidWrite(outputPin);
		now=millis();
	}	
}
