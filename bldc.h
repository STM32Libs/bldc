#ifndef __BLDC__
#define __BLDC__

class bldc
{
public:
    bldc(PinName v_pwm1,PinName v_pwm2,PinName v_pwm3,PinName v_en);
public:
    DigitalOut  enable;
    PwmOut      pwm1;
    PwmOut      pwm2;
    PwmOut      pwm3;
};


#endif /*__BLDC__*/