#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>
#define PIR_D 2
#define SW4 6
int main(void){
    int pir_val, i;
    if(wiringPiSetup() == -1)
        return -1;
    pinMode(PIR_D, INPUT);
    pinMode(SW4, INPUT);
    while(1){
        pir_val = digitalRead(PIR_D);
        if(pir_val == 1) printf("PIR Detected !! \n");
        else printf("PIR Not Detect !! \n");
        int ret = digitalRead(SW4);
        if(ret == 0)
            break;
        sleep(1);
    }
}