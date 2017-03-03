#ifndef DEVICE_HPP
#define DEVICE_HPP
#include <Arduino.h>

class Device{
protected:
    String nam;
    String desc;
public:
    Device(String n, String d = ""): nam(n), desc(d) {};
    virtual void whoami();
};

#endif // DEVICE_HPP

