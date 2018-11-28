#include <Arduino.h>

#include <RBControl_manager.hpp>
#include <Servo.h>

#include "motors.h"
#include "rbprotocol.h"

#include "constants.h"
#include "calibration.h"
#include "functions.h"
#include "move_functions.h"

Servo vratka;

// hlavni stavi
bool hlavni_cesta = false; // pokut neco nestoji n cestě
bool jizda = false; // rovná jízda po čáře
bool otoceni = false; // otáčrní v rozích okruhu
bool vykladani_plechovek = false; 
bool zmena_cesty = false; // mezistav v přechodu mesi hlavní a nouzovou cestou

// podstavi
bool rovnani_orientace;

// Initialize the robot manager
rb::Manager man;

void setup()
{
     // Set the battery measuring coefficient.
    // Measure voltage at battery connector and
    // coef = voltageMeasureAtBatteriesInMilliVolts / raw
    auto& batt = man.battery();
    batt.setCoef(9.0);

    // Set motor power limits
    man.setMotors()
        .pwmMaxPercent(MOTOR_LEFT, 70)  // left wheel
        .pwmMaxPercent(MOTOR_RIGHT, 70)  // right wheel
        .set();

  pin_mode();
  motorSetup();
  vratka.attach(SERVO_PIN); // nutno zadat pin serva
  delay(500);
  hlavni_cesta = true;
  jizda = true;


}
void loop()
{
  enc_functions();
  follow_line_function();
  rotate_r_function();
  rotate_l_function(); 
  correction_direction_function();
  rovnani_orientace_function();

  stop_function(50);

  if((infra_pl^^infra_pp)^^infra_pr)
  {
    hlavni_cesta = false; 
  }
  else
  {
    hlavni_cesta = true;
  }
  if(hlavni_cesta) // popis hlavni trasi
  {
    if((Xr<6)&&(Yr=0)) // pokut jsem na startovni laijne
    {
      jizda = true;
      vykladani_plechovek = true;
      otoceni = false;
      na_souradce = true;
    }
    else if((Xr=7)&&(Yr<3)) 
    {
      jizda = true;
      vykladani_plechovek = false;
      otoceni = false;
      na_souradce = false;
    }
    else if((Xr<7)&&(Yr=3))
    {
      jizda = true;
      vykladani_plechovek = false;
      otoceni = false;
      na_souradce = true;
    }
    else if((Xr=0)&&(Yr<4))
    {
      jizda = true;
      nakladani_plechovek = false;
      otoceni = false;
      na_souradce = false;
    }
    else
    {
      jizda = false;
      nakladani_plechovek = false;
      otoceni = true;
    }
  }
  else // popis vedlejsi 
  {
    stop = true; // zatim jeno zastavit
    //šílenost pro jinou cestu na objetí nepřítele
  }
  if(jizda) // jizda
  {
    correction_direction = true;
    otacky = 200;
  }
  if(otoceni) // popis startu, prubehu a konce otoceni
  {
    correction_direction = false;
    if(v_otacce)
    {
      if(wbr_current<wbr_prumer)
      {
        turn = true;
        osa_otaceni = 5;
      }
      else
      {
        turn = false;
        rovnani_orientace = false;
      }
    }
    else
    {
      if(wbl_current<wbl_prumer)
      {
        rovnani_orientace = true;
        v_otacce = false;
      }
      else if(wbr_current>wbr_prumer)
      {
        correction_direction = true;
        v_otacce = false;
        turn = true;
        osa_otaceni = 5;
      }
      else if(wbr_current<wbr_prumer)
      {
        correction_direction = false;
        v_otacce = true;
        turn = true;
        osa_otaceni = 5;
      }
      else
      {
        correction_direction = true;
        otacky = -50;
        rovnani_orientace = false;
        v_otacce = false;
      }
    }
  }
  if(vykladani_plechovek) // jen ovladani zadnich vratek
  {
    vratka.write(90); // nutno kalibrobat polohu serva
  }
  else
  {
    vratka.write(0); // nutno kalibrobat polohu serva
  }
  // trvale funkce
  if(wbr_current<wbr_prumer) // souradnicov sistem pro pravi souradnicovi senzor
  {
      if(vnimani_prejete_cari_r) // pokut caru us zapocital tak ji dal nevnima
      {
        vnimani_prejete_cari_r=false;
        if(na_souradce) // aby pricital ke spravne ose
        {
          ++Xr;
        }
        else
        {
          ++Yr;
        }
      }
  }
  else
  {
      vnimani_prejete_cari_r = true; // kdiz se dostane spet mimo caru tak muze vnimat dalsi
  }
  if(wbl_current<wbl_prumer)  // souradnicov sistem pro levi souradnicovi senzor
  {
      if(vnimani_prejete_cari_l) // pokut caru us zapocital tak ji dal nevnima
      {
        vnimani_prejete_cari_l=false;
        if(na_souradce) // aby pricital ke spravne ose
        {
          ++Xl;
        }
        else
        {
          ++Yl;
        }
      }
  }
  else
  {
      vnimani_prejete_cari_l = true; // kdiz se dostane spet mimo caru tak muze vnimat dalsi
  }

  builder.set();
}