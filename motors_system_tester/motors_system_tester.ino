#define wait 1000

#define A1_pwm    11 ;   #define A1_dir      40    #define A1_enc      27

#define A2_pwm    10
#define A2_dir      38
#define A2_enc      29

#define A3_pwm    13
#define A3_dir      48
#define A3_enc      31

#define A4_pwm    12
#define A4_dir      42
#define A4_enc      33

///////////////////////////////////////////

#define B1_pwm    7
#define B1_dir      32
#define B1_enc      35

#define B2_pwm    6
#define B2_dir      30
#define B2_enc      37

#define B3_pwm    9
#define B3_dir      36
#define B3_enc      39

#define B4_pwm    8
#define B4_dir      34
#define B4_enc      41

void setup() 
{
  // put your setup code here, to run once:

//  digitalWrite(A3_pwm,1);
//  digitalWrite(A3_dir,0);
 
}

void loop() 
{
  

//  digitalWrite(B4_pwm,0);
//  digitalWrite(B1_pwm,1);
//  digitalWrite(B1_dir,0);

 motorboard_A();
 
  motorboard_B();
 

}

void motorboard_A()
{
  digitalWrite(B4_pwm,0);
  digitalWrite(A1_pwm,1);
  digitalWrite(A1_dir,1);

  delay(wait);

  digitalWrite(A1_pwm,0);
  digitalWrite(A2_pwm,1);
  digitalWrite(A2_dir,1);

  delay(wait);

  digitalWrite(A2_pwm,0);
  digitalWrite(A3_pwm,1);
  digitalWrite(A3_dir,1);

  delay(wait);

   digitalWrite(A3_pwm,0);
  digitalWrite(A4_pwm,1);
  digitalWrite(A4_dir,1);

  delay(wait);
}

void motorboard_B()
{
//  digitalWrite(A4_pwm,0);
//  digitalWrite(B1_pwm,1);
//  digitalWrite(B1_dir,1);
//
//  delay(1000);

  digitalWrite(A4_pwm,0);
  digitalWrite(B2_pwm,1);
  digitalWrite(B2_dir,1);

  delay(wait);

  digitalWrite(B2_pwm,0);
  digitalWrite(B3_pwm,1);
  digitalWrite(B3_dir,1);

  delay(wait);

   digitalWrite(B3_pwm,0);
  digitalWrite(B4_pwm,1);
  digitalWrite(B4_dir,1);

  delay(wait);
}





