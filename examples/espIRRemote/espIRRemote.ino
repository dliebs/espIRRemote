//
// espIRRemote v1.0.4
// 2023.12.13
//

/*----------  Libraries  ----------*/

#include <espIRRemote.h>

/*----------  User Variables  ----------*/

espIRRemote irRemote(2);     // D1 Mini Built-in LED D4

/*----------  Program Variables  ----------*/



/*----------  Main Functions  ----------*/

void setup() { }

void loop() {
  irRemote.txIR(0,0);
  delay(5000);
}
