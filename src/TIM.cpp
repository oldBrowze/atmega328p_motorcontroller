#include "TIM.hpp"
#include "EXT_INT.hpp"
#include "Serial.hpp"
#include "ADC.hpp"
#include "common.hpp"

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

#ifdef __DEBUG__ENABLE 
    /*
    Каждые 5 сек. Считалось по даташиту для режима CTC
    */
    //настройка таймера 2
    OCR0A = 255;
    TCCR0A = (0b100 << WGM01);                              // режим CTC, до OCR0A
    TCCR0B = (0b101 << CS00);                               // коэфф. деления - 1024
    TIMSK0 = (0b1 << OCIE0A);                             // прерывание по совпадению


}

//тестбенч для составления графиков
ISR(TIMER0_COMPA_vect) // вызов каждую секунду(32)
{
    if(++TIM::_counter_interrupt == 305)    //обнуляем
    {
        //SerialPort::write(EXT_INT::count_interrupt);
        
        if(index < 21)
        {
            array_speed[index] = EXT_INT::count_interrupt;
            OCR1A = OCR1A + 50;
            ++index;
        }
        else
            is_blocked = true;
        TIM::_counter_interrupt = 0;
        EXT_INT::count_interrupt = 0;
    }
}
#else
}
#endif