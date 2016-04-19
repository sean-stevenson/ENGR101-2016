int main(){
 
    InitHardware();
    int IRF = 1;
    while(IRF <= 5){
        WriteDigital(7, 1);
        Sleep(0, 500000);
        WriteDigital(7, 0);
        Sleep(0, 500000);
        IRF++;
    }
    return 0;
}

#include <stdio.h>
#include <time.h>

extern "C" int InitHardware();
extern "C" int WriteDigital(int chan, char level);
extern "C" int Sleep(int sec, int usec);
extern "C" int ReadAnalog(int irS);

int main(){
    InitHardware();

    int IRRead;
    while(true){
        IRRead = ReadAnalog(0);
        if(IRRead > 100){
            WriteDigital(7,1);
            Sleep(1,0);
        }
        else{
            WriteDigital(7,0);
            Sleep(1,0);
        }
    }
    return 0;
}
#include <stdio.h>
#include <time.h>

extern "C" int InitHardware();
extern "C" int Sleep(int sec, int usec);
extern "C" int ReadAnalog(int irS);
extern "C" int SetMotor(int motor, int dir, int speed);

int main(){
    InitHardware();

	//Turns left for 0.5 seconds
            SetMotor(1,1,0);
            Sleep(0,0);
        
            SetMotor(2,1,255);
            Sleep(0,500000);
//Turns right for 0.5 seconds
            SetMotor(1,1,255);
            Sleep(0,500000);
        
            SetMotor(2,1,0);
            Sleep(0, 0);

        
    }
    return 0;
}
#include <stdio.h>
#include <time.h>

extern "C" int InitHardware();
extern "C" int Sleep(int sec, int usec);
extern "C" int ReadAnalog(int irS);
extern "C" int SetMotor(int motor, int dir, int speed);

int main(){
    InitHardware();

    int IRRead;
    while(true){
        IRRead = ReadAnalog(0);

        if(IRRead > 200){
            SetMotor(1,1,0);
            Sleep(0,250000);
        }
        else{
            SetMotor(1,1,250);
            Sleep(0,100000);
        }
    }
    return 0;
}

