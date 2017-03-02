#include "Device.hpp"

void Device::whoami(){
  Serial.begin(9600);
  Serial.print("Nazwa urzadzenia: ");   
  Serial.println(this->nam);
  Serial.print("Opis urzadzenia: ");
  Serial.println(this->desc);
  Serial.end();
}

