#include "constants.h"

void enc_functions()
{
    if(digitalRead(enc_l1_pin) != enc_l1_pin_save)
    {
        enc_l1_pin_save = digitalRead(enc_l1_pin);
        if(enc_l1_pin_save)
        {
            if(enc_l2_pin)
                ++enc_l;
            else
                --enc_l;
        }
        else
        {
            if(enc_l2_pin)
                --enc_l;
            else
                ++enc_l;
        }
    }
    if(digitalRead(enc_r1_pin) != enc_r1_pin_save)
    {
        enc_r1_pin_save = digitalRead(enc_r1_pin);
        if(enc_r1_pin_save)
        {
            if(enc_r2_pin)
                ++enc_r;
            else
                --enc_r;
        }
        else
        {
            if(enc_r2_pin)
                --enc_r;
            else
                ++enc_r;
        }
    }
}
float follow_line_function()
{
    if((wbp1_current<wbp1_prumer) && (wbp2_current>wbp2_prumer) && (wbp3_current>wbp3_prumer) && 
    (wbp4_current>wbp4_prumer) && (wbp5_current>wbp5_prumer))
    {
        odklon = 1.5;
    }
    else if((wbp1_current>wbp1_prumer) && (wbp2_current<wbp2_prumer) && (wbp3_current>wbp3_prumer) && 
    (wbp4_current>wbp4_prumer) && (wbp5_current>wbp5_prumer))
    {
        odklon = 1.1;
    }
    else if((wbp1_current>wbp1_prumer) && (wbp2_current>wbp2_prumer) && (wbp3_current<wbp3_prumer) && 
    (wbp4_current>wbp4_prumer) && (wbp5_current>wbp5_prumer))
    {
        if((wbz1_current<wbz1_prumer) && (wbz2_current>wbz2_prumer) && (wbz3_current>wbz3_prumer) && 
        (wbz4_current>wbz4_prumer) && (wbz5_current>wbz5_prumer))
        {
            odklon = 1.1;
        }
        else if((wbz1_current>wbz1_prumer) && (wbz2_current<wbz2_prumer) && (wbz3_current>wbz3_prumer) && 
       (wbz4_current>wbz4_prumer) && (wbz5_current>wbz5_prumer))
        {
            odklon = 1.05;
        }
            else if((wbz1_current>wbz1_prumer) && (wbz2_current>wbz2_prumer) && (wbz3_current<wbz3_prumer) && 
            (wbz4_current>wbz4_prumer) && (wbz5_current>wbz5_prumer))
            {
                odklon = 1;
            }
        else if((wbz1_current>wbz1_prumer) && (wbz2_current>wbz2_prumer) && (wbz3_current>wbz3_prumer) && 
        (wbz4_current<wbz4_prumer) && (wbz5_current>wbz5_prumer))
        {
            odklon = -1.05;
        }
        else if((wbz1_current>wbz1_prumer) && (wbz2_current>wbz2_prumer) && (wbz3_current>wbz3_prumer) && 
        (wbz4_current>wbz4_prumer) && (wbz5_current<wbz5_prumer))
        {
            odklon = -1.1;
        }
    }
    else if((wbp1_current>wbp1_prumer) && (wbp2_current>wbp2_prumer) && (wbp3_current>wbp3_prumer) && 
    (wbp4_current<wbp4_prumer) && (wbp5_current>wbp5_prumer))
    {
        odklon = -1.1;
    }
    else if((wbp1_current>wbp1_prumer) && (wbp2_current>wbp2_prumer) && (wbp3_current>wbp3_prumer) && 
    (wbp4_current>wbp4_prumer) && (wbp5_current<wbp5_prumer))
    {
        odklon = -1.5;
    }
    else
    {
        stracen = true;
    }
}