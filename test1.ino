/**
 * PI (maestro) solicita 1 byte a un Arduino (esclavo)
 * [pi] byte = bus.read_byte(address) -> [arduino] Wire.onRequest(handler)
 * Suponemos un sensor analógico en el pin 0
 * */

#include <Wire.h>

#define SLAVE_ADDRESS 0x04

const int SENSORPIN = 0;

void setup(){
    Serial.begin(9600);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onRequest(sendData);
    Serial.println("Ready!");
}

void loop(){
    delay(100);
}

void sendData(){
    Wire.write(analogRead(SENSORPIN));
}