#include <Arduino.h>

class System
{
  private:
    uint8_t p, d, e;
    uint8_t stp;
    bool stat = 0, new_stat = 1;

  public:
    System(uint8_t pwm, uint8_t dir, uint8_t enc)
    {
      p = pwm;
      d = dir;
      e = enc;
    }

    void move(uint8_t p_value, bool dirn)    //Rotate Motor
    {
      analogWrite(p, p_value);
      digitalWrite(d, dirn);
    }

    void stop()
    {
      analogWrite(p, 0);
    }

    uint8_t step()    //Counts the step
    {
      new_stat = digitalRead(e);  //Reads en Pin

      if (new_stat != stat)              //IF Pin status toggles
      {
        stat = new_stat;
        stp++;
      }

      return stp;
    }

    void run_seq(uint8_t values[]) 
    {
      uint8_t pwm_value = values[0];

      bool dirn = values[1];
      
      uint8_t first_rev = values[2];
      uint8_t first_div = values[3];

      uint8_t second_rev = values[4];
      uint8_t second_div = values[5];

      uint8_t third_rev = values[6];
      uint8_t third_div = values[7];

      uint8_t fourth_rev = values[8];
      uint8_t fourth_div = values[9];

      move(pwm_value, dirn);

      while(step() < (36 / first_div) * first_rev );
      
      stp=0;
      move(pwm_value, !dirn);

      while(step() < 36 / second_div * second_rev);

      stp=0;
      move(pwm_value, dirn);

      while(step() < 36 / third_div * third_rev);

      stp=0;
      move(pwm_value, !dirn);

      while(step() <  36 / fourth_div * fourth_rev);

      stp=0;
      stop();
    }
};
