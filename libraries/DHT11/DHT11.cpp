/*******************************************
*	文件名：DHT11.cpp 
*	温湿度传感器库
*	created 2017.5.24
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "DHT11.h"

DHT11::DHT11(int sensorPin){
	pin=sensorPin;
	firstTime=1;
	index=0;
}

/**********************************************
发送开始工作指令函数 
**********************************************/
void DHT11::begin(){
bgn:
//设置6号接口模式为：输出，输出低电平20ms（>18ms），输出高电平40μs
	pinMode(pin,OUTPUT);
	digitalWrite(pin,LOW);
	delay(20);
	digitalWrite(pin,HIGH);
	delayMicroseconds(40);
	digitalWrite(pin,LOW);
	pinMode(pin,INPUT);   //设置2号接口模式：输入
	//高电平响应信号
	loopCnt=10000;
	while(digitalRead(pin) != HIGH){
    	if(loopCnt-- == 0){    //如果长时间不返回高电平，输出个提示，重头开始
      		//Serial.println("HIGH");
      		goto bgn;
    	}
  	}
  //低电平响应信号
	loopCnt=30000;
	while(digitalRead(pin) != LOW){
    	if(loopCnt-- == 0){    //如果长时间不返回低电平，输出个提示，重头开始
			//Serial.println("LOW");
			goto bgn;
		}
	}
}

void DHT11::read(){
  begin();
  //开始读取bit1-40的数值  
  for(int i=0;i<40;i++){
    while(digitalRead(pin) == LOW)    //当出现高电平时，记下时间“time”
      continue;
    time = micros();
    
    while(digitalRead(pin) == HIGH)
      continue;
//当出现低电平，记下时间，再减去刚才储存的time
//得出的值若大于50μs，则为‘1’，否则为‘0’,并储存到数组里去
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
//滤波程序
//如果是第一次采样,即firstTime=1,则填充队列
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
