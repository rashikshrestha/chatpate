#include <Arduino.h>

class System
{
  private:
    bool stat = 0;
    bool new_stat = 0;
    uint16_t stp = 0;
    uint8_t rev = 1;
    uint8_t pwm = 100;

  public:

    int step_count();



};
