#include "system.h"


System::System(uint8_t pwm_pin, uint8_t in1, uint8_t in2, uint8_t en)
{
   pwm_pin = pwm_pin;
   in1 = in1;
   in2 = in2;
   en = en;


  
}


int System::step_count()
{
  new_stat = digitalRead(8);
  if (new_stat != stat)
  {
    stat = new_stat;
    stp++;
    Serial.println(stp);
  }

  if (stp >= 36 * rev)
  {
    Serial.println("Revolution Completed");
    analogWrite(2, 0);
    stp = 0;

  }
}

int print_it()
{
  Serial.print(in1);
}
