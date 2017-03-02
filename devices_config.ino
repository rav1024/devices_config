#include "GPSUnit.hpp"

const byte gps_rx = 12;
const byte gps_tx = 11;
 
GPSUnit gps(gps_rx, gps_tx);

void setup() {
  // put your setup code here, to run once:
  gps.whoami();
}

void loop() {
// put your main code here, to run repeatedly:
       
    gps.print_data(5);
    
}
