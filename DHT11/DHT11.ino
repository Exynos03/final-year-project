#include "DHT.h"

#define DHTPIN D2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 TEST 1");
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f) ) {
    Serial.println("Failed to Read DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("'C ");

  Serial.print("Temperature: ");  
  Serial.print(f);
   Serial.print("'F ");

}

