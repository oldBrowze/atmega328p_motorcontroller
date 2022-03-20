#include "ADC.hpp"
#include <avr/interrupt.h>
//#include "EXT_INT.hpp"
#include "Serial.hpp"

void __ADC::init()
{
    ADMUX = (0b01 << REFS0);   // REFS1 - 0, REFS0 - 1, ИОН = Vcc
            //(0b0000 << MUX0);   //MUX3..0 = 0000 -> ADC0 (A0)

    DIDR0 = (0b1111 << ADC2D); // отключаем каналы 

    ADCSRA = (1 << ADEN) |      // разрешаем работу АЦП
            //(1 << ADATE) |      // разрешаем запуск по триггеру
            //(1 << ADIE) |       // разрешаем прерывания от АЦП
            (0b111 << ADPS0);  // устанавливаем предделитель частоты на 128
            //(1 << ADSC);        // запускаем преобразования
    
}

uint16_t __ADC::get_result(const uint8_t channel)
{
    ADMUX = (ADMUX & 0xF0) | channel;
    if(channel == 2)
        ADMUX |= (0b11 << REFS0);
    else 
        ADMUX |= (0b01 << REFS0);
    ADCSRA |= (1 << ADSC); //запускаем преобразование
    while(!(ADCSRA & (1 << ADIF)));

    return ADC;
}

/*
ISR(ADC_vect)
{
    static volatile uint16_t ADC_value;

    ADC_value = ADC;
    switch(ADMUX & 0x0F)
    {
        case 0:
            OCR1A = ADC_value;
            //SerialPort::write(OCR1A);
            ADMUX = (ADMUX & 0xF0) | 0x1;
            break;
        case 1:

            //SerialPort::write(ADC_value);
            ADMUX = (ADMUX & 0xF0) | 0x0;
            break;
    }

    //ADMUX ^= (1 << MUX0);
}*/