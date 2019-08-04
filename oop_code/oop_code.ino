#include "pin_configurations.h"
#include "system.h"

#define wait 1000

uint8_t Chatmasala_values[10] = {255,  1,   1,1  ,1,1,  0,1,  0,1};


System Chatmasala(Chatmashala_pwm, Chatmashala_dir, Chatmashala_enc);
System Chilly(Chilly_pwm, Chilly_dir, Chilly_enc);
System Bhuja(Bhuja_pwm, Bhuja_dir, Bhuja_enc);
System Onion(Onion_pwm, Onion_dir, Onion_enc);
System Chana(Chana_pwm, Chana_dir, Chana_enc);
System Noodles(Noodles_pwm, Noodles_dir, Noodles_enc);
System Birenoon(Birenoon_pwm, Birenoon_dir, Birenoon_enc);

void setup()
{

  Serial.begin(9600);
  
}

void loop()
{
    Chatmasala.run_seq(Chatmasala_values);

    delay(1000);

    Chilly.run_seq(Chatmasala_values);

    delay(1000);

    Bhuja.run_seq(Chatmasala_values);

    delay(1000);

    Onion.run_seq(Chatmasala_values);

    delay(1000);

    Chana.run_seq(Chatmasala_values);

    delay(1000);

    Noodles.run_seq(Chatmasala_values);

    delay(1000);

//    Birenoon.run_seq(Chatmasala_values);
//
//    delay(1000);

    

    

    

}
