//
//
//  espIRRemote - Arduino IR remote class with code LUT
//    IR code lookup table is in espIRRemote.h
//
//  Changes From Previous Version
//    Added more codes for TCL
//
//

#include "espIRRemote.h"

// Instanciate IRsend irLED on pin IRLEDPIN and begin irLED
espIRRemote::espIRRemote(int IRLEDPIN) : irLED(IRLEDPIN) {
  irLED.begin();
}

// Send IR code of coordinates of irCodes[][]
void espIRRemote::txIR(int remoteNumber, int irCode) {

  uint64_t irCodeToTX = irCodes[remoteNumber][irCode];                // Extract IR Code from array

  switch ( remoteNumber ) {                                           // Send appropriate IR modulation according to remoteNumber
    case 0:                                                           // TCL Series 4 Roku Remote
    case 4:                                                           // Incense Heater  
      irLED.sendNEC(irCodeToTX);                                      // 8-bit, 1x
      break;

    case 3:                                                           // 3x2 HDMI Matrix Switch
    case 6:                                                           // 4x2 HDMI Matrix Switch
    case 13:                                                          // Golden Power LED Lights
      irLED.sendNEC(irCodeToTX, 32, 1);                               // 32-bit. 1x
      break;

    case 5:                                                           // Philips PicoPix Max
      irLED.sendNEC(irCodeToTX, 32, 8);                               // 32-bit, 8x
      break;

    case 1:                                                           // Sony RM-YD023 & RM-YD092
      irLED.sendSony(irCodeToTX, 12, 2);                              // 12-bit, 2x
      break;

    case 2:                                                           // Sony RM-YD023 & RM-YD092
    case 7:                                                           // Sony RMT-AA401U AV System
    case 9:                                                           // Sony RMTDSLR2
    case 11:                                                          // Sony RMT-845
      irLED.sendSony(irCodeToTX, 15, 2);                              // 15-bit, 2x
      if ( remoteNumber == 7 && ( irCode == 21 || irCode == 22 ) ) {
        for ( int i = 0; i < 5; i++ ) {
          delay(200);
          irLED.sendSony(irCodeToTX, 15, 2);                          // Send the volume +/- 5x for AV system
        }
      }
      break;

    case 8:                                                           // Sony RMT-AA401U AV System
    case 10:                                                          // Sony RMTDSLR2
    case 12:                                                          // Sony RMT-845
      irLED.sendSony(irCodeToTX, 20, 2);                              // 20-bit, 2x
      break;
  }
}
