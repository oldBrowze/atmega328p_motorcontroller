

#include "EXT_INT.hpp"
#include "Serial.hpp"

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
    EICRA   =   (0b10 << ISC00) | (0b10 << ISC10);  // спадающий фронт на ноге PD2, PD3
    EIMSK   =   (1 << INT0) | (1 << INT1);          // включаем внешнее прерывание

    DDRD    &=  ~((1 << DD2) | (1 << DD3));         // определяем пин на вход
    PORTD   |=  (1 << PD2) | (1 << PD3);            // подтягиваем на питание

    PCICR   =   (1 << PCIE0) | (1 << PCIE1);        // включаем группу прерываний PCINT0/1 
    PCMSK0  =   (1 << PCINT4) | (1 << PCINT5);      // включаем прерывание PCINT0/1

    DDRB    &=  ~((1 << DD4));                      // определяем пин на вход
    PORTB   |=  (1 << PB4);                         // подтягиваем дополнительно на питание

    DDRD    |=   (1 << DD6) | (1 << DD5);           // выход на start/stop
    PORTD   |=   (1 << PD6) | (1 << PD5);           // выход на реверс
}


ISR(PCINT0_vect)
{
    if((PINB & (1 << PB4)) == false)
        //SerialPort::write(static_cast<uint8_t>(0xC)); 
    ++EXT_INT::count_interrupt;
}

ISR(INT0_vect)
{
    SerialPort::write(static_cast<uint8_t>(0xE)); 
    PORTD ^= (1 << PD5);
}

ISR(INT1_vect)
{
    SerialPort::write(static_cast<uint8_t>(0xD)); 
    PORTD ^= (1 << PD6);
}
