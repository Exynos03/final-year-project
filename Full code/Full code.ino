#include "DHT.h"
#define trigPin D4
#define echoPin D5
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
long duration;
int distance;

void setup() 
{
  Serial.begin(9600);
  Serial.println("DHT11 TEST 1");
  dht.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(D8, OUTPUT);
}

void loop()
 {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f) ) 
  {
    Serial.println("Failed to Read DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("'C ");
     digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

//ultra
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
  //buzz
   digitalWrite(D8, HIGH);
  delay(1000);
  digitalWrite(D8, LOW);
  delay(1000);

}




