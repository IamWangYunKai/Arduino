/*************************************************************************
*	�ļ�����Filter.h 
*	����˲����� 
*   ����ʹ����Filter�࣬�����������˲���
*   �������ַ�ʽ��ȡһ������ 
*   ע���ȡ���ݲ�����ı�Filter����value��ֵ������ı���Ҫÿ�ζ�ȡ��ֵ 
*	created 2016.7.29
*	by ���ƿ�
*	Email�� 615349118@qq.com 
**************************************************************************/ 
#ifndef Filter_h
#define Filter_h

#define N_REC 12		//��ƽ���˲��Ļ������� 
#define CHANGE 1

class Filter
{
	public:
		Filter(int pin);							//���캯��������Ϊ�������� 
		volatile int value;							//�����ڴ洢��������ֵ 
		int limitRead(int limit_val=-1,int change=0);	//�޷��˲�������һ����ѡ�����������޶����ȴ�С���ڶ�����ѡ��value��׼�Ƿ�ı� ���� CHANGE��ʾ��׼�ı� 
		int midRead(int n_mid=11);						//��λֵ�˲�����������������ȡ���� ��Ĭ��Ϊ11 
		int avrRead(int n_avr=10);						//����ƽ���˲�����������������ȡ������Ĭ��Ϊ10 
		int recRead(int n_rec=1);						//����ƽ���˲�����������������ȡ���� ��Ĭ��Ϊ1 
		int lagRead(float rate=0.1); 					//һ���ͺ��˲������������¶�ȡ������ռ���أ���Χ��0-1��Ĭ��Ϊ0.1��ԽС����Խ�⻬ 
		void setLimit(int limit_val);				//�����޷��˲��������ƴ�С ��Ĭ��Ϊ100 
		void setVal(int set_val=0); 					//����value�Ĵ�С �����Ӳ�������� 
		void setDalay(unsigned long time=10);			//�����������ζ�ȡ��ʱ������Ĭ��Ϊ10ms 
		void setRate(int rate_val);					//����һ���ͺ��˲����ı��� 
		void recClear(void);						//��������ƽ���˲�����������ԭ������ 
		
	private:
		int valPin;					//�������� 
		int value_rec[N_REC];		//����ƽ���˲��õ����� 
		int index;					//����ƽ���˲��õ����� 
		int limit; 					//�����������ķ�Χ 
		unsigned long delayTime;	//���β�����ʱ��������λΪ���� 
		int flag;					//�жϵ���ƽ���˲��Ƿ��ȡ��ֵ 
		float rate;					//һ���ͺ��˲��ı�ֵ 
}; 

#endif 
