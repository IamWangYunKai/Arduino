/*******************************************
*	�ļ�����KY-037.h
*	������������
*	created 2017.5.24
*	by ���ƿ�
*	Email�� 615349118@qq.com 
********************************************/ 
#ifndef KY037_h
#define KY037_h

class KY037{
	public:
		KY037(int sensorPin); 	//KY037���캯��������һ����������
		volatile int val;		//����ֵ 
		void test(void);		//��⺯�� 
		int getMid(void);
		void setMid(int value); 
		void begin(void);
		
	private:
		int pin;			//�������� 
		int mid;			//midΪ��̬ƫ�� 
};

#endif
