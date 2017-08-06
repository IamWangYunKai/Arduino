/*检测闪电到此地的距离*/
int soundPin = A0;
int lightPin = A1;
/*上一次读到的时间和时间差*/
long lightTime,soundTime,realTime;
/*设定超时时间为10s，防止误判*/
int timeOut=10000;
int distance;
/*设定阈值*/
int lightNormal = 100;
int soundNormal = 500;
int relLight = 100;
int relSound = 200;
/*设定标签，flag=1时表示检测到闪电*/
int flagLight = 0;
int flagSound = 0;

void setup(){
    pinMode(soundPin,INPUT);
    pinMode(lightPin,INPUT);
    Serial.begin(115200);
    Serial.println("Get ready, test now !");
}

void loop(){
    testLight();
    testSound();
    if( flagSound && flagLight ){
        realTime = soundTime - lightTime;
        if( realTime > 0 && realTime < timeOut ){
            distance = int( 0.34*realTime );
            Serial.print(distance);
            Serial.println(" meters away from here !");
        }
        /*标签清零*/
        flagLight = flagSound = 0;
    }
}

void testLight(){
    int val=analogRead(lightPin);
    if( val - lightNormal > relLight ){
        lightTime = millis();
        flagLight = 1;
    }
}

void testSound(){
    int val=analogRead(lightPin);
    if( abs( val - soundNormal ) > relSound ){
        soundTime = millis();
        flagSound = 1;
    }
}
