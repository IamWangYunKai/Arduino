/*************************************************************************
*	文件名：PID.h 
*	PID控制库 
*   本库包含位置型PID控制和增量型PID控制
*	只需在建立对象时声明是INC还是POS
*	由于delay函数有一定缺陷，这里想要维持状态又想延时请用still()函数 
*	注意，这里用到的pid参数均非公式中的实际参数
*	在位置型PID控制中：
*	p=Kp	i=K*T/Ti	d=K*Td/T
*	公式为	u(n)=Kp*e(n)+(Kp*T/Ti)*∑e(i)+(Kp*Td/T)*[e(n)-e(n-1)]
*	在增量型PID控制中：
*	p=Kp(1+T/Ti+Td/T)	i=Kp(1+2Td/T)	d=Kp*Td/T
*	公式为	u(n)=Kp(1+T/Ti+Td/T)*e(n) - Kp(1+2Td/T)*e(n-1) -  Kp*Td/T*e(n-2)
*	注意其中的 '-' 号，实际计算可列方程
*	本库未经实验检验，尚需改进 
*	created 2016.7.30
*	by 王云凯
*	Email： 615349118@qq.com 
**************************************************************************/ 
#ifndef PID_h
#define PID_h

#define	INC -1
#define	POS -2

class PID
{
	public:
		PID(int mode=-1,float _set=0,float _p=0,float _i=0,float _d=0);	//构造函数，默认为增量型PID控制 
		float p=0;					//非真正的p 
		float i=0;					//非真正的i 
		float d=0;					//非真正的d 
		float set=0;				//给定值 
		int read=0;					//检测的被控量 
		int write=0;				//计算所得控制量，是增量du(t) 
		int inputPin;				//	被记忆的读取引脚 
		int outputPin;				//	被记忆的执行引脚
		int pidRead(int pin); 		//检测被控量 
		int pidWrite(int pin=-1);	//输出控制量，需要指定引脚，无参数则仅计算返回控制量
		void still(unsigned long time=1000);	//反复进行PID控制，参数是维持时间
		void clear(void); 			//清除记忆 
	private:	 
		float Error=0;				//	给定值-被控量，e(n) 
		float lastError=0;			//	e(n-1)
		float prevError=0;			//	e(n-2)
		float sumError=0;			//	∑e(i)
		float dError=0;				//dError=Error-lastError
		int flag;					//用于判断是位置型PID控制还是增量型PID控制		
}; 

#endif 
