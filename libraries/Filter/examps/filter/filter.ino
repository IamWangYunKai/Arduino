#include <Filter.h>
int pin=A1;
Filter filter(A1);
int val[6];
int i=0;

void setup() {
pinMode(A1,INPUT);
Serial.begin(9600);
Serial.println("Start!");
val[5]=analogRead(A1);
filter.setVal(val[5]);
filter.value=val[5];
}

void loop() {
  val[i++]=filter.limitRead(300);
  val[i++]=filter.midRead(11);
  val[i++]=filter.avrRead(10);
  val[i++]=filter.recRead();
  val[i++]=filter.lagRead(0.5);
  for(int j=0;j<5;j++){
    Serial.println(val[j]);
  }
  Serial.println("Done!");
  i=0;
  delay(100);
}
