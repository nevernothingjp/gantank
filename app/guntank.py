import webiopi
import subprocess as proc
webiopi.setDebug()
GPIO = webiopi.GPIO
MOTOR_RIGHT_FORWARD = 2
MOTOR_RIGHT_BACK = 3
MOTOR_LEFT_FORWARD = 4
MOTOR_LEFT_BACK = 14
MOTOR_STOP = 15
SHUTDOWN = 18

def setup():
  GPIO.setFunction(MOTOR_RIGHT_FORWARD, GPIO.OUT)
  GPIO.setFunction(MOTOR_RIGHT_BACK, GPIO.OUT)
  GPIO.setFunction(MOTOR_LEFT_FORWARD, GPIO.OUT)
  GPIO.setFunction(MOTOR_LEFT_BACK, GPIO.OUT)
  GPIO.setFunction(MOTOR_STOP, GPIO.OUT)
  GPIO.setFunction(SHUTDOWN, GPIO.OUT)

def allLow():
  GPIO.digitalWrite(MOTOR_LEFT_FORWARD, GPIO.LOW)
  GPIO.digitalWrite(MOTOR_LEFT_BACK, GPIO.LOW)
  GPIO.digitalWrite(MOTOR_RIGHT_FORWARD, GPIO.LOW)
  GPIO.digitalWrite(MOTOR_RIGHT_BACK, GPIO.LOW)

def destroy():
  allLow()
  GPIO.digitalWrite(MOTOR_STOP, GPIO.LOW)
  GPIO.digitalWrite(SHUTDOWN, GPIO.LOW)

@webiopi.macro
def home():
  allLow()
  GPIO.digitalWrite(MOTOR_STOP, GPIO.LOW)
  GPIO.digitalWrite(SHUTDOWN, GPIO.LOW)

@webiopi.macro
def stop():
  allLow()

@webiopi.macro
def leftForwad():
  allLow()
  GPIO.digitalWrite(MOTOR_RIGHT_FORWARD, GPIO.HIGH)

@webiopi.macro
def forwad():
  allLow()
  GPIO.digitalWrite(MOTOR_LEFT_FORWARD, GPIO.HIGH)
  GPIO.digitalWrite(MOTOR_RIGHT_FORWARD, GPIO.HIGH)

@webiopi.macro
def rightForwad():
  allLow()
  GPIO.digitalWrite(MOTOR_LEFT_FORWARD, GPIO.HIGH)

@webiopi.macro
def leftTurn():
  allLow()
  GPIO.digitalWrite(MOTOR_LEFT_BACK, GPIO.HIGH)
  GPIO.digitalWrite(MOTOR_RIGHT_FORWARD, GPIO.HIGH)

@webiopi.macro
def rightTurn():
  allLow()
  GPIO.digitalWrite(MOTOR_RIGHT_BACK, GPIO.HIGH)
  GPIO.digitalWrite(MOTOR_LEFT_FORWARD, GPIO.HIGH)

@webiopi.macro
def leftBack():
  allLow()
  GPIO.digitalWrite(MOTOR_RIGHT_BACK, GPIO.HIGH)

@webiopi.macro
def back():
  allLow()
  GPIO.digitalWrite(MOTOR_RIGHT_BACK, GPIO.HIGH)
  GPIO.digitalWrite(MOTOR_LEFT_BACK, GPIO.HIGH)

@webiopi.macro
def rightBack():
  allLow()
  GPIO.digitalWrite(MOTOR_LEFT_BACK, GPIO.HIGH)

