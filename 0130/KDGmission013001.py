import time
import RPi.GPIO as GPIO

red_pin = 4
green_pin = 5
blue_pin = 6

GPIO.setmode(GPIO.BCM)
GPIO.setup(red_pin, GPIO.OUT)
GPIO.setup(green_pin, GPIO.OUT)
GPIO.setup(blue_pin, GPIO.OUT)
try:
    for i in range(1,20):
        GPIO.output(red_pin, True)
        time.sleep(0.5)
        GPIO.output(red_pin, False)
        GPIO.output(green_pin, True)
        time.sleep(0.5)
        GPIO.output(green_pin, False)
        GPIO.output(blue_pin, True)
        time.sleep(0.5)
        GPIO.output(blue_pin, False)
        time.sleep(0.5)
except KeyboardInterrupt:
    pass
GPIO.cleanup()
