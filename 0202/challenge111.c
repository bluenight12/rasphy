#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED 0

int main(){
    wiringPiSetup();
    pinMode(LED, OUTPUT);
    while(1){
        char inp;
        scanf("%c",&inp);
        while(getchar() != '\n');
        if(inp == 'N') digitalWrite(LED, 1);
        if(inp == 'F') digitalWrite(LED, 0);
    }
}