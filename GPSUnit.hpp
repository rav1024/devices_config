#ifndef GPSUNIT_HPP
#define GPSUNIT_HPP
#include "SerialDevice.hpp"
#include <TinyGPS++.h>

class GPSUnit: public SerialDevice, public TinyGPSPlus {
public:
  GPSUnit(byte rx, byte tx, String nam = "GPS", String desc = "Neo-7M"): SerialDevice(rx, tx, nam, desc){};
};

#endif //GPSUNIT_HPP
