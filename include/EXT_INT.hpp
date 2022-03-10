#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

class EXT_INT
{
private:
    EXT_INT() = delete;
public: 
    static volatile bool blocked_control; // Если флаг взведен, реакции на потенциометр нет. 
    static volatile uint16_t count_interrupt; // количество оборотов, который засек датчик
    static void init();
};