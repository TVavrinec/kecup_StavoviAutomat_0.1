#include <Arduino.h>

//MOTOR 1 - levy
#define MOTOR_A1_PIN  // nutno určit piny!!!
#define MOTOR_B1_PIN  // nutno určit piny

//MOTOR 2 - pravy
#define MOTOR_A2_PIN  // nutno určit piny
#define MOTOR_B2_PIN  // nutno určit piny

#define PWM_1  // nutno určit piny
#define PWM_2  // nutno určit piny

#define EN_PIN_1  // nutno určit piny
#define EN_PIN_2  // nutno určit piny

#define MOTOR_1 1
#define MOTOR_2 2

void pvm_motor(bool motor, int16_t pwm) //motor(0 nebo 1) a pwm (od -255 do 255);
{
    if(motor == MOTOR_1)
    {
        if(pwm > 0)
        {
            digitalWrite(MOTOR_A1_PIN, LOW); 
            digitalWrite(MOTOR_B1_PIN, HIGH);
        }
        else if(pwm < 0)
        {
            digitalWrite(MOTOR_A1_PIN, HIGH);
            digitalWrite(MOTOR_B1_PIN, LOW);      
        }
        else
        {
            digitalWrite(MOTOR_A1_PIN, LOW);
            digitalWrite(MOTOR_B1_PIN, LOW);            
        }
        analogWrite(PWM_1, pwm);
    }
    else
    {
        if(pwm > 0)
        {
            digitalWrite(MOTOR_A2_PIN, LOW);
            digitalWrite(MOTOR_B2_PIN, HIGH);
        }
        else if(pwm < 0)
        {
            digitalWrite(MOTOR_A2_PIN, HIGH);
            digitalWrite(MOTOR_B2_PIN, LOW);      
        }
        else
        {
            digitalWrite(MOTOR_A2_PIN, LOW);
            digitalWrite(MOTOR_B2_PIN, LOW);            
        }
        analogWrite(PWM_2, pwm);
    }
}
void stop_function(uint8_t brzdna_sila)
{
    if(stop)
    {
        digitalWrite(MOTOR_A1_PIN, LOW);
        digitalWrite(MOTOR_B1_PIN, LOW);
        analogWrite(PWM_1, brzdna_sila);

        digitalWrite(MOTOR_A2_PIN, LOW);
        digitalWrite(MOTOR_B2_PIN, LOW);
        analogWrite(PWM_2, brzdna_sila);
    }
}
void motorSetup()                        
{
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  pinMode(PWM_1, OUTPUT);
  pinMode(PWM_2, OUTPUT);

  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);  
}