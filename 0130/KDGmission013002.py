import RPi.GPIO as GPIO
import time

led_pin = 4
GPIO.setmode(GPIO.BCM)
GPIO.setup(led_pin, GPIO.OUT)

def bright(x):
    l = x * 100
    for i in range(0, l):
        j = int(i / (x*10))
        GPIO.output(led_pin, False)
        time.sleep(0.01-(j/1000))
        GPIO.output(led_pin, True)
        time.sleep(j/1000)
    GPIO.output(led_pin, False)

def dark(x):
    l = x * 100
    for i in range(0, l):
        j = int(i / (x*10))
        GPIO.output(led_pin, False)
        time.sleep(j/1000)
        GPIO.output(led_pin, True)
        time.sleep(0.01-(j/1000))
    GPIO.output(led_pin, False)
try:
    while True: 
        print("원하는 숫자입력 : ",end='')
        x = input()
        x = int(x)
        if x == 1:
            GPIO.output(led_pin, True)

        elif x == 2:
            GPIO.output(led_pin, False)
        
        elif x == 3:
            bright(3)

        elif x == 4:
            dark(3)

        elif x == 5:
            bright(3)
            dark(3)

        elif x == 6:
            y = input()
            y = int(y)
            bright(y/2)
            dark(y/2)

        elif x == 0:
            break
        

except KeyboardInterrupt:
    pass

GPIO.cleanup()


