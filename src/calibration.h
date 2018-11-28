#include "Arduino.h"
void pin_mode()
{
    pinMode(ENC_L1,INPUT);
    pinMode(ENC_L2,INPUT);
    pinMode(ENC_R1,INPUT);
    pinMode(ENC_R2,INPUT);

    pinMode(INFRA_L, INPUT);
    pinMode(INFRA_PL,INPUT);
    pinMode(INFRA_PP,INPUT);
    pinMode(INFRA_PR,INPUT);

    pinMode(SERVO_PIN,OUTPUT);
}
void wait_for_button(int pin)
{
    bool button = false;
    while (button == false) 
    {
        if(analogRead(pin))
        {
            button = true;
        }
    }
}
void calibration_black_white()
{
    wait_for_button(button1_pin);
    wbp1_w = wbp1_current;
    wbp2_w = wbp2_current;
    wbp3_w = wbp3_current;
    wbp4_w = wbp4_current;
    wbp5_w = wbp5_current;

    wbz1_w = wbz1_current;
    wbz2_w = wbz2_current;
    wbz3_w = wbz3_current;
    wbz4_w = wbz4_current;
    wbz5_w = wbz5_current;

    wbl_w = wbl_current;
    wbr_w = wbr_current;

    wait_for_button(button1_pin);
    wbp1_b = wbp1_current;
    wbp5_b = wbp5_current;

    wait_for_button(button1_pin);
    wbp2_b = wbp2_current;
    wbp3_b = wbp3_current;
    wbp4_b = wbp4_current;
    
    wait_for_button(button1_pin);
    wbz1_b = wbz1_current;
    wbz5_b = wbz5_current;

    wait_for_button(button1_pin);
    wbz2_b = wbz2_current;
    wbz3_b = wbz3_current;
    wbz4_b = wbz4_current;
    
    wait_for_button(button1_pin);
    wbl_b = wbl_current;
    wbr_b = wbr_current;

    wbp1_prumer = (wbp1_b+wbp1_w)/2;
    wbp2_prumer = (wbp2_b+wbp2_w)/2;
    wbp3_prumer = (wbp3_b+wbp3_w)/2;
    wbp4_prumer = (wbp4_b+wbp4_w)/2;
    wbp5_prumer = (wbp5_b+wbp5_w)/2;

    wbz1_prumer = (wbz1_b+wbz1_w)/2;
    wbz2_prumer = (wbz2_b+wbz1_w)/2;
    wbz3_prumer = (wbz3_b+wbz1_w)/2;
    wbz4_prumer = (wbz4_b+wbz1_w)/2;
    wbz5_prumer = (wbz5_b+wbz1_w)/2;

    wbr_prumer = (wbr_b+wbr_w)/2;
    wbl_prumer = (wbl_b+wbl_w)/2;
}