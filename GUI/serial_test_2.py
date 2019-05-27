import serial, time
import os

def serialcmdw():
    os.system('clear')
    serialcmd = input("serial command: ")
    ser.write (serialcmd.encode())
    serialcmdw()

ser = serial.Serial()
os.system('clear')
ser.port = "COM13"
ser.baudrate = 9600
ser.close()
ser.open()
# time.sleep(1)
serialcmdw()