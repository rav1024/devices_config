#include "MoveSensor.hpp"

MoveSensor::MoveSensor(const byte p, String n, String d): Device(n, d), pin(p){
  pinMode(p, INPUT);  
};

bool MoveSensor::is_moving(){
  if(digitalRead(pin))
    return 1;
  else
    return 0;
}

