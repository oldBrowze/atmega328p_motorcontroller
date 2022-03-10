#include "PWM.hpp"

void __PWM::init()
{
    //настройка таймера 1
    TCCR1A = (1 << COM1A1) | 
                (0 << COM1A0) |                             // non-inverting mode fast pwm
                (1 << WGM12) | 
                (1 << WGM11) | 
                (1 << WGM10);                               // Fast PWM 10-bit(as ADC resolution)

    TCCR1B = (1 << CS10);                                   // Частота без предделителя     
    /*
        Частота таймера: f = F_CPU / (1 * 2^resolution_PWM) = 15.625 kHz

    */
   OCR1A = 512;
   
    //настройка таймера 2
}