/*******************************************
*	文件名：Filter.cpp 
*	软件滤波器库 
*	created 2016.7.29
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#include <Arduino.h>
#include "Filter.h"

Filter::Filter(int pin){
	valPin=pin;
	value_rec[N_REC]={0};	//递推平均滤波用的数组 
	index=0;			//递推平均滤波用的索引 
	limit=100; 				//限制最大振幅的范围 
	delayTime=10;			//两次采样的时间间隔，单位为毫秒 
	rate=0.1;
	flag=1;
	value=0;
}
		
int Filter::limitRead(int limit_val,int change){
  if(-1!=limit_val){
  	limit=limit_val;			//每次调用后会改变limit，下一次可以不再使用参数 
  }
  int new_value;
  new_value=analogRead(valPin);
  if ( ( new_value - value > limit ) || ( value - new_value > limit ))
    return value;
  else{
  	if(change) value=new_value; 
  	return new_value;
  }
}

int Filter::midRead(int n_mid){
  int value_buf[n_mid];   //存放采样数据 
  int count,i,j,temp;
  for (count=0;count<n_mid;count++){
    value_buf[count]=analogRead(valPin);
    delay(delayTime);
  }
  //对样本排序
  for (j=0;j<n_mid-1;j++){
    for (i=0;i<n_mid-j;i++){
      if ( value_buf[i]>value_buf[i+1] ){
        temp = value_buf[i];
        value_buf[i] = value_buf[i+1];
        value_buf[i+1] = temp;
      }
    }
  }
  return value_buf[(int)((n_mid-1)/2)];
}

int Filter::avrRead(int n_avr){
  int sum = 0,count;
  for (count=0;count<n_avr;count++){
    sum += analogRead(valPin);
    delay(delayTime);
  } 
  return (int)(sum/n_avr);
}

int Filter::recRead(int n_rec){
  int count,i;
  int sum=0;
  if(flag){
	for(i=0;i<N_REC;i++){ 
  		value_rec[i] = analogRead(valPin);
  		delay(delayTime);
  		} 
  		flag=0;
  }
  for(i=0;i<N_REC;i++){
	value_rec[index++] = analogRead(valPin);
	if(index == N_REC) index=0;
  }
  for(count=0;count<N_REC;count++)
    sum += value_rec[count];
  return (int)(sum/N_REC);
}

int Filter::lagRead(float rate){
  int new_value;
  new_value = analogRead(valPin);
  return (int)( (1-rate)*value + rate*new_value );
}

void Filter::setDalay(unsigned long time){
	delayTime=time;
}

void Filter::setVal(int set_val){
	value=set_val;
}

void Filter::setLimit(int limit_val){
	limit=limit_val;
}

void Filter::setRate(int rate_val){
	rate=rate_val;
}

void Filter::recClear(void){
	flag=1;
}
