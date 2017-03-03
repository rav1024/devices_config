#ifndef SERIALDEVICE_HPP
#define SERIALDEVICE_HPP
#include "Device.hpp"
#include <SoftwareSerial.h>

class SerialDevice: public Device, public SoftwareSerial {
protected:  
  const byte rx;
  const byte tx;
public:
  SerialDevice(const byte r, const byte t, String n, String d = "");
  virtual byte connectionTest(); //if available() true return 1, else 0
};

#endif //SERIALDEVICE_HPP
