#include "Serial.hpp"

void SerialPort::write(const uint8_t message)
{
    while(!(UCSR0A & (1 << UDRE0)));

    UDR0 = message;

    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = '\n';
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = '\r';

    //nop!
}
void SerialPort::write(const unsigned char message[], const __SIZE_TYPE__ &size)
{
    for(__SIZE_TYPE__ index = 0; index < size; ++index)
    {
        while(!(UCSR0A & (1 << UDRE0)));

        UDR0 = message[index];
    }
    
    
}
void SerialPort::write(const volatile uint16_t value)
{
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = static_cast<uint8_t>(value >> 8);

    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = static_cast<uint8_t>(value & 0xFF);

    /*
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = '\n';
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = '\r';
    */
}

void SerialPort::connect()
{

    UBRR0 = 103; //9600
    UCSR0C = (0b11 << UCSZ00) | // 8bit
            (0b0 << USBS0);     // 1-bit stops
    
    UCSR0B = (1 << TXEN0);

}