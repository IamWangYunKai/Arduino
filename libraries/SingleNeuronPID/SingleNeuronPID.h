/*******************************************
*	�ļ�����SingleNeuronPID.h 
*	PID���ƿ� 
*	created 2016.9.4
*	by ���ƿ�
*	Email�� 615349118@qq.com 
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
		float set=0;				//����ֵ 
		int read=0;					//���ı����� 
		int write=0;				//�������ÿ�������������du(t) 
		int inputPin;				//	������Ķ�ȡ���� 
		int outputPin;				//	�������ִ������
		int pidRead(int pin); 		//��ⱻ���� 
		int pidWrite(int pin=-1);	//�������������Ҫָ�����ţ��޲���������㷵�ؿ�����
		void still(unsigned long time=1000);	//��������PID���ƣ�������ά��ʱ��
		void clear(void); 			//������� 
		void learn(void);

	private:
		float Error=0;				//	����ֵ-��������e(n) 
		float lastError=0;			//	e(n-1)
		float prevError=0;			//	e(n-2)
		float sumError=0;			//	��e(i)
		float dError=0;				//dError=Error-lastError
		float x1=0.0;
		float x2=0.0;
		float x3=0.0;
}; 

#endif 
