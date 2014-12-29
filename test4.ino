/**
 * PI (maestro) envía 3 bytes a un Arduino (esclavo)
 * [pi] bus.write_i2c_block_data(address, 0, bytes) -> [arduino] Wire.onReceive(handler(int byteCount));
 */

#include <Wire.h>

#define SLAVE_ADDRESS 0x04

int number = 0;

void setup() {
    Serial.begin(9600);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Serial.println("Ready!");
}

void loop(){
    delay(100);
}

void receiveData(int byteCount){
    while(Wire.available()) {
        number = Wire.read();
        Serial.print(number);
     }
}