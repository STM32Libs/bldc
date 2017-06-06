

#include "bldc.h"

bldc::bldc(PinName v_pwm1,PinName v_pwm2,PinName v_pwm3,PinName v_en):
        pwm1(v_pwm1),
        pwm2(v_pwm2),
        pwm3(v_pwm3),
        enable(v_en)
{
    
}
        