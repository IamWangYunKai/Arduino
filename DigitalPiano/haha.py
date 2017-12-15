import msvcrt
import serial
import time

class Arduino(object):

    __OUTPUT_PINS = -1

    def __init__(self, port, baudrate=115200):
        self.serial = serial.Serial(port, baudrate)
        self.serial.write(b'99')

    def __str__(self):
        return "Arduino is on port %s at %d baudrate" %(self.serial.port, self.serial.baudrate)
    
    def __sendData(self, serial_data):
        while(self.__getData()[0] != "w"):
            pass
        serial_data = str(serial_data).encode('utf-8')
        self.serial.write(serial_data)

    def __getData(self):
        input_string = self.serial.readline()
        input_string = input_string.decode('utf-8')
        return input_string.rstrip('\n')

    def close(self):
        self.serial.close()
        return True
    
    def set1(self):
        self.__sendData('1')
        return True
    def set2(self):
        self.__sendData('2')
        return True
    def set3(self):
        self.__sendData('3')
        return True
    def set4(self):
        self.__sendData('4')
        return True
    def set5(self):
        self.__sendData('5')
        return True
    def set6(self):
        self.__sendData('6')
        return True
    def set7(self):
        self.__sendData('7')
        return True
    def stop(self):
        self.__sendData('99')
        return True
    def set11(self):
        self.__sendData('11')
        return True
    def set12(self):
        self.__sendData('12')
        return True
    def set13(self):
        self.__sendData('13')
        return True
    def set14(self):
        self.__sendData('14')
        return True
    def set15(self):
        self.__sendData('15')
        return True
    def set16(self):
        self.__sendData('16')
        return True
    def set17(self):
        self.__sendData('17')
        return True
    def set21(self):
        self.__sendData('21')
        return True
    def set22(self):
        self.__sendData('22')
        return True
    def set23(self):
        self.__sendData('23')
        return True
    def set24(self):
        self.__sendData('24')
        return True
    def set25(self):
        self.__sendData('25')
        return True
    def set26(self):
        self.__sendData('26')
        return True
    def set27(self):
        self.__sendData('27')
        return True


try:
    b = Arduino('COM3')
except:
    try:
        b = Arduino('COM4')
    except:
        try:
            b = Arduino('COM5')
        except:
            print("Connection FAIL!")
            exit()

print("\nSuccessfully connect to Arduino!\n")
print("Please press Key to play:\n")
print("Q:c6  W:d6  E:e6  R:f6  T:g6  Y:a6  U:b6\n")
print("A:c5  S:d5  D:e5  F:f5  G:g5  H:a5  J:b5\n")
print("Z:c4  X:d4  C:e4  V:f4  B:g4  N:a4  M:b4\n")
print("space:0\n")

while 1:
    key=msvcrt.getch();
    key=bytes.decode(key);
    
    if key=='a':
        b.set1()
    if key=='s':
        b.set2()
    if key=='d':
        b.set3()
    if key=='f':
        b.set4()
    if key=='g':
        b.set5()
    if key=='h':
        b.set6()
    if key=='j':
        b.set7()
    if key=='q':
        b.set11()
    if key=='w':
        b.set12()
    if key=='e':
        b.set13()
    if key=='r':
        b.set14()
    if key=='t':
        b.set15()
    if key=='y':
        b.set16()
    if key=='u':
        b.set17()
    if key=='z':
        b.set21()
    if key=='x':
        b.set22()
    if key=='c':
        b.set23()
    if key=='v':
        b.set24()
    if key=='b':
        b.set25()
    if key=='n':
        b.set26()
    if key=='m':
        b.set27()
    if key==' ':
        b.stop()
