#include "ADC.hpp"
#include <avr/interrupt.h>
#include "Serial.hpp"

void __ADC::init()
{
    ADMUX = (0b01 << REFS0);                    // REFS1 - 0, REFS0 - 1, ИОН = Vcc

    DIDR0 = (0b1111 << ADC2D);                  // отключаем каналы 

    ADCSRA = (1 << ADEN) |                      // разрешаем работу АЦП
            (0b111 << ADPS0);                   // устанавливаем предделитель частоты на 128
    
}

uint16_t __ADC::get_result(const uint8_t channel)
{
    ADMUX = (ADMUX & 0xF0) | channel;           // настраиваем канал

    ADCSRA |= (1 << ADSC);                      // запускаем преобразование
    while(!(ADCSRA & (1 << ADIF)));             // ждем конца преобразования

    return ADC;
}
