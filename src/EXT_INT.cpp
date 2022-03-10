#include "EXT_INT.hpp"

void EXT_INT::init()
{
    /*
    Допустимые порты: 
    1. PD2 - INT0
    2. PD3 - INT1
    */
    EICRA = (0b10 << ISC00) | (0b10 << ISC01);      // спадающий фронт на ноге PD2, PD3
    EIMSK = (1 << INT0) | (1 << INT1);              // включаем внешнее прерывание

    DDRD    |= (0 << DD2) | (0 << DD3);             // определяем пин на вход
    PORTD   |= (1 << PD2) | (1 << PD2);             // подтягиваем на питание

}

ISR(INT0_vect)
{
/*
    Прерывание по низкому сигналу оптического датчика
*/
    
}

ISR(INT1_vect)
{
    using namespace EXT_INT;
    /*
    Прерывание по изменению FAULT
    Отключаем работу ШИМ
    */
    if(blocked_control == false)
        OCR1A = 0;
        
    EXT_INT::blocked_control = !EXT_INT::blocked_control;

}