#include <wiringPi.h>
#include <stdio.h>

#define BZR	    1	
#define TOTAL	25


#define RE 293.66
#define DO 261.63
#define MI 329.63
#define PA 349.23
#define SOL 391.00
#define LA 440.00
#define SI 493.88


#define T8	300
#define T16	150
#define T4	600

int total_num[] = {25, 108, 25};


int airplane[] ={MI, RE, DO, RE, MI, MI, MI, RE, RE, RE, MI, SOL, SOL, MI, RE, DO, RE, MI, MI, MI, RE, RE, MI, RE, DO};
int delays_a[] ={T8+T16, T16, T8, T8, T8, T8, T4, T8, T8, T4, T8, T8, T4, T8+T16, T16, T8, T8, T8 ,T8, T4, T8, T8, T8+T16, T16, T4+T4};

int mario[] ={MI, MI, 0, MI, 0, DO, MI, 0, SOL, 0, SOL/2, 0, DO, 0, SOL/2, 0, MI/2, 0, LA/2, 0, SI/2, 0, 233.08, LA/2, SOL/2, MI, SOL, LA, 0, PA, SOL, 0,
                MI, DO, RE, SI/2, 0, DO, 0, SOL/2, 0, MI/2, 0, LA/2, 0, SI/2, 0, 233.08, LA/2, SOL/2, MI, SOL, LA, 0, PA, SOL, 0, MI, DO, RE, SI/2, 0,
                0, SOL, 369.99, PA, 311.13, MI, 0, 207.65, LA/2, DO, 0, LA/2, DO, RE, 0, SOL, 369.99, PA, 311.13, MI, 0, DO*2, DO*2, DO*2, 0,
                0, SOL, 369.99, PA, 311.13, MI, 0, 207.65, LA/2, DO, 0, LA/2, DO, RE,0,311.13,0,RE,0, DO, 0, };
int delays_m[] ={T8, T8, T8, T8, T8, T8, T8, T8, T4, T4, T4, T4, T4, T8, T4, T8, T4, T8, T8, T8, T8, T8, T8, T4, T8, T8, T8, T8,
                T4, T8, T8, T4, T8, T8, T8, T8, T4, T4,T8,T4,T8,T4,T8,T8,T8,T8,T8,T8,T4, T8, T8, T8,T8,T4,T8,T8,T4,T8,T8,T8,T8,T4,T4,T8,T8,T8,T4,T8,T8,T8,T8,T8,T8,T8,T8,T8
                ,T4,T8,T8,T8,T4,T8,T8,T4,T8,T4,T4,T4, T8,T8,T8,T4,T8,T8,T8,T8,T8,T8,T8,T8,T8,T4,T4,T8,T4,T8,T4,T4};//108*/

int rabbit[] = {SOL, MI, MI, SOL, MI , DO, RE, MI, RE, DO, MI, SOL, DO*2,SOL, DO*2, SOL, DO*2, SOL , MI, SOL, RE,PA,MI,RE,DO};
int delays_b[] = {T4,T8,T8,T8,T8,T4,T4,T8,T8,T8,T8,T4,T8+T16,T16,T8,T8,T8,T8,T4,T4,T8,T8,T8,T8,T4};
/*
int notes[] = {MI, SOL, LA, SI, SI, MI, SI, LA, SI, LA, SOL, PA, MI,RE, RE, PA, SOL, LA, LA, SOL, PA, SOL, MI, SOL, LA, SI, SI, MI, SI, LA, SI, LA, SOL, PA, MI,RE,
                RE, PA, SOL, LA, LA, 185.00, LA, SI, MI, SOL, LA, SI, SI, MI, SI, LA, LA, LA, SOL, PA};
int delays[] = {T16, T16, T16, T8, T8, T16, T16 + T8, T8, T8, T16,T16,T16,T16,T16, T8,T8,T8,T8,T16,T16,T16, T16+T16, T16,T16,T16, T8,T8, T16,T8+T16,T8,T8,T16,T16,T16,T16,T16,
                T8, T8, T8,T8,T16,T16,T16,T8,T16,T16,T16,T8,T8,T16,T8+T16,T8,T8,T16,T16,T8};*/


int marioPlay(){
	int i;
    pinMode(BZR, PWM_OUTPUT);

    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);

	for(i=0;i<total_num[1];++i){
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
    pwmWrite(BZR, 0);
	return 0;
}

int airPlay(){
	int i;
    pinMode(BZR, PWM_OUTPUT);

    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);

	for(i=0;i<total_num[0];++i){
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
    pwmWrite(BZR, 0);
	return 0;
}

int rabbitPlay(){
	int i;
    pinMode(BZR, PWM_OUTPUT);

    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);

	for(i=0;i<total_num[2];++i){
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
    pwmWrite(BZR, 0);
	return 0;
}

int main(){
	wiringPiSetup();
	marioPlay();
	return 0;
}
