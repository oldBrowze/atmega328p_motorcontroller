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
    enum ADC_Channel : const uint8_t
    {
        ADC0 = 0x00,
        ADC1,
        ADC2,
        ADC3,
        ADC4,
        ADC5,
        ADC6,
        ADC7
    };

    static void init();
    static inline void set_channel(const ADC_Channel& channel)
    {
        //if(channel > 0b111) return;
        ADMUX = channel;
    }
    [[deprecated]]
    static inline const volatile uint8_t get_channel()
    {
        return (ADMUX & 0xF);
    }
};