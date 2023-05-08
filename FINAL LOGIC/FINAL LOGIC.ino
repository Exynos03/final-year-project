#define trigPin D4
#define echoPin D8

#define DHTPIN D2
#define DHTTYPE DHT11

#include "DHT.h"

DHT dht(DHTPIN, DHTTYPE);
long duration;
int distance;


void setup() {
  //HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // DHT-11
  Serial.begin(9600);
  Serial.println("DHT11 TEST 1");
  dht.begin();
}

void loop() {
  //DHT-11
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to Read DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print(" Temperature: ");
  Serial.print(t);
  Serial.print("'C ");

  Serial.print("Temperature: ");
  Serial.print(f);
  Serial.print("'F ");

  //HC-SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;  // s=t*v

  Serial.print("Distance: ");
  Serial.print(distance);
  delay(500);

  if (distance <= 10) {
    //Serial.println();
    Serial.print(" High Flood Alert");
    tone(14, 1000, 300);
    delay(300);
  }

  if (distance > 10 && distance <= 30) {
    //Serial.println();
    Serial.print(" Water level at cautious level");
    tone(14, 500, 100);
    delay(300);
  }

  Serial.println();
}