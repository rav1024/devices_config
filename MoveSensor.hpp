#ifndef MOVESENSOR_HPP
#define MOVESENSOR_HPP
#include "Device.hpp"

class MoveSensor: public Device {
protected:
    const byte pin;
public:
    MoveSensor(const byte p, String n = "Move Sensor", String d = "");
    bool is_moving();
};

#endif // MOVESENSOR_HPP
