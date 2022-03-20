#pragma once

#include <avr/io.h>
//#include <avr/interrupt.h>

class ADC_Operations;
using __ADC = ADC_Operations;

class ADC_Operations
{
private:
    ADC_Operations() = delete;
public:    
    static void init();
    static uint16_t get_result(const uint8_t);
    [[deprecated]]
    static inline const volatile uint8_t get_channel()
    {
        return (ADMUX & 0xF);
    }
};