#pragma once
#include <avr/io.h>
/*
constexpr auto MAX_VOLTAGE                  = 5;        // оно же напряжение питания
constexpr auto _offset_adc_motor            = 2;        // подбирается опытным путем(скачет от питания пололу). 2 В с усилителя в состоянии отключенного двигателя. Отнимать от результата
constexpr auto MAX_SPEED_MOTOR_WITHOUT_LOAD = 3250;     // макс. обороты в минуту без нагрузки
constexpr auto MAX_SPEED_MOTOR_WITH_LOAD    = 2688;     // макс. обороты в минуту c нагрузкой
constexpr auto PRESCALER_ENCODER_DISK       = 12;       // количество прорезей на энкодерном диске
constexpr auto COEFF_OF_ADC_ADC1            = 5.f/1024;   // (шаг квантования) коэффициент, на который нужно умножить значение АЦП, чтобы получить напряжение.
//constexpr auto KOEFFICIENT_OF_SPEED         = 60 / PRESCALER_ENCODER_DISK; // коэффицент, на который нужно домножить, чтобы получить кол-во об. в мин.
*/
extern volatile uint8_t index;
extern volatile uint16_t array_current[21];
extern volatile uint16_t array_speed[21];
extern volatile bool is_blocked;