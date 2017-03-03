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

void SerialDevice::whoami(){
  this->Device::whoami();
  Serial.begin(9600);
  Serial.print("PINs, RX: ");
  Serial.print(rx);
  Serial.print(", TX: ");
  Serial.println(tx);
  Serial.end();
}

