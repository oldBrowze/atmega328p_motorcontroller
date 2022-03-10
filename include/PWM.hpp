#pragma once

#include <avr/io.h>

class PWM_Operations;
using __PWM = PWM_Operations;

class PWM_Operations
{
private:
    PWM_Operations() = delete;

public:
    static void init();
    static inline void port_init()
    {
        DDRB |= (1 << PB1);
    }
};