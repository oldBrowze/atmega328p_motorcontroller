#include "TIM.hpp"
#include "EXT_INT.hpp"
#include "SETTINGS.hpp"

void TIM::timer_init()
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
   
    OCR3A = 15626;
    /*
    Время, через которое вызовется прерывание, определится:
    t = resolution / (OCR3A + 1)
    (OCR3A + 1) = t / resolution
    (OCR3A + 1) = 1s / (1 * prescale / F_CPU) = 15626
    OCR3A = 15626 - 1 = 15625.
    */
    TCCR3A = (0b00 << COM3B0) |                             // порты отключены
                (0b100 << WGM30);                           // режим CTC, до OCR3A
    TCCR3B = (0b101 << CS30);                               // коэфф. деления - 1024
    TIMSK3 = (0b1 << OCIE3A);                               // прерывание по совпадению

}


ISR(TIMER3_COMPA_vect) // вызов каждую секунду
{
    if(EXT_INT::count_interrupt * KOEFFICIENT_OF_SPEED < 5) //изменить на ожидаемое кол-во оборотов при N-ом напряжении

    EXT_INT::count_interrupt = 0;
}