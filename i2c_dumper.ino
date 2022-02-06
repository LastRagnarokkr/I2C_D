#include <Wire.h>

#define AT24C256_ADDR 0x50

void setup() {
  unsigned long Flashsize = 0x8000; 
  byte r = 0;
  //512pages * 64bytes = 32 768bytes (0x8000) * 8 = 262 144bits
  //1024pages*32bytes=0x8000
  
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000L); //set clock speed at 400 kHz
  
  delayMicroseconds(500);
  Serial.println("Set baud to 115200. Clocked for 400kHz.");
  Serial.println("Waiting for input character to start...");

    while (!Serial.available()) {
    // Loop until a character sent via serial
  }
  
  Wire.beginTransmission(AT24C256_ADDR);
  Wire.write(0x00); //Set the start address for use in the upcoming reads
  Wire.endTransmission();
 
  for(int i = 0; i < 1024; i++){
    Wire.requestFrom(AT24C256_ADDR, 32); //read 32 bytes at a time as buffer limit is 32 bytes
	
	while (Wire.available()){
		r = Wire.read();
		Serial.print(r, BIN); //use Serial.print(value,byte) for ASCII characters
	}
  }
  
  Serial.println("Reading operation is finished.");
  
}

void loop() {
 
}
