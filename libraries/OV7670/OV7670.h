#ifndef OV7670_h
#define OV7670_h

#include <Arduino.h>

class OV7670
 {
	public:
	OV7670(void);
	void init(void);
	void readpid(void);
	
	void writeReg(byte reg, byte value);
    byte readReg(byte reg);
	
	byte pid;
	byte last_status;
	
	private:
	byte ov7670_address;
 };
#endif