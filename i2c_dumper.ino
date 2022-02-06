#include <Wire.h>

#define DEV_ADDR 0x50 //0x50 for when all pins are floating or grounded (with AT24C256)

void setup() {
  int PAGESIZE = 32; //BUFFER is limited to 32 bytes!
  int PAGEAMOUNT = 1024;
  byte R = 0;
  
  Serial.begin(9600); //Baud rate is set to 9600
  Wire.begin();
  //Wire.setClock(400000L); //set clock speed to 400 kHz
  
  delayMicroseconds(500);
  Serial.println("Set baud to 115200. Clocked for 400kHz.");
  Serial.println("Waiting for input character to start...");

    while (!Serial.available()){
    // Loop until a character sent via serial
  }
  
  Wire.beginTransmission(DEV_ADDR);
  Wire.write(0x00); //Set the start address for use in the upcoming reads
  Wire.endTransmission();
 
  for(int i = 0; i < PAGEAMOUNT; i++){
    Wire.requestFrom(DEV_ADDR, PAGESIZE); //read 32 bytes at a time as buffer limit is 32 bytes
	
	while (Wire.available()){
		R = Wire.read();
		Serial.print(R, BIN); //use Serial.print(value,byte) for ASCII characters
	}
  }
  
  Serial.println("Reading operation is finished.");
  
}

void loop() {
 
}
