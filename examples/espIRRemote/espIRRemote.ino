//
// espIRRemote v1.0.2
// 2023.12.12
//

#define IRLEDPIN 13

/*----------  Libraries  ----------*/

#include <espIRRemote.h>

/*----------  User Variables  ----------*/


/*----------  Program Variables  ----------*/

//espIRRemote irRemote;

/*----------  Main Functions  ----------*/

void setup() { beginIR(); }

void loop() {
  txIR(0,0);
  delay(5000);
}
