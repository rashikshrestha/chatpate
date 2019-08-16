#include "pin_configurations.h"
#include "system.h"
#include "data_manipulation.h"

#define wait 1000

DataParser dp;
uint8_t* intermediate_values;

uint8_t Sequence_values[7][10] = {
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1},    //Chatmashala
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1},    //Chilly
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1},    //Bhuja
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1},    //Onion
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1},    //Chana
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1},    //Noodles
  {255,  1,   1, 1  , 1, 1,  0, 1,  0, 1}     //Birenoon
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
  Serial3.begin(9600);
  
  dp.begin(Serial3);     // Use Serial3 instead of Serial for bluetooth communication via Serial3
}

void loop()
{
  while(!update_data());    //Wait until data is recieved
  print_data();                   //Print the current data

  make_chatpate();            //Start Chatpate making sequence
}

bool update_data()
{
  dp.wait_for_data();
  if (dp.validate_data())
  {
    intermediate_values = dp.get_values();

    for (uint8_t i = 0; i < 7; i++)
      for (uint8_t j = 0; j < 10; j++)
        Sequence_values[i][j] = intermediate_values[10 * i + j];

    dp.nullify();
    return 1;

  }
  else
  {
    dp.nullify();
    return 0;
  }

}

void print_data()
{
  Serial.println("Current data is : ");
  
  for (uint8_t i = 0; i < 7; i++)
    for (uint8_t j = 0; j < 10; j++)
      Serial.print(String(Sequence_values[i][j]) + ",");

  Serial.println("\n");
}

void make_chatpate()
{
  Serial.println("Chatpate making sequence started !!! ");
  
  Serial.println("Putting 1: ");
  Chatmasala.run_seq(Sequence_values[0]);

  delay(wait);

  Serial.println("Putting 2: ");
  Chilly.run_seq(Sequence_values[1]);

  delay(wait);

  Serial.println("Putting 3: ");
  Bhuja.run_seq(Sequence_values[2]);

  delay(wait);
  
  Serial.println("Putting 4: ");
  Onion.run_seq(Sequence_values[3]);

  delay(wait);

  Serial.println("Putting 5: ");
  Chana.run_seq(Sequence_values[4]);

  delay(wait);

  Serial.println("Putting 6: ");
  Noodles.run_seq(Sequence_values[5]);

  delay(wait);

  Serial.println("Putting 7: ");
  Birenoon.run_seq(Sequence_values[6]);

  delay(wait);
  Serial.println("Chatpate making completed successfully !!! ");
}

