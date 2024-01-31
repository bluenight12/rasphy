#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22

void correct(){
	digitalWrite(LED_RED, 0);
	digitalWrite(LED_GREEN, 0);
	digitalWrite(LED_BLUE, 0);
	usleep(100000);
	digitalWrite(LED_RED, 1);
	usleep(500000);
	digitalWrite(LED_GREEN, 1);
	usleep(500000);
	digitalWrite(LED_BLUE, 1);
	usleep(500000);
}

void not_cor(){
	digitalWrite(LED_RED, 0);
	digitalWrite(LED_GREEN, 0);
	digitalWrite(LED_BLUE, 0);
	usleep(100000);
	digitalWrite(LED_RED, 1);
	usleep(500000);
	digitalWrite(LED_RED, 0);
	usleep(500000);
	digitalWrite(LED_RED, 1);
	usleep(500000);
	digitalWrite(LED_RED, 0);
	usleep(500000);
	digitalWrite(LED_RED, 1);
	usleep(500000);
	digitalWrite(LED_RED, 0);
}
int main(void){
	if(wiringPiSetup() == -1)
		return 1;
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_BLUE, OUTPUT);


	while(1){
		int r = rand() % 2;
		int g = rand() % 2;
		int b = rand() % 2;
		digitalWrite(LED_RED, 0);
		digitalWrite(LED_BLUE, 0);
		digitalWrite(LED_GREEN, 0);
		usleep(500000);
		if(r + g + b <= 1)
			continue;
		digitalWrite(LED_RED, r);
		digitalWrite(LED_GREEN, g);
		digitalWrite(LED_BLUE, b);
		printf("1. yellow\n");
		printf("2. magenta\n");
		printf("3. cyan\n");
		printf("4. white\n");
		int ans;
		printf("정답을 입력하세요 : ");
		scanf("%d", &ans);
		switch(ans){
			case 1:
				if(r == 1 && g == 1 && b == 0)
					correct();
				else
					not_cor();
				break;
			case 2:
				if(r == 1 && g == 0 && b == 1)
					correct();
				else
					not_cor();
				break;
			case 3:
				if(r == 0 && g == 1 && b == 1)
					correct();
		
				else
					not_cor();
				break;
			case 4:
				if(r == 1 && g == 1 && b == 1)
					correct();
				else
					not_cor();
				break;
			case 0:
				printf("종료합니다");
				digitalWrite(LED_RED, 0);
				digitalWrite(LED_BLUE, 0);
				digitalWrite(LED_GREEN, 0);
				return 0;
		}
	}
}

					


