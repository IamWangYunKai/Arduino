/*******************************************
*	�ļ�����DHT11.cpp 
*	��ʪ�ȴ�������
*	created 2017.5.24
*	by ���ƿ�
*	Email�� 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "DHT11.h"

DHT11::DHT11(int sensorPin){
	pin=sensorPin;
	firstTime=1;
	index=0;
}

/**********************************************
���Ϳ�ʼ����ָ��� 
**********************************************/
void DHT11::begin(){
bgn:
//����6�Žӿ�ģʽΪ�����������͵�ƽ20ms��>18ms��������ߵ�ƽ40��s
	pinMode(pin,OUTPUT);
	digitalWrite(pin,LOW);
	delay(20);
	digitalWrite(pin,HIGH);
	delayMicroseconds(40);
	digitalWrite(pin,LOW);
	pinMode(pin,INPUT);   //����2�Žӿ�ģʽ������
	//�ߵ�ƽ��Ӧ�ź�
	loopCnt=10000;
	while(digitalRead(pin) != HIGH){
    	if(loopCnt-- == 0){    //�����ʱ�䲻���ظߵ�ƽ���������ʾ����ͷ��ʼ
      		//Serial.println("HIGH");
      		goto bgn;
    	}
  	}
  //�͵�ƽ��Ӧ�ź�
	loopCnt=30000;
	while(digitalRead(pin) != LOW){
    	if(loopCnt-- == 0){    //�����ʱ�䲻���ص͵�ƽ���������ʾ����ͷ��ʼ
			//Serial.println("LOW");
			goto bgn;
		}
	}
}

void DHT11::read(){
  begin();
  //��ʼ��ȡbit1-40����ֵ  
  for(int i=0;i<40;i++){
    while(digitalRead(pin) == LOW)    //�����ָߵ�ƽʱ������ʱ�䡰time��
      continue;
    time = micros();
    
    while(digitalRead(pin) == HIGH)
      continue;
//�����ֵ͵�ƽ������ʱ�䣬�ټ�ȥ�ղŴ����time
//�ó���ֵ������50��s����Ϊ��1��������Ϊ��0��,�����浽������ȥ
  if (micros() - time >50)
      chr[i]=1;
  else
      chr[i]=0;
  }
  
  humi=temp=0;   
  for(int i=0;i<8;i++){
    humi += (chr[i]<<(7-i));
    temp += (chr[i+16]<<(7-i));
  }
//�˲�����
//����ǵ�һ�β���,��firstTime=1,��������
  if(firstTime){
    for(int i=0;i<N_REC;i++){
      value_temp[i] = temp;
      value_humi[i] = humi;
    }
      firstTime=0;
  }
  value_temp[index++] = temp;
  value_humi[index++] = humi;
  if(index == N_REC) index=0;
  
  temp=humi=0;
  for(int count=0;count<N_REC;count++){
    temp += value_temp[count];
    humi += value_humi[count];
  }
  temp=(int)(temp/N_REC);
  humi=(int)(humi/N_REC);
}
