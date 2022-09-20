/*
    I2C Master test.
    When an integer is send via serial port,
    it resends it via I2C to a slave in two bytes
    Little endian format (MSB first, then LSB)
*/

#include <Wire.h>
#include<Streaming.h>

const int ADDR = 0x09;
void setup()
{
    Serial.begin(115200);
    Wire.begin();
}

void loop()
{
}

void SerialEvent()
{
    int rx = Serial.parseInt();
    Serial << "Received: " << rx << endl;
    
    uint8_t msb = (uint8_t)(rx & 0x00F0 >> 8);
    uint8_t lsb = (uint8_t)(rx & 0x000F);
    
    Wire.beginTransmission(ADDR);
    Wire.write(msb);
    Wire.write(lsb);
    Wire.endTransmission();
}