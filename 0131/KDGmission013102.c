#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22

void Make_LED(int n, int *arr){
	srand((unsigned int)time(NULL));
	for(int i = 0;i<n;i++){
		int ran = rand()%3;
		switch (ran){
			case 0:
				arr[i] = LED_RED;
				break;
			case 1:
				arr[i] = LED_GREEN;
				break;
			case 2:
				arr[i] = LED_BLUE;
				break;

		}
	}
}

void Clear_LED(){
	digitalWrite(LED_RED, 0);
	digitalWrite(LED_GREEN, 0);
	digitalWrite(LED_BLUE, 0);
}

int main(void){
	if(wiringPiSetup() == -1)
		return 1;

	pinMode(LED_RED, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_BLUE, OUTPUT);

	Clear_LED();
	int *arr;
	int n;
	arr = (int *)malloc(sizeof(int)*n);
	printf("몇 개를 도전하시겠습니까? ");
	scanf("%d", &n);
	while(getchar() != '\n');
	Make_LED(n, arr);
	printf("Press any Key");
	while(getchar() != '\n');
	for(int i = 0;i<n;i++){
		digitalWrite(arr[i], 1);
		usleep(500000);
		digitalWrite(arr[i], 0);
		usleep(500000);
	}
	printf("정답을 입력해주세요 \n");
	char *answer = (char *)malloc(sizeof(char)*n);
	for(int i =0;i<n;i++){
		answer[i] = getchar();
	}
	//for(int i = 0;i<n;i++){
	//	printf("%c", answer[i]);
	//}
	int count = 0;
	for(int i =0;i<n;i++){
		if(answer[i] == 'r'){
			if(arr[i] != LED_RED) count++;
		}
		if(answer[i] == 'g'){
			if(arr[i] != LED_GREEN) count++;
		}
		if(answer[i] == 'b'){
			if(arr[i] != LED_BLUE) count++;
		}
	}
	if(count == 0){
		digitalWrite(LED_GREEN, 1);
		usleep(1000000);
		digitalWrite(LED_GREEN, 0);
	}
	else{
		digitalWrite(LED_RED, 1);
		usleep(1000000);
		digitalWrite(LED_RED, 0);
	}
	free(arr);
	free(answer);
	return 0;

}
