#ifndef __BLDC__
#define __BLDC__

#include "mbed.h"

namespace math
{
    float const pi = 3.1415926535897932384626433832795;

}

class bldc
{
public:
    bldc(Serial *ps,PinName v_pwm1,PinName v_pwm2,PinName v_pwm3,PinName v_en);

    void setVector(int angle,float norm);
public:
    DigitalOut  enable;
    PwmOut      pwm1;
    PwmOut      pwm2;
    PwmOut      pwm3;
private:
    uint16_t pwm1_shadow;
    uint16_t pwm2_shadow;
    uint16_t pwm3_shadow;
    Serial *ser;
    uint16_t    sin_Table[256];
};


#endif /*__BLDC__*/