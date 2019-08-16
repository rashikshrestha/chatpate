/*DATA FORMAT:
@#$255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,%^&
*/

#include "data_manipulation.h"

DataParser dp;
uint8_t* intermediate_values;

//Test Datas:
uint8_t Sequence_values[7][10] = {
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89},    //Chatmashala
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89},    //Chilly
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89},    //Bhuja
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89},    //Onion
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89},    //Chana
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89},    //Noodles
  {155, 81, 82, 83, 84, 85, 86, 87, 88, 89}    //Birenoon
};

void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
  
  dp.begin(Serial);     // Use Serial3 instead of Serial for bluetooth communication via Serial3

}

void loop()
{
  while(!update_data());
   print_data();
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

