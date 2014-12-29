# PI (maestro) solicita 3 bytes a un Arduino (esclavo)
# [pi] bytes = bus.read_i2c_block_data(address,0,3) -> Wire.onRequest(handler);

import smbus
import time

bus = smbus.SMBus(1)
address = 0x04

def readList():
    bytes = bus.read_i2c_block_data(address,0,3)
    return bytes

while True:

    time.sleep(0.5)
    bytes = readList()
    print "Arduino: Hey RPI, I received a list of bytes ", bytes
    print