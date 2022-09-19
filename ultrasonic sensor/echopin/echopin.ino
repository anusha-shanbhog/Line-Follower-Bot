const int trigPin=5; 
const int echoPin=4; 



void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {

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
  
  if(inches<5)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);
  

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(500);

}

long microsecondsToInches(long microseconds)
{return microseconds / 74 / 2;}

long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}


  
  
  
