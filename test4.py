# PI (maestro) envía 3 bytes a un Arduino (esclavo)
# [pi] bus.write_i2c_block_data(address, 0, bytes) -> [arduino] Wire.onReceive(handler(int byteCount));

import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

address = 0x04

def writeBytes(bytes):
    bus.write_i2c_block_data(address, 0, bytes)
    return -1

while True:
    bytes = [0x04, 0x05, 0x06]
    writeBytes(bytes)
    print "RPI mandando a Arduino: ", bytes
    time.sleep(1)