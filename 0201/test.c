/* memory game */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <stdint.h>
#include <unistd.h>

/* BCM 6 13 19 26 */
#define SW1 3 
#define SW2 23
#define SW3 24
#define SW4 25

/* BCM 23 24 25 4 */
#define RED_LED 4
#define GREEN_LED 5
#define BLUE_LED 6

#define BUZZER 7

#define RED_BUZZER 262
#define GREEN_BUZZER 294
#define BLUE_BUZZER 330

#define MAX_PATTERN_SIZE 10
#define LED_SIZE 3

const unsigned char available_leds[LED_SIZE] = {RED_LED, GREEN_LED, BLUE_LED};
unsigned char pattern[MAX_PATTERN_SIZE] = {};
unsigned int score = 0;

void setup_pins(void)
{
	wiringPiSetup();

	/* switch gpio */
	pinMode(SW1, INPUT);
	pinMode(SW2, INPUT);
	pinMode(SW3, INPUT);
	pinMode(SW4, INPUT);

	/* led gpio */
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(BLUE_LED, OUTPUT);

	/* buzzer gpio */
	pinMode(BUZZER, PWM_OUTPUT);
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
}

void clear_all(void)
{
	/* clear led */
	digitalWrite(RED_LED, LOW);
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(BLUE_LED, LOW);

	/* clear buzzer */
	pwmWrite(BUZZER, LOW);
}

void create_pattern(unsigned char pattern_length)
{
	unsigned char i = 0;

	for (i = 0; i < pattern_length; ++i)
	{
		pattern[i] = available_leds[(unsigned char)rand() % 3];
	}
}

void play_buzzer(unsigned int duration, unsigned char led)
{
	switch(led)
	{
		case RED_LED:
			pwmWrite(BUZZER, RED_BUZZER);
			delay(duration);
			pwmWrite(BUZZER, LOW);
			break;
		case GREEN_LED:
			pwmWrite(BUZZER, GREEN_BUZZER);
			delay(duration);
			pwmWrite(BUZZER, LOW);
			break;
		case BLUE_LED:
			pwmWrite(BUZZER, BLUE_BUZZER);
			delay(duration);
			pwmWrite(BUZZER, LOW);
			break;
		default:
			break;
	}
}

char play_game(void)
{
	unsigned char i = 0;
	unsigned char pattern_size = 4;
	char user_input = 0;
	char answer_flag = 1;

	create_pattern(pattern_size);

	for (i = 0; i < pattern_size; ++i)
	{
		digitalWrite(pattern[i], HIGH);
		play_buzzer(500, pattern[i]);
		digitalWrite(pattern[i], LOW);
		delay(300);
	}

	/* get player's input */
	for (user_input = pattern_size; user_input != 0;)
	{
		if (digitalRead(SW1) == LOW)
		{
			printf("SW1 pressed!\n");
			user_input--;
			if (pattern[i] != RED_LED && answer_flag == 1)
				answer_flag = 0;
			delay(100);
		}
		/*else if (digitalRead(SW2) == LOW)
		{
			printf("SW2 pressed!\n");
			user_input--;
			if (pattern[i] != GREEN_LED && answer_flag == 1)
				answer_flag = 0;
			delay(100);
		}
		else if (digitalRead(SW3) == LOW)
		{
			printf("SW3 pressed!\n");
			user_input--;
			if (pattern[i] != BLUE_LED && answer_flag == 1)
				answer_flag = 0;
			delay(100);
		}
		else if (digitalRead(SW4) == LOW)
		{
			printf("SW4 pressed!\n");
			user_input = 0;
			// end game
			answer_flag = 2;
			break;
		}*/
	}

	return answer_flag;
}

void wrong(void)
{
	unsigned char i = 0;
	for (i = 0; i < 3; ++i)
	{
		digitalWrite(RED_LED, HIGH);
		delay(280);
		digitalWrite(RED_LED, LOW);
	}
}

void correct(void)
{
	unsigned char i = 0;
	for (i = 0; i < 3; ++i)
	{
		digitalWrite(GREEN_LED, HIGH);
		delay(280);
		digitalWrite(GREEN_LED, LOW);
	}
	
}

int main(void)
{
	char flag = 0;
	setup_pins();
	
	srand((unsigned)time(NULL));

	while(1)
	{
		// clear_all();
		flag = play_game();
		printf("Flag : %d\n", flag);
		switch (flag)
		{
			case 0:
				wrong();
				break;
			case 1:
				correct();
				score++;
				break;
			case 2:
				// done print score 
				printf("Your score is : %d\n", score);
				break;
			default:
				break;
		}
	}

	return 0;
}

