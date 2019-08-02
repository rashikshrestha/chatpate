#define l1 13
#define l2 12
#define l3 48
#define l4 42
#define l5 40
#define l6 38
#define l7 11
#define l8 10

//#define l1 9
//#define l2 8
//#define l3 36
//#define l4 34
//#define l5 32
//#define l6 30
//#define l7 7
//#define l8 6

//#define l1 5
//#define l2 4
//#define l3 28
//#define l4 26
//#define l5 24
//#define l6 22
//#define l7 3
//#define l8 2

//#define l1 41
//#define l2 39
//#define l3 37
//#define l4 35
//#define l5 33
//#define l6 31
//#define l7 29
//#define l8 27

//#define l1 A14
//#define l2 A15
//#define l3 50
//#define l4 52
//#define l5 53
//#define l6 51
//#define l7 49
//#define l8 47

//#define l1 A6
//#define l2 A7
//#define l3 A8
//#define l4 A9
//#define l5 A10
//#define l6 A11
//#define l7 A12
//#define l8 A13

//#define l1 A0
//#define l2 A1
//#define l3 A2
//#define l4 A3
//#define l5 A4
//#define l6 A5
//#define l7 A6
//#define l8 A7

void setup()
{
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);


}

void loop()
{
  digitalWrite(l8, LOW);
  digitalWrite(l1, HIGH);
  delay(500);

  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(500);

   digitalWrite(l2, LOW);
  digitalWrite(l3, HIGH);
  delay(500);

   digitalWrite(l3, LOW);
  digitalWrite(l4, HIGH);
  delay(500);

   digitalWrite(l4, LOW);
  digitalWrite(l5, HIGH);
  delay(500);

   digitalWrite(l5, LOW);
  digitalWrite(l6, HIGH);
  delay(500);

   digitalWrite(l6, LOW);
  digitalWrite(l7, HIGH);
  delay(500);

   digitalWrite(l7, LOW);
  digitalWrite(l8, HIGH);
  delay(500);

}
