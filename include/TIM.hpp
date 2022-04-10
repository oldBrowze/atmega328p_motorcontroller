#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

class Timer_Operations;
using TIM = Timer_Operations;

class Timer_Operations
{
private:
    Timer_Operations() = delete;

public:
    static volatile inline uint16_t _counter_interrupt = 0;
    static void timer_init();
    static inline void port_init()
    {
        DDRB |= (1 << PB1);
    }
};