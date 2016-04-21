//Turning light on and off 5 times
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
//Turning light on when close to sensor
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
//Making motor turn
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
//Making motor respond to sensor
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

//Reading from 3 sensors
int main(){
    InitHardware();

    int adc_reading;
    adc_reading = ReadAnalog(0);
    printf("%d\n", adc_reading);
    Sleep(1, 000000);

    adc_reading = ReadAnalog(2);
    printf("%d\n", adc_reading);
    Sleep(1, 000000);

    adc_reading = ReadAnalog(4);
    printf("%d\n", adc_reading);
    Sleep(1, 000000);

return 0;
}
//Getting 5 readings
extern "C" int InitHardware();
extern "C" int ReadAnalog(int ch_adc);
extern "C" int Sleep(int sec, int usec);

int main(){
    InitHardware();
    int sensorloop = 5;
    int sensorloopEnd = sensorloop;

    int avgTotal = 0;

    while(sensorloop > 0){
        int adc_reading = ReadAnalog(0);
        printf("%d\n", adc_reading);
        avgTotal = avgTotal + adc_reading;
        Sleep(1,0);
        sensorloop = sensorloop-1;

    }


    int adcReadingAvg = avgTotal/sensorloopEnd;
    printf("%d\n", adcReadingAvg);
return 0;}
#include <stdio.h>
#include <time.h>

//Get half range
extern "C" int InitHardware();
extern "C" int ReadAnalog(int ch_adc);
extern "C" int Sleep(int sec, int usec);

int main(){
    InitHardware();
    int sensorloop = 5;
    int sensorloopEnd = sensorloop;

    int avgTotal = 0;

    int max = 0;
    int min = 1023;

    while(sensorloop > 0){
        int adR = ReadAnalog(0);
        if(adR > max){
        max = adR;
        }
        if(adR < min){
        min = adR;
        }
        printf("%d\n", adR);
        avgTotal = avgTotal + adR;
        Sleep(1,0);
        sensorloop = sensorloop-1;

    }


    int adcReadingAvg = avgTotal/sensorloopEnd;
    int halfrange = (max - min)/2;
    printf("Average reading = %d\n", adcReadingAvg);
    printf("Half range = %d\n", halfrange);
return 0;}
//Array for storing values
#include <stdio.h>
#include <time.h>


extern "C" int InitHardware();
extern "C" int ReadAnalog(int ch_adc);
extern "C" int Sleep(int sec, int usec);

int main(){
    InitHardware();
    int sensorloop = 20;

    int values [20] = {};
    int i;
    
        for(i=0;i< 20;i++){
        int adR = ReadAnalog(0);
        values[i] = values + adR;
        }

        printf("%d\n", values[count]);
        Sleep(1,0);
        sensorloop = sensorloop-1;

    }

    printf("20 values = %d\n", values);
return 0;}
