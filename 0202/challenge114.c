#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wiringPi.h>

#define STEP_A 27
#define STEP_B 0
#define STEP_2A 1
#define STEP_2B 24
// q 0 w 90 e 180
int main(void) {
    int angle, i;
    wiringPiSetup();
    pinMode(STEP_A, OUTPUT);
    pinMode(STEP_B, OUTPUT);
    pinMode(STEP_2A, OUTPUT);
    pinMode(STEP_2B, OUTPUT);
    digitalWrite(STEP_2B, 0);
    digitalWrite(STEP_2A, 0);
    digitalWrite(STEP_B, 0);
    digitalWrite(STEP_A, 0);
    while (1) {
        printf("q : 0, w : 90, e : 180");
        scanf("%c", &angle);
        while (getchar() != '\n');
        if (angle == 'w') {
            for (int i = 0; i < 129; i++) {
                digitalWrite(STEP_A, 1);
                usleep(2000);
                digitalWrite(STEP_A, 0);
                digitalWrite(STEP_B, 1);
                usleep(2000);
                digitalWrite(STEP_B, 0);
                digitalWrite(STEP_2A, 1);
                usleep(2000);
                digitalWrite(STEP_2A, 0);
                digitalWrite(STEP_2B, 1);
                usleep(2000);
                digitalWrite(STEP_2B, 0);
            }
        }
        else if (angle == 'e') {
            for (int i = 0; i < 258; i++) {
                digitalWrite(STEP_A, 1);
                usleep(2000);
                digitalWrite(STEP_A, 0);
                digitalWrite(STEP_B, 1);
                usleep(2000);
                digitalWrite(STEP_B, 0);
                digitalWrite(STEP_2A, 1);
                usleep(2000);
                digitalWrite(STEP_2A, 0);
                digitalWrite(STEP_2B, 1);
                usleep(2000);
                digitalWrite(STEP_2B, 0);
            }
        }
    }
}