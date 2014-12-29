# PI (maestro) solicita 1 byte a un Arduino (esclavo)
# [pi] byte = bus.read_byte(address) -> [arduino] Wire.onRequest(handler)
 
import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

address = 0x04

def readNumber():
    number = bus.read_byte(address)
    return number

while True:

    time.sleep(0.5)
    number = readNumber()
    print "RPI recibiendo de Arduino:  ", number
    print