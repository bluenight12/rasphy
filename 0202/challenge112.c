#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED 1
#define Range 1024
int main(){
    wiringPiSetup();
    pinMode(LED, PWM_OUTPUT);
    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(Range);
    while(1){
        char inp;
        scanf("%c",&inp);
        while(getchar() != '\n');
        if(inp == '0'){
            pwmWrite(LED, 0);
        }else if(inp == '5'){
            pwmWrite(LED, Range/2);
        }else if (inp == 't')
        {
            pwmWrite(LED, Range);
        }
    }
}