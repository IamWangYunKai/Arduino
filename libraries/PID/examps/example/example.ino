#include <PID.h>
PID pid(INC); //声明为增量型PID控制
int inputPin=A1;
int outputPin=A2;
void setup() {
Serial.begin(9600);
pid.set=200;
pid.p=1;
pid.i=1;
pid.d=1;
}

void loop() {
pid.pidRead(inputPin);
Serial.println(pid.read);
pid.pidWrite(outputPin);
Serial.println(pid.write);
pid.still(5000);
pid.clear();
}
