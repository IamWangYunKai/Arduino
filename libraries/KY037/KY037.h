/*******************************************
*	文件名：KY-037.h
*	声音传感器库
*	created 2017.5.24
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#ifndef KY037_h
#define KY037_h

class KY037{
	public:
		KY037(int sensorPin); 	//KY037构造函数，传入一个采样引脚
		volatile int val;		//采样值 
		void test(void);		//检测函数 
		int getMid(void);
		void setMid(int value); 
		void begin(void);
		
	private:
		int pin;			//采样引脚 
		int mid;			//mid为静态偏移 
};

#endif
