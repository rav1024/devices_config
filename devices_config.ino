#include "GPSUnit.hpp"

GPSUnit gps(12, 11);
byte counter = 0;
byte t = 0;

void setup() {
  // put your setup code here, to run once:
  gps.whoami();
  Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
    
    gps.get_data();    
    
    if (t != gps.time.second())
    {
      Serial.println(++counter);
      Serial.println(gps.location.lat(), 8);
      Serial.println(gps.location.lng(), 8);
      Serial.println(gps.date.value());
      Serial.println(gps.time.value());
      Serial.println(gps.satellites.value());
      Serial.println();
      t = gps.time.second();
      delay(5010);
    }
}
