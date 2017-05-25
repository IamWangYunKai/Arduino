/*******************************************
*	文件名：DHT11.h
*	温湿度传感器库
*	created 2017.5.24
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#ifndef DHT11_h
#define DHT11_h

#define N_REC 6

class DHT11{
	public:
		DHT11(int sensorPin);
		int temp=0; 	//温度
		int humi=0; 	//湿度
		void begin(void);
		void read(void);
	private:
		int pin;
		unsigned int loopCnt=0; //发送开始工作指令时设置的超时时间
		int chr[40] = {0};    //创建数字数组，用来存放每次传输的40个bit
		unsigned long time=0; //记录高电平时间
		int firstTime=0;   //是否第一次采样标志
		int index=0;       //队列指针
		int value_temp[N_REC]={0};    //温度数据队列
		int value_humi[N_REC]={0};    //湿度数据队列
}; 

#endif
