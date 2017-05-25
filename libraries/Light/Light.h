#ifndef Light_h
#define Light_h
#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define dp 8
#define d4 9
#define d3 10
#define d2 11
#define d1 12

class Light
{
	public:
		 //设置变量
 		long n = 1230;
 		int x = 100;
 		int del = 55;  //此处数值对时钟进行微调
 		void WeiXuan(unsigned char n);
 		void Clear();
 		void show(unsigned char n);
 		void Display(unsigned char x, unsigned char Number);

	private:
		void Num_0();
		void Num_1();
		void Num_2();
		void Num_3();
		void Num_4();
		void Num_5();
		void Num_6();
		void Num_7();
		void Num_8();
		void Num_9();			
}; 



#endif   
