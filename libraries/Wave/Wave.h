/*******************************************
*	ÎÄ¼şÃû£ºWave.h
*	³¬Éù²¨²â¾à¿â
*	created 2016.7.14
*	by ÍõÔÆ¿­
*	Email£º 615349118@qq.com 
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
