// SW1을 누르면 동요 1 그리고 LED-RED
// SW2를 누르면 동요 2 그리고 LED-GREEN
// SW3을 누르면 동요 3 그리고 LED-BLUE

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

//부저 핀
#define BZR 1
//음계
#define RE 293.66
#define DO 261.63
#define MI 329.63
#define PA 349.23
#define SOL 391.00
#define LA 440.00
#define SI 493.88
//박자
#define T8	150
#define T16	75
#define T4	300
//LED 핀
#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22
//버튼 핀
#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6

int total_num[] = {25, 108, 25};

int airplane[] ={MI, RE, DO, RE, MI, MI, MI, RE, RE, RE, MI, SOL, SOL, MI, RE, DO, RE, MI, MI, MI, RE, RE, MI, RE, DO};
int delays_a[] ={T8+T16, T16, T8, T8, T8, T8, T4, T8, T8, T4, T8, T8, T4, T8+T16, T16, T8, T8, T8 ,T8, T4, T8, T8, T8+T16, T16, T4+T4};//25

int mario[] ={MI, MI, 0, MI, 0, DO, MI, 0, SOL, 0, SOL/2, 0, DO, 0, SOL/2, 0, MI/2, 0, LA/2, 0, SI/2, 0, 233.08, LA/2, SOL/2, MI, SOL, LA, 0, PA, SOL, 0,
                MI, DO, RE, SI/2, 0, DO, 0, SOL/2, 0, MI/2, 0, LA/2, 0, SI/2, 0, 233.08, LA/2, SOL/2, MI, SOL, LA, 0, PA, SOL, 0, MI, DO, RE, SI/2, 0,
                0, SOL, 369.99, PA, 311.13, MI, 0, 207.65, LA/2, DO, 0, LA/2, DO, RE, 0, SOL, 369.99, PA, 311.13, MI, 0, DO*2, DO*2, DO*2, 0,
                0, SOL, 369.99, PA, 311.13, MI, 0, 207.65, LA/2, DO, 0, LA/2, DO, RE,0,311.13,0,RE,0, DO, 0, };
int delays_m[] ={T8, T8, T8, T8, T8, T8, T8, T8, T4, T4, T4, T4, T4, T8, T4, T8, T4, T8, T8, T8, T8, T8, T8, T4, T8, T8, T8, T8,
                T4, T8, T8, T4, T8, T8, T8, T8, T4, T4,T8,T4,T8,T4,T8,T8,T8,T8,T8,T8,T4, T8, T8, T8,T8,T4,T8,T8,T4,T8,T8,T8,T8,T4,T4,T8,T8,T8,T4,T8,T8,T8,T8,T8,T8,T8,T8,T8
                ,T4,T8,T8,T8,T4,T8,T8,T4,T8,T4,T4,T4, T8,T8,T8,T4,T8,T8,T8,T8,T8,T8,T8,T8,T8,T4,T4,T8,T4,T8,T4,T4};//108

int rabbit[] = {SOL, MI, MI, SOL, MI , DO, RE, MI, RE, DO, MI, SOL, DO*2,SOL, DO*2, SOL, DO*2, SOL , MI, SOL, RE,PA,MI,RE,DO};
int delays_b[] = {T4,T8,T8,T8,T8,T4,T4,T8,T8,T8,T8,T4,T8+T16,T16,T8,T8,T8,T8,T4,T4,T8,T8,T8,T8,T4};//25

int chak[] = {SI/2, RE, 369.99, RE, 233.08, 277.18, MI, LA/2, SI/2, RE, 369.99, RE, 233.08, 277.18, MI, 466.16, SOL, 369.99, MI, SOL, 369.99, MI, RE, 277.18, SI, SOL, 369.99, MI};
int delays_c[] = {T4, T4, T4, T4,T4, T4, T4, T4,T4, T4, T4, T4,T4, T4, T4, T4,T4, T4, T4, T4,T4, T4, T4, T4,T4+T4,T4+T4,T4+T4,T4+T4};

int music_flag;
int LED_control(int n);

int clear_music(int n){
    digitalWrite(n, 0);
    music_flag = 0;
    pwmWrite(BZR, 0);
}



int marioPlay(int n){
	int i;
    LED_control(n);
	for(i=0;i<total_num[1];++i){
        if(digitalRead(SW4) == 0) {
            clear_music(n);
            break;
        }
        if(mario[i] == 0) {
            pwmWrite(BZR, mario[i]);
        }else{
		    pwmSetRange(1000000/mario[i]);
            pwmWrite(BZR, 1000000/mario[i]/2);
        }
		delay(delays_m[i] - 20);        
        pwmWrite(BZR, 0);
        delay(20);
	}
    clear_music(n);
	return 0;
}

int airPlay(int n){
	int i;
    LED_control(n);
	for(i=0;i<total_num[0];++i){
        if(digitalRead(SW4) == 0) {
            clear_music(n);
            break;
        }
        if(airplane[i] == 0) {
            pwmWrite(BZR, airplane[i]);
        }else{
		    pwmSetRange(1000000/airplane[i]);
            pwmWrite(BZR, 1000000/airplane[i]/2);
        }
		delay(delays_a[i] - 20);        
        pwmWrite(BZR, 0);
        delay(20);
	}
    clear_music(n);
	return 0;
}

int rabbitPlay(int n){
	int i;
    LED_control(n);
	for(i=0;i<total_num[2];++i){
        if(digitalRead(SW4) == 0) {
            clear_music(n);
            break;
        }
        if(rabbit[i] == 0) {
            pwmWrite(BZR, rabbit[i]);
        }else{
		    pwmSetRange(1000000/rabbit[i]);
            pwmWrite(BZR, 1000000/rabbit[i]/2);
        }
		delay(delays_b[i] - 20);        
        pwmWrite(BZR, 0);
        delay(20);
	}
    clear_music(n);
	return 0;
}

int LED_control(int n){
    digitalWrite(n, 1);
}

int main(){
	wiringPiSetup();
	pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(BZR, PWM_OUTPUT);

    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);
    int res;
    while(1){
        if(music_flag == 1) continue;
        res = digitalRead(SW1);
        if(res == 0){
            music_flag = 1;
            airPlay(LED_RED);
        }
        res = digitalRead(SW2);
        if(res == 0){
            music_flag = 1;
            marioPlay(LED_GREEN);
        }
        res = digitalRead(SW3);
        if(res == 0 ){
            music_flag = 1;
            rabbitPlay(LED_BLUE);
        }
    }
	return 0;
}
