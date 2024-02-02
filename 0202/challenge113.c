#include <wiringPi.h>
#include <stdio.h>
#include <termio.h>

#define BZR 24

//음계
#define RE 293.66
#define DO 261.63
#define MI 329.63
#define PA 349.23
#define SOL 391.00
#define LA 440.00
#define SI 493.88

int getch();


int main(){
    wiringPiSetup();
    pinMode(BZR, PWM_OUTPUT);
    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);
    char inp;
    while(1){
        inp = getch();
        switch(inp){
            case 'a':
                pwmSetRange(1000000/DO);
                pwmWrite(BZR, 1000000/DO/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 's':
                pwmSetRange(1000000/RE);
                pwmWrite(BZR, 1000000/RE/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 'd':
                pwmSetRange(1000000/MI);
                pwmWrite(BZR, 1000000/MI/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 'f':
                pwmSetRange(1000000/PA);
                pwmWrite(BZR, 1000000/PA/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 'g':
                pwmSetRange(1000000/SOL);
                pwmWrite(BZR, 1000000/SOL/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 'r':
                pwmSetRange(1000000/LA);
                pwmWrite(BZR, 1000000/LA/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 'l':
                pwmSetRange(1000000/SI);
                pwmWrite(BZR, 1000000/SI/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            case 'k':
                pwmSetRange(1000000/DO*2);
                pwmWrite(BZR, 1000000/DO*2/10);
                delay(500);
                pwmWrite(BZR, 0);
                break;
            default:
                break;
        }
    }
}

int getch(void){
    int ch;
    struct termios buf;
    struct termios save;

    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);

    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}