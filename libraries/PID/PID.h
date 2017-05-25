/*************************************************************************
*	�ļ�����PID.h 
*	PID���ƿ� 
*   �������λ����PID���ƺ�������PID����
*	ֻ���ڽ�������ʱ������INC����POS
*	����delay������һ��ȱ�ݣ�������Ҫά��״̬������ʱ����still()���� 
*	ע�⣬�����õ���pid�������ǹ�ʽ�е�ʵ�ʲ���
*	��λ����PID�����У�
*	p=Kp	i=K*T/Ti	d=K*Td/T
*	��ʽΪ	u(n)=Kp*e(n)+(Kp*T/Ti)*��e(i)+(Kp*Td/T)*[e(n)-e(n-1)]
*	��������PID�����У�
*	p=Kp(1+T/Ti+Td/T)	i=Kp(1+2Td/T)	d=Kp*Td/T
*	��ʽΪ	u(n)=Kp(1+T/Ti+Td/T)*e(n) - Kp(1+2Td/T)*e(n-1) -  Kp*Td/T*e(n-2)
*	ע�����е� '-' �ţ�ʵ�ʼ�����з���
*	����δ��ʵ����飬����Ľ� 
*	created 2016.7.30
*	by ���ƿ�
*	Email�� 615349118@qq.com 
**************************************************************************/ 
#ifndef PID_h
#define PID_h

#define	INC -1
#define	POS -2

class PID
{
	public:
		PID(int mode=-1,float _set=0,float _p=0,float _i=0,float _d=0);	//���캯����Ĭ��Ϊ������PID���� 
		float p=0;					//��������p 
		float i=0;					//��������i 
		float d=0;					//��������d 
		float set=0;				//����ֵ 
		int read=0;					//���ı����� 
		int write=0;				//�������ÿ�������������du(t) 
		int inputPin;				//	������Ķ�ȡ���� 
		int outputPin;				//	�������ִ������
		int pidRead(int pin); 		//��ⱻ���� 
		int pidWrite(int pin=-1);	//�������������Ҫָ�����ţ��޲���������㷵�ؿ�����
		void still(unsigned long time=1000);	//��������PID���ƣ�������ά��ʱ��
		void clear(void); 			//������� 
	private:	 
		float Error=0;				//	����ֵ-��������e(n) 
		float lastError=0;			//	e(n-1)
		float prevError=0;			//	e(n-2)
		float sumError=0;			//	��e(i)
		float dError=0;				//dError=Error-lastError
		int flag;					//�����ж���λ����PID���ƻ���������PID����		
}; 

#endif 
