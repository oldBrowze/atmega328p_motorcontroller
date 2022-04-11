#pragma once
 
#include <avr/io.h>
#include <avr/interrupt.h>

/*
    Для общения с ПК для дебага.
    В основной код не входит
*/
class SerialPort
{
private:
    SerialPort() = delete;
public:
    static void write(const uint8_t);
    static void write(const unsigned char [], const __SIZE_TYPE__ &size);
    static void write(const volatile uint16_t);
    static void connect();
};
