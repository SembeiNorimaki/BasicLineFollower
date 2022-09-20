/*
    Slave I2C test.
    Blinks the Builtin Led. 
    The delay in ms is set via I2C sending 2 bytes in
    Little endian format (MSB first, then LSB)
*/
#include<Wire.h>

const int ADDR = 0x09;
uint16_t rx = 1000;

void receiveEvent(int bytes) 
{
    rx = Wire.read() << 8;   // MSB first
    rx |= Wire.read();       // LSB second
}

void setup()
{
    Wire.begin(ADDR);
    Wire.onReceive(receiveEvent);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(rx);
    digitalWrite(LED_BUILTIN, LOW);
    delay(rx);
}