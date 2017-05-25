/*******************************************
*	�ļ�����DHT11.h
*	��ʪ�ȴ�������
*	created 2017.5.24
*	by ���ƿ�
*	Email�� 615349118@qq.com 
********************************************/ 
#ifndef DHT11_h
#define DHT11_h

#define N_REC 6

class DHT11{
	public:
		DHT11(int sensorPin);
		int temp=0; 	//�¶�
		int humi=0; 	//ʪ��
		void begin(void);
		void read(void);
	private:
		int pin;
		unsigned int loopCnt=0; //���Ϳ�ʼ����ָ��ʱ���õĳ�ʱʱ��
		int chr[40] = {0};    //�����������飬�������ÿ�δ����40��bit
		unsigned long time=0; //��¼�ߵ�ƽʱ��
		int firstTime=0;   //�Ƿ��һ�β�����־
		int index=0;       //����ָ��
		int value_temp[N_REC]={0};    //�¶����ݶ���
		int value_humi[N_REC]={0};    //ʪ�����ݶ���
}; 

#endif
