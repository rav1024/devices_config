#include "GPSUnit.hpp"

void GPSUnit::get_data(){
   while(this->available()) //necesary for read data to decode
      this->encode(this->read());
}

