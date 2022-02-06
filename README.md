# I2C_D
Its a 15-minute-wonder I2C dumper for the Arduino!

For logging, using either Putty or Realterm to capture serial will work.
Note that Arduino will always push ASCII instead of Raw data up the serial stream. 

Instructions for use:
1. Read your EEPROM datasheet
2. Define device address (variable: AT24C256_ADDR your_value)
3. Set desired baud rate with Serial.begin(your_value)
4. The clock defaults to 100 kHz when Wire.begin function is called. Edit the code as neccessary for your applications
5. PageSize: maximum is 32 bytes due to limited buffersize, anything above is truncated by the Arduino
6. PageAmount: Set loop limit


In the future:
-I want to add interactive settings
-Attempt to fix the problem of ASCII serial
-Add functionality for SPI
