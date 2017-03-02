#ifndef SERIALDEVICE_HPP
#define SERIALDEVICE_HPP
#include "Device.hpp"
#include <SoftwareSerial.h>

class SerialDevice: public Device, public SoftwareSerial {
protected:  
  byte rx;
  byte tx;
public:
  SerialDevice(byte r, byte t, String n, String d = "");
  virtual byte connectionTest(); //if available() true return 1, else 0
};

#endif //SERIALDEVICE_HPP
