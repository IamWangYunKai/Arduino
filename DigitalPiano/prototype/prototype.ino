
#ifndef SERIAL_RATE
#define SERIAL_RATE         115200
#endif

#ifndef SERIAL_TIMEOUT
#define SERIAL_TIMEOUT      5
#endif

int pin=12;

void setup() {
    Serial.begin(SERIAL_RATE);
    Serial.setTimeout(SERIAL_TIMEOUT);
    pinMode(12, OUTPUT);
}

void loop() {
    switch (readData()) {
        case 1 :
            tone(pin,523); break;
        case 2 :
            tone(pin,587); break;
        case 3 :
            tone(pin,659); break;
        case 4 :
            tone(pin,698); break;
        case 5 :
            tone(pin,784);break;
        case 6 :
            tone(pin,880); break;
        case 7 :
            tone(pin,988); break;
        case 11 :
            tone(pin,1047); break;
        case 12 :
            tone(pin,1175); break;
        case 13 :
            tone(pin,1319); break;
        case 14 :
            tone(pin,1397); break;
        case 15 :
            tone(pin,1568); break;
        case 16 :
            tone(pin,1760); break; 
        case 17 :
            tone(pin,1976); break;
        case 21 :
            tone(pin,262); break;
        case 22 :
            tone(pin,294); break;
        case 23 :
            tone(pin,330); break;
        case 24 :
            tone(pin,349); break;
        case 25 :
            tone(pin,392); break;
        case 26 :
            tone(pin,440); break;
        case 27 :
            tone(pin,494); break;           
        default:
            //just dummy to cancel the current read, needed to prevent lock 
            //when the PC side dropped the "w" that we sent
            noTone(pin);
            break;
    }
    //delay(500);
    //noTone(pin);
}

char readData() {
    //Serial.flush();
    Serial.println("w");
    while(1) {
        if(Serial.available() > 0) {
            return Serial.parseInt();
        }
    }
}
