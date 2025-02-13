//
//
//  ESP8266 Sony IR Shutter Button
//
//

#include <IRsend.h>


/*--------          GPIO          ----------*/
/*--   Button attached to RESET and GND   --*/

const uint16_t IRLED = 2;  // GPIO2, D1D4 (change this)
IRsend irsend(IRLED);


/*---------------- IR Codes ----------------*/
// Both codes are 20-bit

static const uint64_t shutter = 0xB4B8F;
static const uint64_t shutterTwoSec = 0xECB8F;


/*--------   Main Functions    ----------*/

void setup() {
  irsend.begin();
  irsend.sendSony(shutter, 20, 2);  // 20-bit, 2x
  ESP.deepSleep(0);
}

void loop() {
  // Nothing Happens Here
}
