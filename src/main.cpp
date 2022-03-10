#define F_CPU 16000000L     //тактовая частота МК

#include <avr/io.h>
#include <avr/interrupt.h>

#include "ADC.hpp"
#include "PWM.hpp"
#include "EXT_INT.hpp"


int main()
{
    sei();
    
    __ADC::init();
    __PWM::port_init();
    __PWM::init();
    EXT_INT::init();

 
    while(true) {}
    return 0;
}