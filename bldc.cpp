
#include <math.h>
#include "bldc.h"

bldc::bldc(Serial *ps,PinName v_pwm1,PinName v_pwm2,PinName v_pwm3,PinName v_en):
        ser(ps),
        pwm1(v_pwm1),
        pwm2(v_pwm2),
        pwm3(v_pwm3),
        enable(v_en)
{
        enable = 0;
        pwm1 = 0;
        pwm2 = 0;
        pwm3 = 0;

        pwm1.period_us(50);//20 KHz
}

void bldc::setVector(float angle,float norm)
{
        enable = 1;
        //----------------------------------------------------------measure pulse start
        uint16_t pwm1_buf = norm * sin(angle);
        uint16_t pwm2_buf = norm * sin(angle + math::pi/3);
        uint16_t pwm3_buf = norm * sin(angle + 2*math::pi/3);
        //----------------------------------------------------------measure pulse stop => 67.75 us

        /*ser->printf("pwm1 : %u\n",pwm1_buf);
        ser->printf("pwm2 : %u\n",pwm2_buf);
        ser->printf("pwm3 : %u\n",pwm3_buf);
        ser->printf("\n");*/
        pwm1.pulsewidth_us(pwm1_buf);
        pwm2.pulsewidth_us(pwm2_buf);
        pwm3.pulsewidth_us(pwm3_buf);
        enable = 0;
}
