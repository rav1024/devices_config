#include "SerialDevice.hpp"


SerialDevice::SerialDevice(const byte r, const byte t, String n, String d): 
  Device(n, d), 
  SoftwareSerial(r, t), 
  rx(r), 
  tx(t) 
{
  //this->begin(9600);
}

byte SerialDevice::connectionTest(){ 
  delay(1000);
  if(this->available())
    return 1;
  else
    return 0;
}
