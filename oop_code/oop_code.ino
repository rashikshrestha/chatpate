#include "pin_configurations.h"
#include "system.h"

#define wait 1000

uint8_t Sequence_values[7][10] = {
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1},         //Chatmashala
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1},         //Chilly
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1},         //Bhuja
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1},         //Onion
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1},         //Chana
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1},         //Noodles
                                                              {255,  1,   1,1  ,1,1,  0,1,  0,1}          //Birenoon
                                                        };


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
   
    make_chatpate();
}

void make_chatpate()
{
   Chatmasala.run_seq(Sequence_values[0]);

    delay(wait);
    
   Chilly.run_seq(Sequence_values[1]);

    delay(wait);

    Bhuja.run_seq(Sequence_values[2]);

    delay(wait);

    Onion.run_seq(Sequence_values[3]);

    delay(wait);

    Chana.run_seq(Sequence_values[4]);

    delay(wait);

    Noodles.run_seq(Sequence_values[5]);

    delay(wait);

    Birenoon.run_seq(Sequence_values[6]);

    delay(wait);
}

