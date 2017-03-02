#include "GPSUnit.hpp"

void GPSUnit::get_data(){
   while(serial.available()) //necesary for read data to decode
      gps.encode(serial.read());
}

void GPSUnit::print_data(byte sec){
  static byte t = 0;
  static int counter = 0;
  Serial.begin(9600);
  String s;
  
  this->get_data();
  
  if (t != gps.time.second())
    {
      Serial.print("Lp. ");
      Serial.println(++counter);
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat());
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng());
      Serial.print("Date: ");
      Serial.println(gps.date.value());
      Serial.print("Time: ");
      Serial.println(gps.time.value());
      Serial.print("Satelites: ");
      Serial.println(gps.satellites.value());
      Serial.println();
      
      t = gps.time.second();
      delay((sec-1)*1000);
    }
  
  Serial.end();
}

void GPSUnit::whoami(){
  this->serial.whoami();
}

