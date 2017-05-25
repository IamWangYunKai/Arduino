/*************************************************************************
*	文件名：Filter.h 
*	软件滤波器库 
*   本库使用了Filter类，包含了五种滤波器
*   可用五种方式读取一个数据 
*   注意读取数据并不会改变Filter类中value的值，如需改变需要每次读取后赋值 
*	created 2016.7.29
*	by 王云凯
*	Email： 615349118@qq.com 
**************************************************************************/ 
#ifndef Filter_h
#define Filter_h

#define N_REC 12		//推平均滤波的缓存数量 
#define CHANGE 1

class Filter
{
	public:
		Filter(int pin);							//构造函数，参数为采样引脚 
		volatile int value;							//可用于存储采样所得值 
		int limitRead(int limit_val=-1,int change=0);	//限幅滤波器，第一个可选参数是数据限定幅度大小，第二个是选择value基准是否改变 ，用 CHANGE表示基准改变 
		int midRead(int n_mid=11);						//中位值滤波器，参数是连续读取次数 ，默认为11 
		int avrRead(int n_avr=10);						//算术平均滤波器，参数是连续读取次数，默认为10 
		int recRead(int n_rec=1);						//递推平均滤波器，参数是连续读取次数 ，默认为1 
		int lagRead(float rate=0.1); 					//一阶滞后滤波器，参数是新读取的数所占比重，范围是0-1，默认为0.1，越小数据越光滑 
		void setLimit(int limit_val);				//设置限幅滤波器的限制大小 ，默认为100 
		void setVal(int set_val=0); 					//设置value的大小 ，不加参数则归零 
		void setDalay(unsigned long time=10);			//设置连续两次读取的时间间隔，默认为10ms 
		void setRate(int rate_val);					//设置一阶滞后滤波器的比例 
		void recClear(void);						//放弃递推平均滤波器缓存器的原有数据 
		
	private:
		int valPin;					//采样引脚 
		int value_rec[N_REC];		//递推平均滤波用的数组 
		int index;					//递推平均滤波用的索引 
		int limit; 					//限制最大振幅的范围 
		unsigned long delayTime;	//两次采样的时间间隔，单位为毫秒 
		int flag;					//判断递推平均滤波是否读取过值 
		float rate;					//一阶滞后滤波的比值 
}; 

#endif 
