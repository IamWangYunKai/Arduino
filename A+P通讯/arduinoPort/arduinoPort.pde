/*
Warnning:the end of the array is:/13 /10, and don't ever visit the next cell! Or it will go wrong!
*/
import processing.serial.*;
Serial arduinoPort;

float[] pt=new float[1024];

int val=0;

void setup(){
    size(1024,900);
    int i=0;
    for(i=0;i<1024;i++){
        pt[i]=0.0; 
    }

    strokeWeight(5);
    strokeJoin(ROUND);
    stroke(100,100,255);
    
    arduinoPort = new Serial(this, Serial.list()[0],9600);
}

void draw(){
    byte[] inBuffer = new byte[7];
    while(arduinoPort.available()>0){
        inBuffer = arduinoPort.readBytes();
        arduinoPort.readBytes(inBuffer);
        if(inBuffer != null){
            String myString = new String(inBuffer);
            if(inBuffer[1]!=13 &&inBuffer[2]!=13 &&inBuffer[3]>47 && inBuffer[3]<58){
                 val=(inBuffer[0]-48)*1000+(inBuffer[1]-48)*100+(inBuffer[2]-48)*10+(inBuffer[3]-48);
            }
            else if(inBuffer[2]>47 && inBuffer[2]<58){
                val=(inBuffer[0]-48)*100+(inBuffer[1]-48)*10+(inBuffer[2]-48);
            }
            else if(inBuffer[1]>47 && inBuffer[1]<58){
                val=(inBuffer[0]-48)*10+(inBuffer[1]-48);
            }
            else if(inBuffer[0]>47 && inBuffer[0]<58){
                val=(inBuffer[0]-48);
            }
            print("myString: ");
            print(myString);
            print("val:      ");
            println(val);
        }
    }
    
    background(255,255,255);
    int i=0;
    for(i=1023;i>0;i--){
        pt[i]=pt[i-1]; 
    }

    pt[0]=250+val*400.0/1024;
    
    for(i=0;i<1023;i++){
        line(i,900-pt[i],i+1,900-pt[i+1]);
    }
}