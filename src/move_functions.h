#include "functions.h"

#define MINUTA 60000000
#define ROZCHOT 25

void rotate_l_function() //v ot/min
{
    if(rotate_l)
    {
        if(micros() <= (last_time_1+cas_1))
        {
            last_time_1 = micros(); // ulozeni casu posledniho tiku virtualniho enc
            cas_1 = MINUTA/(otacky_l * pp_enc); // pp_enc = pocet polu encoderu

            ++virtual_enc_1;
            rozdil1 = virtual_enc_1 - enc_l;
            pvm_1 = pvm_1 + rozdil1;

            builder.power(MOTOR_LEFT, pvm_l);
            virtual_enc_1 = enc_1;
        }
    }
}
void rotate_r_function() //v ot/min
{
    if(rotate_r)
    {
        if(micros() <= (last_time_2+cas_2))
        {
            last_time_2 = micros(); // ulozeni casu posledniho tiku virtualniho enc
            cas_2 = MINUTA/(otacky_r * pp_enc); // pp_enc = pocet polu encoderu

            ++virtual_enc_2;
            rozdil2 = virtual_enc_2 - enc_r;
            pvm_2 = pvm_2 + rozdil2;

            builder.power(MOTOR_RIGHT, pvm_r);
            virtual_enc_r = enc_2;
        }
    }
}
void correction_direction_function() // true = prava: folse = leva
{
    if(correction_direction)
    {
        if(odklon>0)
        {
            rotate_l = true;
            rotate_r = true;
            
            otacky_l = otacky*odklon;
            otacky_r = otacky/odklon;
        }
        else if(odklon<0)
        {
            last_time = micros(); // ulozeni casu posledniho tiku virtualniho enc
            cas = MINUTA/(otacky * pp_enc); // pp_enc = pocet polu encoderu
    
            ++virtual_enc;
            delta_l = virtual_enc - enc_l;
            delta_r = virtual_enc - enc_r;
    
            motor_spead_l = (motor_spead_l + delta_l)/(0-odklon);
            motor_spead_r = (motor_spead_r + delta_r)*(0-odklon);
    
            pvm_motor(1, motor_spead_l);
            pvm_motor(2, motor_spead_r);
            virtual_enc_2 = virtual_enc_2 - rozdil2;    
        }
        else
        {
            rotate_l = true;
            rotate_r = true;
            
            otacky_l = otacky;
            otacky_r = otacky;
        }
    }
}
void turn_function()
{
    if(turn)
    {  
        rotate_r = true;
        rotate_l = true;
        correction_direction = false;
        osa_l = osa_otaceni;
        osa_r = ROZCHOT-osa_otaceni;

        otacky_l = turn_spead*osa_r;
        otacky_r = turn_spead*osa_l;

        if(prava_zatacka)
        {
            otacky_l = turn_spead*osa_r;
            otacky_r = turn_spead*osa_l;
        }
    }
}
void rovnani_orientace_function()
{
    if(rovnani_orientace)
    {
        rotate_r = true;
        rotate_l = true;
        if((wbr_current>wbr_prumer)&&(wbl_current<wbl_prumer))
        {
            if(Xr==Xl)
            {
                otacky_l = -0.5;
                otacky_r = 0;
            }
            else
            {
                otacky_l = 0.5;
                otacky_r = 0;
            }
        }
    }
}