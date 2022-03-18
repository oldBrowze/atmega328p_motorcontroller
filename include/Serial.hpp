#pragma once
 
#include <avr/io.h>
#include <avr/interrupt.h>

class SerialPort
{
private:
    SerialPort() = delete;
public:
    static void write(const unsigned char &);
    static void write(const unsigned char [], const __SIZE_TYPE__ &size);
    static void connect();
};
