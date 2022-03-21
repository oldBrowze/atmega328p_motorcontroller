

#include "EXT_INT.hpp"
#include "Serial.hpp"

volatile bool EXT_INT::blocked_control = false; 
volatile uint16_t EXT_INT::count_interrupt = 0;

void EXT_INT::init()
{
    /*
        Используемые порты: 
        1. PD2 - INT0   - внешнее прерывание от оптического датчика
        2. PD3 - INT1   - внешнее прерывание от выхода Pololu FAULT
        3. PB4 - PCINT4 - прерывание от кнопки Start/Stop
        4. PB5 - PCINT5 - прерывание от кнопки reverse
    */
    EICRA   =   (0b10 << ISC00);  // спадающий фронт на ноге PD2, PD3
    EIMSK   =   (1 << INT0);          // включаем внешнее прерывание

    DDRD    &=  ~(1 << DD2);            // определяем пин на вход
    PORTD   |=  (1 << PD2);            // подтягиваем на питание

    PCICR   =   (1 << PCIE0);                       // включаем группу прерываний PCINT0/1 
    PCMSK0  =   (1 << PCINT4) | (1 << PCINT5);      // включаем прерывание PCINT0/1

    DDRB    &=  ~((1 << DD4) | (1 << DD5));            // определяем пин на вход
    PORTB   |=  (1 << PB4) | (1 << PB5);            // подтягиваем дополнительно на питание

    DDRD    |=   (1 << DD6) | (1 << DD5);
    PORTD   |=   (1 << PD6) | (1 << PD5);
}


ISR(PCINT0_vect)
{

    if((PINB & (1 << PB4)) == false) //stop
    {
        SerialPort::write(static_cast<unsigned char>('g')); 
        PORTD ^= (1 << PD5);
    }
    else if((PINB & (1 << PB5)) == false) //reverse
    {
        SerialPort::write(static_cast<unsigned char>('j'));
        PORTD ^= (1 << PD6);
    }
}


ISR(INT0_vect)
{
    EXT_INT::count_interrupt++;
    //SerialPort::write(static_cast<unsigned char>('C'));
}
