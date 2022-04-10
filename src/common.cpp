#include <avr/io.h>
volatile uint8_t index = 0;
volatile uint16_t array_current[21];
volatile uint16_t array_speed[21];
volatile bool is_blocked = false;