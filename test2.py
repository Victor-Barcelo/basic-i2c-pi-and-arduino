# PI (maestro) envía 1 byte a un Arduino (esclavo)
# [pi] bus.write_byte(address, value) -> [arduino] Wire.onReceive(handler(int byteCount));

import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

address = 0x04

def writeNumber(value):
    bus.write_byte(address, value)
    return -1

while True:
    var = input("Introduce un valor 1 - 9: ")
    if not var:
        continue

    writeNumber(var)
    print "RPI mandando a Arduino: ", var
    time.sleep(1)