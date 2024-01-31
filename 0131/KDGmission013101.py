import RPi.GPIO as GPIO
import time
import random

red_pin = 4
green_pin = 5
blue_pin = 6

GPIO.setmode(GPIO.BCM)
GPIO.setup(red_pin, GPIO.OUT)
GPIO.setup(blue_pin, GPIO.OUT)
GPIO.setup(green_pin, GPIO.OUT)

def clear_pin():
    GPIO.output(red_pin, 0)
    GPIO.output(blue_pin, 0)
    GPIO.output(green_pin, 0)

def correct():
    clear_pin()
    GPIO.output(red_pin, 1)
    time.sleep(1)
    GPIO.output(green_pin, 1)
    time.sleep(1)
    GPIO.output(blue_pin, 1)
    time.sleep(1)
    clear_pin()


def not_cor():
    clear_pin()
    GPIO.output(red_pin, 1)
    time.sleep(0.5)
    GPIO.output(red_pin, 0)
    time.sleep(0.5)
    GPIO.output(red_pin, 1)
    time.sleep(0.5)
    GPIO.output(red_pin, 0)
    time.sleep(0.5)
    GPIO.output(red_pin, 1)
    time.sleep(0.5)
    GPIO.output(red_pin, 0)
    time.sleep(0.5)


def answer(x,r,g,b):
    if x == 1:
        if r == 1 and g == 1 and b == 0:
            correct()
        else:
            not_cor()
    elif x == 2:
        if r == 1 and g == 0 and b == 1:
            correct()
        else:
            not_cor()
    elif x == 3:
        if r == 0 and g == 1 and b == 1:
            correct()
        else:
            not_cor()
    elif x == 4:
        if r == 1 and g == 1 and b == 1:
            correct()
        else:
            not_cor()




try:
    while True:
        r = random.randrange(0,2)
        g = random.randrange(0,2)
        b = random.randrange(0,2)

        if r+g+b <= 1:
            continue
        GPIO.output(red_pin, bool(r))
        GPIO.output(green_pin, bool(g))
        GPIO.output(blue_pin, bool(b))

        print("1. yellow")
        print("2. magenta")
        print("3. cyan")
        print("4. white")
        print("답을 입력하세요 :",end="")
        ans = int(input())
        answer(ans, r, g, b)




    
except KeyboardInterrupt:
    pass

GPIO.cleanup()
