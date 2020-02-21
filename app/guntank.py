import webiopi
import subprocess as proc
webiopi.setDebug()
GPIO = webiopi.GPIO
MORTOR_RIGHT_FORWARD = 2
MORTOR_RIGHT_BACK = 3
MORTOR_LEFT_FORWARD = 4
MORTOR_LEFT_BACK = 14
MORTOR_STOP = 15
SHUTDOWN = 18
def setup():
  GPIO.setFuntion(MORTOR_RIGHT_FORWARD, GPIO.OUT)
  GPIO.setFuntion(MORTOR_RIGHT_BACK, GPIO.OUT)
  GPIO.setFuntion(MORTOR_LEFT_FORWARD, GPIO.OUT)
  GPIO.setFuntion(MORTOR_LEFT_BACK, GPIO.OUT)
  GPIO.setFuntion(MORTOR_STOP, GPIO.OUT)
  GPIO.setFuntion(SHUTDOWN, GPIO.OUT)

def allLow():
  GPIO.digitalWrite(MORTOR_LEFT_FORWARD, GPIO.LOW)
  GPIO.digitalWrite(MORTOR_LEFT_BACK, GPIO.LOW)
  GPIO.digitalWrite(MORTOR_RIGHT_FORWARD, GPIO.LOW)
  GPIO.digitalWrite(MORTOR_LEFT_BACK, GPIO.LOW)

def destroy():
  allLow()
  GPIO.digitalWrite(MORTOR_STOP, GPIO.LOW)
  GPIO.digitalWrite(SHUTDOWN, GPIO.LOW)

@webiopi.macro
def home():
  allLow()
  GPIO.digitalWrite(MORTOR_STOP, GPIO.LOW)
  GPIO.digitalWrite(SHUTDOWN, GPIO.LOW)

@webiopi.macro
def stop():
  allLow()

@webiopi.macro
def leftForwad():
  allLow()
  GPIO.digitalWrite(MORTOR_RIGHT_FORWARD, GPIO.HIGH)

@webiopi.macro
def forwad():
  allLow()
  GPIO.digitalWrite(MORTOR_LEFT_FORWARD, GPIO.HIGH)
  GPIO.digitalWrite(MORTOR_RIGHT_FORWARD, GPIO.HIGH)

@webiopi.macro
def rightForwad():
  allLow()
  GPIO.digitalWrite(MORTOR_LEFT_FORWARD, GPIO.HIGH)

@webiopi.macro
def leftTurn():
  allLow()
  GPIO.digitalWrite(MORTOR_LEFT_BACK, GPIO.HIGH)
  GPIO.digitalWrite(MORTOR_RIGHT_FORWARD, GPIO.HIGH)

@webiopi.macro
def rightTurn():
  allLow()
  GPIO.digitalWrite(MORTOR_LEFT_FORWARD, GPIO.HIGH)
  GPIO.digitalWrite(MORTOR_RIGHT_BACK, GPIO.HIGH)

@webiopi.macro
def leftBack():
  allLow()
  GPIO.digitalWrite(MORTOR_RIGHT_BACK, GPIO.HIGH)

@webiopi.macro
def back():
  allLow()
  GPIO.digitalWrite(MORTOR_LEFT_BACK, GPIO.HIGH)
  GPIO.digitalWrite(MORTOR_RIGHT_BACK, GPIO.HIGH)

@webiopi.macro
def rightBack():
  allLow()
  GPIO.digitalWrite(MORTOR_LEFT_BACK, GPIO.HIGH)
