/*******************************************
*	�ļ�����PID.cpp 
*	PID���ƿ� 
*	created 2016.7.30
*	by ���ƿ�
*	Email�� 615349118@qq.com 
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
	if(flag=-2){				//	λ����PID����
		Error=set-read;			// ƫ��
		sumError += Error;		// ����
		dError=Error-lastError;	// ��ǰ΢��
		prevError=lastError;	//���±��� 
		lastError=Error;		//���±���
		write= p*Error+i*sumError+d*dError;	//��������� 
	}
	else if(flag=-1){			//	������PID���� 
		Error=set-read;			// ƫ��
		write= p*Error-i*lastError-d*prevError;	//���������
		prevError=lastError;	//���±��� 
		lastError=Error;		//���±���
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
