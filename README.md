# I2C_D
Its a 15-minute-wonder I2C dumper for the Arduino!

For logging, using either Putty or Realterm to capture serial will work.
Note that Arduino will always push ASCII instead of Raw data up the serial stream. 

Instructions for use:
1. Read your EEPROM datasheet
2. Define device address (variable: DEV_ADDR your_value)
3. Set desired baud rate with Serial.begin(your_value). Default is 9600
4. The clock defaults to 100 kHz when Wire.begin function is called. Edit the code as neccessary for your applications
5. PAGESIZE: maximum is 32 bytes due to limited buffersize, anything above is truncated by the Arduino
6. PAGEAMOUNT: Set loop limit


Future improvements:
- Add interactive settings
- Add read functionality for SPI protocol
- Add R/W functionality for I2C + SPI
- Check if adding UART and JTAG functionality is feasible
- Check if all of this can be fit inside the limited memory


(non-affiliated) Links for additional function reference:
- Wire.h library: https://playground.arduino.cc/Main/WireLibraryDetailedReference/#requestFrom
- Discussion about Serial.print vs. Serial.write: https://forum.arduino.cc/t/serial-print-or-serial-write/42715
