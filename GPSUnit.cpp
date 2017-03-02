#include "GPSUnit.hpp"

void GPSUnit::get_data(){
   while(serial.available()) //necesary for read data to decode
      gps.encode(serial.read());
}

void GPSUnit::print_data(byte sec){
  static byte t = 0;
  static int counter = 0;
  Serial.begin(9600);
  char sz[32];

  serial.begin(9600);
  this->get_data();
  //serial.end();
  
  if (t != gps.time.second())
    {
      Serial.println("");
      Serial.print("Lp. ");
      Serial.println(++counter);

      Serial.print("Satelites: "); //not wroking some reason when  if confition is...no! it just need a while
      Serial.println(gps.satellites.value());

      Serial.print("Horizontal precision (ideal = 1): ");
      Serial.println(gps.hdop.value()/100.);
      
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);

      Serial.print("Altitude (m): ");
      Serial.println(gps.altitude.meters());
      
      //Serial.print("Date: ");
      sprintf(sz, "Date: %02u-%02u-%u", gps.date.day(), gps.date.month(), gps.date.year());
      Serial.println(sz);
      
      //Serial.print("Time: ");
      sprintf(sz, "Time: %02u:%02u:%02u", gps.time.hour(), gps.time.minute(), gps.time.second());
      Serial.println(sz);

      Serial.print("Speed (km/h): ");
      Serial.println(gps.speed.kmph());

      Serial.println();
      
      t = gps.time.second();
      delay((sec-1)*1000);
    }
  
  Serial.end();
}

void GPSUnit::whoami(){
  this->serial.whoami();
}

void GPSUnit::connectionTest(){
  serial.begin(9600);
  Serial.begin(9600);
  if(serial.connectionTest())
    Serial.println("Connection: OK");
  else
    Serial.println("Connection ERROR");
  Serial.end();
  serial.end();
}

