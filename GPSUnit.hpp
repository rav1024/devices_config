#ifndef GPSUNIT_HPP
#define GPSUNIT_HPP
#include "SerialDevice.hpp"
#include <TinyGPS++.h>

class GPSUnit{
private:
  SerialDevice serial;
  TinyGPSPlus gps;
  
  void get_data(); // use encoded() to get read NMEA frames
public:
  GPSUnit(byte rx, byte tx, String nam = "GPS", String desc = "Neo-7M"): serial(rx, tx, nam, desc){};
  void whoami(); 
  void print_data(byte sec = 1); //prints data from gps to serial output and delay sec (def 1s)
};

#endif //GPSUNIT_HPP
