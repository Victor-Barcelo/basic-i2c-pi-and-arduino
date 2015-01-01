/**
 * PI (maestro) solicita 3 bytes a un Arduino (esclavo)
 * [pi] bytes = bus.read_i2c_block_data(address,0,3) -> Wire.onRequest(handler);
 * Suponemos un sensor analógico en el pin 0
 */

#include <Wire.h>

#define SLAVE_ADDRESS 0x04

const int SENSORPIN = 0;

void setup(){
    Serial.begin(9600);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData); //opcional
    Wire.onRequest(sendData);
    Serial.println("Ready!");
}

void loop(){
    delay(100);
}

void receiveData(int byteCount){
  	int cmd = Wire.read();
  	if(cmd == 0)
  	{
    	//código
  	}
}

void sendData(){
    byte dataSend[] = {analogRead(SENSORPIN),1,2}; //1 y 2 son bytes arbitrarios
 	Wire.write(dataSend, 3);        
}