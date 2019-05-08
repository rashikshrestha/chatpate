#include "system.h"

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
