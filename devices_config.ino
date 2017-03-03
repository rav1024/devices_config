#include "GPSUnit.hpp"
#include "MoveSensor.hpp"

const byte gps_rx = 12;
const byte gps_tx = 11;
const byte ms_pin = 10;

Device* dev = new Device("New Device", "This is just new device"); 
SerialDevice sd(5, 6, "Serial Device", "New serial device");
GPSUnit gps(gps_rx, gps_tx);
MoveSensor ms(ms_pin);

void setup() {
  // put your setup code here, to run once:
  //gps.whoami();
  //gps.connectionTest();

  //ms.whoami();

  dev->whoami();

  dev = &sd;
  dev->whoami();

  dev = &ms;
  dev->whoami();
  
}

void loop() {
// put your main code here, to run repeatedly:
/* 
    gps.print_data(5);
    
    Serial.begin(9600);
    Serial.print("Is moving? ");
    Serial.println(ms.is_moving(5, 2));
    Serial.println("");
    Serial.end();
*/
}
