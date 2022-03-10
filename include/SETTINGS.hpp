#pragma once

constexpr auto NOMINALLY_VOLTAGE = 6;
constexpr auto MAX_VOLTAGE = 5;
constexpr auto MAX_SPEED_MOTOR_WITHOUT_LOAD = 3250; // макс. обороты в минуту без нагрузки
constexpr auto MAX_SPEED_MOTOR_WITH_LOAD    = 2688; // макс. обороты в минуту c нагрузкой
constexpr auto PRESCALER_ENCODER_DISK       = 12;   // количество прорезей на энкодерном диске
constexpr auto KOEFFICIENT_OF_SPEED         = 60 / PRESCALER_ENCODER_DISK; // коэффицент, на который нужно домножить, чтобы получить кол-во об. в мин.
