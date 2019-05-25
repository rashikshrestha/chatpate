#define p 2
#define int_pin_1 22
#define int_pin_2 23
#define en 8


uint8_t in1 = int_pin_1;
uint8_t  in2 = int_pin_2;

bool stat = 0;
bool new_stat = 0;
int stp = 0;

int first_rev = 1;
int second_rev = 1;
int third_rev = 1;
int fourth_rev = 1;

int first_div = 1;
int second_div = 1;
int third_div = 1;
int fourth_div = 1;

int pwm = 100;
char cmd;
uint8_t mode = 1;
uint8_t movements = 1;

bool repeater = 0;
uint8_t delay_duration = 1;

void setup()
{
  Serial.begin(9600);

  pinMode(en, INPUT);
  pinMode(p, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in1, OUTPUT);

  disp_cond();

}

void loop()
{
  commander();
  step_counter();
  motor_controller();
}

void dir1()
{
  analogWrite(p, pwm);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void dir2()
{
  analogWrite(p, pwm);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void stop()
{
  analogWrite(p, 0);
}

void nullify_all()
{
  stop();
  stp = 0;
  mode = 1;
}

void motor_controller()
{

  if (mode == 1 && stp >= 36 / first_div * first_rev)
  {
    stp = 0;

    if (movements == 1)
    {
      mode = 1;
      stop();

      if (repeater == 1)
      {
        delay(1000 * delay_duration);
        dir1();
      }
    }

    else
    {
      mode = 2;
      dir2();
    }
  }

  if (mode == 2 && stp >= 36 / second_div * second_rev)
  {
    stp = 0;

    if (movements == 2)
    {
      mode = 1;
      stop();

      if (repeater == 1)
      {
        delay(1000 * delay_duration);
        dir1();
      }
    }
    else
    {
      mode = 3;
      dir1();
    }

  }

  if (mode == 3 && stp >= 36 / third_div * third_rev)
  {
    stp = 0;

    if (movements == 3)
    {
      mode = 1;
      stop();

      if (repeater == 1)
      {
        delay(1000 * delay_duration);
        dir1();
      }

    }
    else
    {
      mode = 4;
      dir2();
    }


    if (mode == 4 && stp >= 36 / fourth_div * fourth_rev)
    {
      stp = 0;

      mode = 1;
      stop();

      if (repeater == 1)
      {
        delay(1000 * delay_duration);
        dir1();
      }

    }

  }

}

void step_counter()
{
  new_stat = digitalRead(en);
  if (new_stat != stat)
  {
    stat = new_stat;
    stp++;
    Serial.print("Steps: ");
    Serial.println(stp);
  }
}

void commander()
{
  while (Serial.available())
  {
    cmd = Serial.read();

    if (cmd == 'r')
    {
      stp = 0;
      dir1();
    }

    if (cmd == 't')
    {
      nullify_all();
    }

    if (cmd == 'u')
    {
      pwm += 10;
      Serial.println(pwm);
    }

    if (cmd == 'i')
    {
      pwm -= 10;
      Serial.println(pwm);
    }

    //CONTROLLING NO OF REVOLUTIONS:
    if (cmd == 'a')
    {
      first_rev += 1;
      Serial.println(first_rev);
    }

    if (cmd == 'z')
    {
      first_rev -= 1;
      if (first_rev < 0) first_rev = 0;
      Serial.println(first_rev);
    }

    if (cmd == 's')
    {
      second_rev += 1;
      Serial.println(second_rev);
    }

    if (cmd == 'x')
    {
      second_rev -= 1;
      if (second_rev < 0) second_rev = 0;
      Serial.println(second_rev);
    }

    if (cmd == 'd')
    {
      third_rev += 1;
      Serial.println(third_rev);
    }

    if (cmd == 'c')
    {
      third_rev -= 1;
      if (third_rev < 0) third_rev = 0;
      Serial.println(third_rev);
    }

    if (cmd == 'f')
    {
      fourth_rev -= 1;
      Serial.println(fourth_rev);
    }

    if (cmd == 'v')
    {
      fourth_rev -= 1;
      if (fourth_rev < 0) fourth_rev = 0;
      Serial.println(fourth_rev);
    }

    //CONTROLLING DIVISOR
    if (cmd == 'g')
    {
      first_div += 1;
      if (first_div > 4) first_div = 4;
      Serial.println(first_div);
    }

    if (cmd == 'b')
    {
      first_div -= 1;
      if (first_div < 1) first_div = 1;
      Serial.println(first_div);
    }

    if (cmd == 'h')
    {
      second_div += 1;
      if (second_div > 4) second_div = 4;
      Serial.println(second_div);
    }

    if (cmd == 'n')
    {
      second_div -= 1;
      if (second_div < 1) second_div = 1;
      Serial.println(second_div);
    }

    if (cmd == 'j')
    {
      third_div += 1;
      if (third_div > 4) third_div = 4;
      Serial.println(third_div);
    }

    if (cmd == 'm')
    {
      third_div -= 1;
      if (third_div < 1) third_div = 1;
      Serial.println(third_div);
    }

    if (cmd == 'k')
    {
      fourth_div -= 1;
      if (fourth_div > 4) fourth_div = 4;
      Serial.println(fourth_div);
    }

    if (cmd == ',')
    {
      fourth_div -= 1;
      if (fourth_div < 1) fourth_div = 1;
      Serial.println(fourth_div);
    }

    //CONTROLLING DIRECTION:

    if (cmd == 'q')
    {
      in1 = int_pin_1;
      in2 = int_pin_2;
    }

    if (cmd == 'w')
    {
      in1 = int_pin_2;
      in2 = int_pin_1;
    }

    //DISPLAYING VALUES:

    if (cmd == 'p')
    {
      disp_cond();
    }

    if (cmd == 'y')
    {
      repeater = 1;
    }

    if (cmd == 'u')
    {
      repeater = 0;
    }

    if (cmd == 'i')
    {
      delay_duration += 1;
    }

    if (cmd == 'o')
    {
      delay_duration -= 1;
      if (delay_duration < 0) delay_duration = 0;
    }


  }
}

void disp_cond()
{
  Serial.println("\n#######################################");

  Serial.print("Steps : ");
  Serial.println(stp);

  Serial.print("PWM : ");
  Serial.println(pwm);

  Serial.print("Direction : ");
  if (in1 == int_pin_1)
    Serial.println("1");
  else
    Serial.println("2");

  Serial.print("\nMovements : ");
  Serial.println(movements);

  Serial.print("First Rev : ");
  Serial.print(first_rev);
  Serial.print(" / ");
  Serial.println(first_div);

  Serial.print("Second Rev : ");
  Serial.print(second_rev);
  Serial.print(" / ");
  Serial.println(second_div);

  Serial.print("Third Rev : ");
  Serial.print(third_rev);
  Serial.print(" / ");
  Serial.println(third_div);

  Serial.print("Fourth Rev : ");
  Serial.print(fourth_rev);
  Serial.print(" / ");
  Serial.println(fourth_div);
  Serial.print("\n");

  Serial.print("\nRepeater : ");
  Serial.println(repeater);

  Serial.print("Delay Duration : ");
  Serial.println(delay_duration);

  Serial.println("#######################################\n");
}
