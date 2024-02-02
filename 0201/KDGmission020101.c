// 인체 감지 센서와 부저 결합

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>
#define PIR_D 2
#define BZR 1
int main(void){
    int pir_val, i;
    if(wiringPiSetup() == -1)
        return -1;
    pinMode(PIR_D, INPUT);
    pinMode(BZR, OUTPUT);
    
    while(1){
        pir_val = digitalRead(PIR_D);
        if(pir_val == 1) digitalWrite(BZR, 1);
        else digitalWrite(BZR ,0);
    }
}