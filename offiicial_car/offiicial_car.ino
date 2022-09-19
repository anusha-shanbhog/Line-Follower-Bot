const int trigPin = 5;//connect trigger pin to pin 4of arduino
const int echoPin = 4;// connect echo pin to pin2 of arduino

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);//left
  pinMode(6, OUTPUT);//left motor
  pinMode(7, OUTPUT);//right
  pinMode(8, OUTPUT);//right motor
}

void loop() {
  // put your main code here, to run repeatedly:
  //clock
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if (cm < 5)
  {
    stopp();
    delay(1000);
    rvs();
    delay(1000);
    right();
    delay(1000);
    frwd();
  }
  else
  {
    frwd();
  }
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void frwd()
{
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

}

void rvs()
{
  digitalWrite(3, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}

void right()
{
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}
void stopp()
{
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
