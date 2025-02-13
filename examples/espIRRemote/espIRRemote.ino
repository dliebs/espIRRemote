//
//
//  espIRRemote - Arduino IR remote class with code LUT
//    IR code lookup table is in espIRRemote.h
//
//  Changes From Previous Version
//    Added more codes for TCL
//
//

/*----------  Libraries  ----------*/

#include <espIRRemote.h>

/*----------  User Variables  ----------*/

// Creates IR remote on input pin
espIRRemote irRemote(LED_BUILTIN);

/*----------  Program Variables  ----------*/



/*----------  Main Functions  ----------*/

void setup() { }

void loop() {
  // Transmit IR code of irCodes[][] in espIRRemote.h
  irRemote.txIR(0,0);
  delay(5000);
}
