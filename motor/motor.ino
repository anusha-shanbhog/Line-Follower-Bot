const int trigPin=5; 
  const int echoPin=11; 


void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
Serial.begin(9600);
  pinMode(13, OUTPUT);
  
}

void sensor(){
 long duration,inches,cm;
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pinMode(echoPin, INPUT); 
  duration=pulseIn(echoPin, HIGH);

  //convert time to distance
  
  inches=microsecondsToInches(duration);
  cm=microsecondsToCentimeters(duration);
  
  digitalWrite(13,LOW);
  
  if(inches<5){
  digitalWrite(13,HIGH);
  stopp();
  delay(5000);
  bwrd();
  delay(5000);
  left();
  delay(5000);
  frwd();
  }
  else
  {digitalWrite(13,LOW);
  frwd();
  }}


long microsecondsToInches(long microseconds)
{return microseconds / 74 / 2;}

long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}



void loop() 
{
 frwd();
 sensor();
 delay(5000);  
}

void frwd()
{digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(5000);}

  void bwrd()
  {digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(5000);}

  void stopp()
  {digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(5000);}

  void left()
   {digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(5000);}

void right()
   {    digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(5000);}

  
  
  
