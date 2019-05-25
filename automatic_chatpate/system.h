#include <Arduino.h>

class System
{
  private:
     uint8_t pwm_pin;
     uint8_t in1;
     uint8_t in2;
     uint8_t en;

  
    bool stat = 0;
    bool new_stat = 0;
    uint16_t stp = 0;
    uint8_t rev = 1;
    uint8_t pwm = 100;

  public:

    System(uint8_t pwm_pin, uint8_t in1, uint8_t in2, uint8_t en);
    int step_count();
    int print_it();


};
