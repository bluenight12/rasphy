#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>
#include <unistd.h>

//LED 핀
#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22
//버튼 핀
#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6

#define BZR	    1	

#define RE 293.66
#define DO 261.63
#define MI 329.63

int main(){
    wiringPiSetup();

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(SW4, INPUT);

    pinMode(BZR, PWM_OUTPUT);

    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);
    int before = -1;
    int arr[5];
    for(int i = 0 ;i<5;i++){
        int n = rand()%3;
        while(n == before){
            n = rand()%3;
        }
        before = n;
        switch(n){
            case 0:
                digitalWrite(LED_RED, 1);
                pwmSetRange(1000000/DO);
                pwmWrite(BZR, 1000000/DO/2);
                delay(500);
                pwmWrite(BZR, 0);       
                digitalWrite(LED_RED, 0);
                break;
            case 1:
                digitalWrite(LED_GREEN, 1);                
                pwmSetRange(1000000/RE);
                pwmWrite(BZR, 1000000/RE/2);
                delay(500);
                pwmWrite(BZR, 0);                
                digitalWrite(LED_GREEN, 0);
                break;
            case 2:
                digitalWrite(LED_BLUE, 1);
                pwmSetRange(1000000/MI);
                pwmWrite(BZR, 1000000/MI/2);
                delay(500);
                pwmWrite(BZR, 0);                
                digitalWrite(LED_BLUE, 0);
                break;
        }
        delay(1000);
        arr[i] = n;
    }
    int answer[5];
    int count = 0;
    int before_SW1 = 1;
    int before_SW2 = 1;
    int before_SW3 = 1;
    while(count < 5){
        if(digitalRead(SW1) == 0) answer[count++] = 0;
        if(digitalRead(SW2) == 0) answer[count++] = 1;
        if(digitalRead(SW3) == 0) answer[count++] = 2;
        if(digitalRead(SW4) == 0) break;
        delay(100);
    }
    int ed = 0;
    for(int i = 0;i<5;i++){
        if(arr[i] == answer[i]) ed++;
    }
    if(ed == 5) printf("Success");
}