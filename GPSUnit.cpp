#include "GPSUnit.hpp"

void GPSUnit::get_data(){
   while(this->available()) //necesary for read data to decode
      this->encode(this->read());
}

void GPSUnit::print_data(byte sec){
  static byte t = 0;
  static int counter = 0;
  Serial.begin(9600);
  String s;
  
  this->get_data();
  
  if (t != this->time.second())
    {
      Serial.print("Lp. ");
      Serial.println(++counter);
      Serial.print("Latitude: ");
      Serial.println(this->location.lat());
      Serial.print("Longitude: ");
      Serial.println(this->location.lng());
      Serial.print("Date: ");
      Serial.println(this->date.value());
      Serial.print("Time: ");
      Serial.println(this->time.value());
      Serial.print("Satelites: ");
      Serial.println(this->satellites.value());
      Serial.println();
      
      t = this->time.second();
      delay((sec-1)*1000);
    }
  
  Serial.end();
}

