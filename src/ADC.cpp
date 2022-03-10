#include "ADC.hpp"
#include <avr/interrupt.h>
#include <EXT_INT.hpp>

void __ADC::init()
{
    ADMUX = (0b01 << REFS0) |   // REFS1 - 0, REFS0 - 1, ИОН = Vcc
            (0b0000 << MUX0);   //MUX3..0 = 0000 -> ADC0 (A0)

    ADCSRA = (1 << ADEN) |      // разрешаем работу АЦП
            (1 << ADATE) |      // разрешаем запуск по триггеры
            (1 << ADIE) |       // разрешаем прерывания от АЦП
            (0b101 << ADPS0) |  // устанавливаем предделитель частоты на 2
            (1 << ADSC);        // запускаем преобразования
    
}

ISR(ADC_vect)
{
    switch(ADMUX & 0xF)
    {
        case 0: // потенциометр
            if(EXT_INT::blocked_control == false)
            {
                OCR1A = ADC;                // считываем результаты с АЦП
                __ADC::set_channel(__ADC::ADC_Channel::ADC1);
            }
            break;
        case 1: // датчик тока
            
            __ADC::set_channel(__ADC::ADC_Channel::ADC0);
            break;
    }
    ADCSRA |= (1 << ADSC);      // начинаем след. преобразование
}