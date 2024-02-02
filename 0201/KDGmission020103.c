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

int clear(){
    digitalWrite(LED_RED, 0);
    digitalWrite(LED_GREEN, 0);
    digitalWrite(LED_BLUE, 0);
}
int answer = 0;
int check_LED(int led, float k){
    float count = 0;
    while(1){
        if(led == LED_RED){
            if(digitalRead(SW1) == 0){
                answer++;
                break;
            }
        } else if(led == LED_GREEN){
            if(digitalRead(SW2) == 0){
                answer++;
                break;
            }
        } else if(led == LED_BLUE){
            if(digitalRead(SW3)==0){
                answer++;
                break;
            }
        }
        usleep(100);
        count += 0.0001;
        if(count > k){
            break;
        }
    }
    clear();
}
int main(){
    wiringPiSetup();
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);

    srand(time(NULL));
    int before = -1;
    for(int i = 0 ;i<10;i++){
        int n = rand()%3;
        while(n == before){
            n = rand()%3;
        }
        before = n;
        float k;
        k = ((float)(rand()%50) / 100) + 0.5f;
        switch(n){
            case 0:
                digitalWrite(LED_RED, 1);
                check_LED(LED_RED, k);
                break;
            case 1:
                digitalWrite(LED_GREEN, 1);
                check_LED(LED_GREEN, k);
                break;
            case 2:
                digitalWrite(LED_BLUE, 1);
                check_LED(LED_BLUE, k);
                break;
        }
    }
    printf("Score : %d\n", answer);
}