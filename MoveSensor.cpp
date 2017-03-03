#include "MoveSensor.hpp"

MoveSensor::MoveSensor(const byte p, String n, String d): Device(n, d), pin(p){
  pinMode(p, INPUT);  
};

boolean MoveSensor::is_moving(byte sec, byte sens){
  double mv  = 0;
  double count = 0;

  while (count != sec){
  if(digitalRead(pin))
    mv++;
  count++;
  delay(1000);
  }

  if((mv/count)*100. > sens*10)
    return true;
  else
    return false;
}

