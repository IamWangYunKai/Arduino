/*******************************************
*	�ļ�����Wave.h
*	����������
*	created 2016.7.14
*	by ���ƿ�
*	Email�� 615349118@qq.com 
********************************************/ 
#ifndef Wave_h
#define Wave_h
#define RATE 58.00

class Wave
{
	public:
		Wave(int trig, int echo);
		
		float distance();		
	private:
		int TrigPin;
		int EchoPin;	
}; 

#endif
