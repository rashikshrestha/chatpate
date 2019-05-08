int t = 1;
char cmd;
int pwm = 60;


void setup()
{
  Serial.begin(9600);
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

  pinMode(5,OUTPUT);

  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  
}

void loop()
{
  commander();
  

}

void on()
{
  digitalWrite(5,HIGH);
  analogWrite(2,pwm);
}

void off()
{
  digitalWrite(2,LOW);
  digitalWrite(5,LOW);
}

void commander()
{
  while (Serial.available())
  {
    cmd = Serial.read();

    if (cmd == 'r')
    {
      on();
      Serial.println("ON");
    }

    if (cmd == 't')
    {
      off();
      Serial.println("OFF");
    }

    if (cmd == 'u')
    {
      t += 1;
      Serial.println(t);
      
    }

    if (cmd == 'd')
    {
      t -= 1;
      Serial.println(t);
      
    }

    if (cmd == 's')
    {
      Serial.println("started");
      
      on();
      delay(t*1000);
      off();

      Serial.println("finished\n\n");
      
    }

   




  }
}
