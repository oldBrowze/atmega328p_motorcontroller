#define F_CPU 16000000L     //тактовая частота МК

#include <avr/io.h>
#include <avr/interrupt.h>


#include "ADC.hpp"
#include "TIM.hpp"
#include "EXT_INT.hpp"

#include "Serial.hpp"
#include "common.hpp"

//#define __DEBUG__ENABLE 
int main()
{
    sei();

    __ADC::init();
    TIM::port_init();
    TIM::timer_init();
    EXT_INT::init();

    SerialPort::connect();
    
    #ifdef __DEBUG_ENABLE
    bool is_stop = false;


    PORTD ^= (1 << PD5);
    OCR1A = 50;
    #endif
    
    while(true) 
    {
        OCR1A = __ADC::get_result(0x0u);
        
        #ifdef __DEBUG_ENABLE
        if(!is_blocked) 
            array_current[index] = __ADC::get_result(1);
        else if(!is_stop)
        {
            for(uint8_t idx = 0; idx < 21; ++idx)
            {
                SerialPort::write(array_speed[idx]);
                SerialPort::write(static_cast<uint8_t>(0xA));
                SerialPort::write(array_current[idx]);
                is_stop = true;
            }
        }
        #endif
    }

    return 0;
}