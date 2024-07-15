//
//
//  espIRRemote - Version 1.0.7
//  Based on IRsend
//  This version was not deployed [2023.12.13]
//
//  Universal IR remote class
//    Ability to create multiple of class on different pins
//    IR codes are built into espIRRemote.h
//
//  Changes From Previous Version
//    Comments, cleanup
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
