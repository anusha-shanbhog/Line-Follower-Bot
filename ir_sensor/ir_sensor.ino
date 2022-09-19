void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(3, OUTPUT);//left
  pinMode(6, OUTPUT);//left motor
  pinMode(7, OUTPUT);//right
  pinMode(8, OUTPUT);//right motor
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(10,150);
  analogWrite(11,150);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((digitalRead(4) == LOW) && (digitalRead(5) == LOW)) // Condition_1 stop
  {
    frwd();
  }

  if ((digitalRead(4) == HIGH) && (digitalRead(5) == HIGH)) //CONDITION-2 FORWRD
  {
    stopp();
  }
  if ((digitalRead(4) == LOW) && (digitalRead(5) == HIGH))  // RIGHT
  {
    right();
  }
  if ((digitalRead(4) == HIGH) && (digitalRead(5) == LOW))
  {
    left();
  }
  else
  {
    frwd();
  }
}

void frwd()
{
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

}
void right()
{
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}
void left()
{
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void stopp()
{
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
