/*DATA FORMAT:
@#$255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,255,1,2,3,4,5,6,7,8,9,%^&
*/

//#define SERIAL_TX_BUFFER_SIZE 256
//#define SERIAL_RX_BUFFER_SIZE 256
#include "data_manipulation.h"

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

void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);

  dp.begin(Serial);     // Use Serial3 instead of Serial for bluetooth communication via Serial3

}

void loop()
{
  update_data();
}

void update_data()
{
  dp.wait_for_data();
  if (dp.validate_data())
  {
    intermediate_values = dp.get_values();

    for (uint8_t i = 0; i < 7; i++)
      for (uint8_t j = 0; j < 10; j++)
        Sequence_values[i][j] = intermediate_values[i + j];
  }
  dp.nullify();
}

