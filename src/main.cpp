#define F_CPU 16000000L     //тактовая частота МК

#include <avr/io.h>
#include <avr/interrupt.h>


#include "ADC.hpp"
#include "TIM.hpp"
#include "EXT_INT.hpp"

#include "Serial.hpp"


int main()
{
    sei();

    __ADC::init();
    TIM::port_init();
    TIM::timer_init();
    EXT_INT::init();

    SerialPort::connect();

    
    while(true) 
    {
        OCR1A = __ADC::get_result(0x0);
        SerialPort::write(__ADC::get_result(0x1));
    }

    return 0;
}