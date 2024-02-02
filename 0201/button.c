#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>
#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6

#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22

int main(void){
    int i,ret = 2;
    if(wiringPiSetup() == -1)
        return 1;
    
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(SW4, INPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_RED, 0);
    digitalWrite(LED_GREEN, 0);
    digitalWrite(LED_BLUE, 0);
    while(1){
        ret = digitalRead(SW1);
        if(ret == 0)
            digitalWrite(LED_RED, 1);
        ret = digitalRead(SW2);
        if(ret == 0)
            digitalWrite(LED_GREEN, 1);
        ret = digitalRead(SW3);
        if(ret == 0)
            digitalWrite(LED_BLUE, 1);
        ret = digitalRead(SW4);
        if(ret == 0){
            usleep(1000);
            digitalWrite(LED_RED, 0);
            digitalWrite(LED_GREEN, 0);
            digitalWrite(LED_BLUE, 0);
            break;
        }
    }   
}