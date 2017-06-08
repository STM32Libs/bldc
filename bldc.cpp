
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

        //Prescaler : no effect
        TIM1->PSC = 0;
        TIM1->ARR = 3200;//50 us
        for(int i=0;i<256;i++)
        {
                float angle = i * 2*math::pi /256;
                sin_Table[i] = TIM1->ARR * (sin(angle)+1) / 2;
        }
}

void bldc::setVector(int angle,float norm)
{
        //----------------------------------------------------------measure pulse start
        int a1 = angle % 256;
        uint16_t pwm1_buf = sin_Table[a1];
        int a2 = a1 + 85;
        if(a2>=256)a2-=256;
        uint16_t pwm2_buf = sin_Table[a2];
        int a3 = a1 + 170;
        if(a3>=256)a3-=256;
        uint16_t pwm3_buf = sin_Table[a3];
        //----------------------------------------------------------measure pulse stop => 67.75 us

        /*ser->printf("pwm1 : %u\n",pwm1_buf);
        ser->printf("pwm2 : %u\n",pwm2_buf);
        ser->printf("pwm3 : %u\n",pwm3_buf);
        ser->printf("\n");*/
        //pwm1.pulsewidth_us(100);
        //pwm2.pulsewidth_us(200);

        TIM1->CCR1 = pwm1_buf;// 0.25 us ~ 0.375
        TIM1->CCR2 = pwm2_buf;
        TIM1->CCR3 = pwm3_buf;

        //ser->printf("%d - %d - %d\n",TIM1->CCR1,TIM1->CCR2,TIM1->CCR3);
}
