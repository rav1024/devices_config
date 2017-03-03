#ifndef GPSUNIT_HPP
#define GPSUNIT_HPP
#include "SerialDevice.hpp"
#include <TinyGPS++.h>

class GPSUnit: public SerialDevice{
private:
  TinyGPSPlus gps;
  
  void get_data(); // use encoded() to get read NMEA frames

public:
  GPSUnit(const byte rx, const byte tx, String nam = "GPS", String desc = "Neo-7M"): SerialDevice(rx, tx, nam, desc){};
  //void whoami(); 
  void print_data(byte sec = 1); //prints data from gps to serial output and delay sec (def 1s)
  boolean connectionTest();
};

#endif //GPSUNIT_HPP
