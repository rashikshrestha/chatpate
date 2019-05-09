#define p 2
#define in2 22
#define in1 24
#define en 8

bool wait = 0;
int delay_time = 1;


bool stat = 0;
bool new_stat = 0;
int stp = 0;
int rev = 1;
int pwm = 100;
char cmd;
uint8_t opp = 0;


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
  new_stat = digitalRead(en);
  if (new_stat != stat)
  {
    stat = new_stat;
    stp++;
    Serial.print("Steps: ");
    Serial.println(stp);
  }


  if (opp == 0 && stp >= 8 * rev - 1 )
  {


    Serial.println("Revolution Completed");
    //stop();

    

    if (wait == 0)
    {
      Serial.println("Should be wating here");

      stop();
      delay(delay_time * 1000);

      Serial.println("Waiting completed");
      wait = 1;

    }
    dir2();


    stp = 0;
    opp = 1;
  }

  if (opp == 1 && stp >= 8 * rev)
  {




    Serial.println("Opposite Revolution Completed");

    stop();
    stp = 0;
    opp = 0;
    wait = 0;

  }

  if (opp == 2 && stp >= 36 * rev * 2)
  {
    Serial.println("More Opposite Revolution Completed");

    stop();
    stp = 0;
    opp = 0;

    disp_cond();

  }



}

void dir2()
{
  analogWrite(p, pwm);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void dir1()
{
  analogWrite(p, pwm);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
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
      stop();
    }

    if (cmd == 'u')
    {
      pwm += 10;
      Serial.println(pwm);
    }

    if (cmd == 'd')
    {
      pwm -= 10;
      Serial.println(pwm);
    }

    if (cmd == 'q')
    {
      rev += 1;
      Serial.println(rev);

    }

    if (cmd == 'a')
    {
      rev -= 1;
      Serial.println(rev);

    }

    if (cmd == '[')
    {
      delay_time += 1;
      Serial.println(delay_time);

    }

    if (cmd == ']')
    {
      delay_time -= 1;
      Serial.println(delay_time);

    }

    if (cmd == 'p')
    {
      disp_cond();
    }

    if (cmd == 'n')
    {
      stp = 0;
    }





  }
}

void disp_cond()
{
  Serial.println("\n#######################################");
  Serial.print("PWM : ");
  Serial.println(pwm);
  Serial.print("Rev : ");
  Serial.println(rev);
  Serial.print("Stp : ");
  Serial.println(stp);
  Serial.print("Delay Time : ");
  Serial.println(delay_time);
  Serial.println("#######################################\n");
}
