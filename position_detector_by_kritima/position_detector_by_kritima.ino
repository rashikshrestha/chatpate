int sensor_input=8;
int steps=0;
int previous_step=0;
int pwm_pin=2;
int pwm=100;
int in1=51;
int in2=53;
float rev=0;
float r=0;
char x=0;

int i1=3;
int i2=4;
int p=3;
int c=0;

void setup()
{ pinMode(sensor_input,INPUT);
  Serial.begin(9600);
  pinMode(pwm,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}

class Motor
{ public:

   void rotate()
   { analogWrite(pwm_pin,pwm);
     digitalWrite(in1,1);
     digitalWrite(in2,0);
    
     analogWrite(p,255);
     digitalWrite(i1,1);
     digitalWrite(i2,0);
     Serial.println("Started");
   }
  void Anti_clk()
  { digitalWrite(in1,0);
    digitalWrite(in2,1);
    Serial.println("Anti-Started");
  }
  void stop()
  { analogWrite(pwm_pin,pwm);
    digitalWrite(in1,0); 
    digitalWrite(in2,0);
    Serial.println("Stopped");
    Serial.println("Anticlock");
    delay(3);
    digitalWrite(in1,1);
    digitalWrite(in2,1);
    Serial.println("Stopped");
   
    digitalWrite(i1,0);
    digitalWrite(i2,0);
  
  }

   void step_counter()
   {  int temp=digitalRead(sensor_input);

      if (temp==0 && (previous_step==1))
      { steps=steps+1;
        previous_step=0;
        Serial.print("Steps:  ");
        Serial.println(steps);
      }

      if(temp==1 && (previous_step==0))
      { steps=steps+1;
        previous_step=1;
        Serial.print("Steps:  ");
        Serial.println(steps);
      }
    }
};
Motor m1;

void loop()
{ m1.step_counter();
  
  //m1.rotate();
  if (steps==72)
  { m1.stop();
  }
  /*if (steps==36)
  { 
    m1.Anti_clk();
  }
 
 */
 
 /* if(steps==2)
  { m1.stop();
    delay(2000);
    c=1;
  }
  
  if(c==1)
  { m1.step_counter();
    m1.Anti_clk();
    if (steps==2)
    {m1.stop();
     c=0;
    }
  }
  */
  
   if (Serial.available()>0)
  { x=Serial.read();
  
    if (x == 's')
    { m1.rotate();
      
    }

     if (x == 't')
     { m1.stop();
       steps=0;
       rev=0;
       r=0; 
       pwm=70;
       Serial.print( "Steps:  ");
       Serial.println(steps);
       Serial.print("Rev: ");
       Serial.println(rev);
     }

     if (x == 'u')
     { rev+=1.0;
       r= rev*36;
       Serial.print("Rev:  ");
       Serial.println(rev);
      }

      if (x == 'd')
      { pwm+=5;
        analogWrite(pwm_pin,pwm); 
        Serial.print("PWM:  ");
       Serial.println(pwm); 
      }

     
    }
}
