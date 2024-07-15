//
// espIRRemote v1.0.1
// 2023.12.12
//

/*----------  Libraries  ----------*/

#include <espIRRemote.h>

/*----------  User Variables  ----------*/

#define IRLEDPIN 13

/*----------  Program Variables  ----------*/

espIRRemote irRemote;

/*----------  Main Functions  ----------*/

void setup() { }

void loop() {
  irRemote.txIR(0,0);
  delay(5000);
}
