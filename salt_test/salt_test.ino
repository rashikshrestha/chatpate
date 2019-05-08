

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

  pinMode(8, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  disp_cond();



}

void loop()
{
  commander();
  new_stat = digitalRead(8);
  if (new_stat != stat)
  {
    stat = new_stat;
    stp++;
    Serial.print("Steps: ");
    Serial.println(stp);
  }


  if (opp==0 && stp >= 9 * rev)
  {
    Serial.println("Revolution Completed");
    stop();
    //dir2();
    stp = 0;
    //opp = 1;
  }

  if(opp==1 && stp >= 9 * rev)
  {
    Serial.println("Opposite Revolution Completed");
    
    stop();
    stp=0;
    opp = 0;
    
  }

  if(opp==2 && stp >= 36 * rev *2)
  {
    Serial.println("More Opposite Revolution Completed");
    
    stop();
    stp=0;
    opp = 0;

    disp_cond();
    
  }

  
  
}

void dir2()
{
  analogWrite(2, pwm);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
}

void dir1()
{
  analogWrite(2, pwm);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
}

void stop()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
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

    if(cmd == 'p')
    {
      disp_cond();
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
  Serial.println("#######################################\n");
  
  
}
