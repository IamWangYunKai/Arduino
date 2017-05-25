#include <Arduino.h>
#include "Light.h"

void Light::Display(unsigned char x, unsigned char Number){
	this->WeiXuan(x);
	this->pickNumber(Number);
	delay(1);
	this->Clear(); 
}

void Light::WeiXuan(unsigned char n){
    switch(n){
        case 1: 
            digitalWrite(d1,LOW);
            digitalWrite(d2, HIGH);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, HIGH);   
			break;
   		case 2: 
    		digitalWrite(d1, HIGH);
    		digitalWrite(d2, LOW);
    		digitalWrite(d3, HIGH);
    		digitalWrite(d4, HIGH); 
    		break;
    	case 3: 
			digitalWrite(d1,HIGH);
			digitalWrite(d2, HIGH);
			digitalWrite(d3, LOW);
			digitalWrite(d4, HIGH); 
			break;
    	case 4: 
			digitalWrite(d1, HIGH);
			digitalWrite(d2, HIGH);
			digitalWrite(d3, HIGH);
			digitalWrite(d4, LOW); 
			break;
    	default :
			digitalWrite(d1, HIGH);
			digitalWrite(d2, HIGH);
			digitalWrite(d3, HIGH);
			digitalWrite(d4, HIGH);
        	break;
    }
}
void Light::Num_0(){
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, HIGH);
	digitalWrite(g, LOW);
	digitalWrite(dp,LOW);
}
void Light::Num_1(){
	digitalWrite(a, LOW);
	digitalWrite(b, HIGH);
	digitalWrite(c, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, LOW);
	digitalWrite(dp,LOW);
}
/*后面的缩进不想改了*/
void Light::Num_2(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Num_3(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Num_4(){
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Num_5(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Num_6(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Num_7(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,LOW);
}
void Light::Num_8(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Num_9(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Light::Clear(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,LOW);
}
void Light::show(unsigned char n){
	switch(n){
   case 0:this->Num_0();
   break;
   case 1:this->Num_1();
   break;
   case 2:this->Num_2();
   break;
   case 3:this->Num_3();
   break;
   case 4:this->Num_4();
   break;
   case 5:this->Num_5();
   break;
   case 6:this->Num_6();
   break;
   case 7:this->Num_7();
   break;
   case 8:this->Num_8();
   break;
   case 9:this->Num_9();
   break;
   default:this->Clear();
   break; 
  }
}

