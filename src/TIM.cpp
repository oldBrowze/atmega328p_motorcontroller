#include "TIM.hpp"
#include "EXT_INT.hpp"
#include "Serial.hpp"
#include "ADC.hpp"

//#define __DEBUG__ENABLE 

void TIM::timer_init()
{
    //настройка таймера 1
    //TCCR1A = 0;
    TCCR1A = (1 << COM1A1) | 
                (0 << COM1A0) |                             // non-inverting mode fast pwm
                (1 << WGM12) | 
                (1 << WGM11) |
                (1 << WGM10);     

    TCCR1B = 0x1;                                           // Частота без предделителя     
}