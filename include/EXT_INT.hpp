#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

namespace EXT_INT
{
    bool blocked_control = false; // Если флаг взведен, реакции на потенциометр нет. 
    void init();
};