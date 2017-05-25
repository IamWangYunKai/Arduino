/*******************************************
*	文件名：SingleNeuronPID.h 
*	PID控制库 
*	created 2016.9.4
*	by 王云凯
*	Email： 615349118@qq.com 
********************************************/ 
#ifndef SingleNeuronPID_h
#define SingleNeuronPID_h

class SNPID{
	public:
		SNPID(float _set=0,float _p=0,float _i=0,float _d=0,float _rp=0,float _ri=0,float _rd=0);
		float rp=0.0;
		float ri=0.0;
		float rd=0.0;
		float p=0;	
		float i=0;	
		float d=0;	
		float set=0;				//给定值 
		int read=0;					//检测的被控量 
		int write=0;				//计算所得控制量，是增量du(t) 
		int inputPin;				//	被记忆的读取引脚 
		int outputPin;				//	被记忆的执行引脚
		int pidRead(int pin); 		//检测被控量 
		int pidWrite(int pin=-1);	//输出控制量，需要指定引脚，无参数则仅计算返回控制量
		void still(unsigned long time=1000);	//反复进行PID控制，参数是维持时间
		void clear(void); 			//清除记忆 
		void learn(void);

	private:
		float Error=0;				//	给定值-被控量，e(n) 
		float lastError=0;			//	e(n-1)
		float prevError=0;			//	e(n-2)
		float sumError=0;			//	∑e(i)
		float dError=0;				//dError=Error-lastError
		float x1=0.0;
		float x2=0.0;
		float x3=0.0;
}; 

#endif 
