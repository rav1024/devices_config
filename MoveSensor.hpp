#ifndef MOVESENSOR_HPP
#define MOVESENSOR_HPP
#include "Device.hpp"

class MoveSensor: public Device {
protected:
    const byte pin;
public:
    MoveSensor(const byte p, String n = "Move Sensor", String d = "");
    boolean is_moving(byte sec = 10, byte sens = 3); //check if device moving in sec sameple (at least 5 sec recommended)
                                            //sens - sensitivity of sensor, 1-10 scale, 
                                            //if 10 - very low sensitive, must be 100% move reading in sec time 
                                            //if 1 - very high sensitive, 10% move readin in sec time
    void whoami();
};

#endif // MOVESENSOR_HPP
