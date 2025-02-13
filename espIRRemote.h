//
//
//  espIRRemote - Arduino IR remote class with code LUT
//    IR code lookup table is in espIRRemote.h
//
//  Changes From Previous Version
//    Added more codes for TCL
//
//

#ifndef espIRRemote_h
#define espIRRemote_h

/*----------  Libraries  ----------*/

#include "Arduino.h"
#include <IRsend.h>

/*---------------- IR Codes ----------------*/
/*-- *All the remotes exist in one array* --*/

// TCL Series 4 Roku Remote - 0            0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15          16          17          18          19          20          21          22
//                                         Power       Back        Home        Up          Left        Down        Right       Ok          Jump Back?  */Option    Rewind      Play/Pause  Fast Fwd    Vol Up      Vol Down    Mute        Off         On          HDMI1       HDMI2       HDMI3       AV          Antenna
static const uint64_t irCodes[14][28] = { {0x57E3E817, 0x57E36699, 0x57E3C03F, 0x57E39867, 0x57E37887, 0x57E3CC33, 0x57E3B44B, 0x57E354AB, 0x57E31EE1, 0x57E38679, 0x57E32CD3, 0x57E332CD, 0x57E3AA55, 0x57E3F00F, 0x57E308F7, 0x57E304FB, 0x57E318E7, 0x57E316E9, 0x57E3847B, 0x57E344BB, 0x57E3C43B, 0x57E3A45B, 0x57E3D42B},
// Sony RM-YD023 & RM-YD092 - 1            0      1      2      3      4      5     6      7      8      9      10     11     12     13     14    15     16     17     18     19    20     21     22     23     24     25     26     27
//   12 bit                                Power  Input  PicOff Disp   Sleep  Home  Pict   Up     Left   Down   Right  Ok     Vol +  Vol -  Ch +  Ch -   Jump   Mute   0      1     2      3      4      5      6      7      8      9
                                          {0xA90, 0xA50, 0x7D0, 0x5D0, 0x6D0, 0x70, 0x270, 0x2F0, 0x2D0, 0xAF0, 0xCD0, 0xA70, 0x490, 0xC90, 0x90, 0x890, 0xDD0, 0x290, 0x910, 0x10, 0x810, 0x410, 0xC10, 0x210, 0xA10, 0x610, 0xE10, 0x110},
// Sony RM-YD023 & RM-YD092 - 2            0      1       2       3       4       5       6       7       8       9       10     11      12      13      14      15      16
//   15 bit                                SyncMu Wide    Option  Return  Rwd     FF      Play    Pause   Prev    Next    Stop   Yellow  Blue    Red     Green   .       CC
                                          {0xD58, 0x5E25, 0x36E9, 0x62E9, 0x6CE9, 0x1CE9, 0x2CE9, 0x4CE9, 0x1EE0, 0x5EE9, 0xCE9, 0x72E9, 0x12E9, 0x52E9, 0x32E9, 0x5CE9, 0x425},
// 3x2 HDMI Matrix Switch   - 3            0          1          2          3          4          5
//   Codes overlap with Incense Heater     Out A1     A2         A3         Out B1     B2         B3
                                          {0x1FE48B7, 0x1FE807F, 0x1FE20DF, 0x1FE7887, 0x1FEC03F, 0x1FE609F},
// Incense Heater           - 4            0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16         17
//                                         Power      Fan Off    1          2          3          Temp +     Temp -     50C        100C       200C       210C       220C       230C       Timer 0hr  2hr        4hr        Audio      Light
                                          {0x1FE7887, 0x1FE10EF, 0x1FE20DF, 0x1FEA05F, 0x1FE609F, 0x1FED827, 0x1FEB04F, 0x1FEE01F, 0x1FE906F, 0x1FE50AF, 0x1FEF807, 0x1FE30CF, 0x1FE708F, 0x1FE807F, 0x1FE40BF, 0x1FEC03F, 0x1FE48B7, 0x1FE58A7},
// Philips PicoPix Max      - 5            0           1           2           3           4           5           6           7           8           9           10          11          12
//   Mouse button doesn't do anything      Power       Mouse       Up          Left        Down        Right       Ok          Back        Menu        Home        Vol -       Vol +       Auto Focus
                                          {0x40BF48B7, 0x00000000, 0x40BFF807, 0x40BFF00F, 0x40BF827D, 0x40BF906F, 0x40BF22DD, 0x40BF0AF5, 0x40BFC837, 0x40BF40BF, 0x40BF609F, 0x40BF00FF, 0x40BFC03F},
// 4x2 HDMI Matrix Switch   - 6            0          1          2          3          4          5          6          7          8
//   Codes overlap with Incense Heater     Power      Out A1     A2         A3         A4         Out B1     B2         B3         B4
                                          {0x1FE48B7, 0x1FE807F, 0x1FEC03F, 0x1FE20DF, 0x1FE609F, 0x1FEE01F, 0x1FE906F, 0x1FE50AF, 0x1FEF807},
// Sony RMT-AA401U AV Systm - 7            0       1      2       3       4       5       6      7       8       9       10     11      12      13      14     15      16      17      18      19      20      21      22
//   15 bit                                Power   Sleep  SAT     GAME    CD      TV      FM     2Ch     Movie   Music   Night  Dimmer  Disp    AmpMenu Up     Down    Left    Right   Ok      Home    Mute    Vol +   Vol -
                                          {0x540C, 0x30C, 0x600D, 0x1F0C, 0x520C, 0x2B0C, 0xC0C, 0x710D, 0x610D, 0x490D, 0x20D, 0x590C, 0x690C, 0x770D, 0xF0D, 0x4F0D, 0x2F0D, 0x6F0D, 0x180C, 0x650C, 0x140C, 0x240C, 0x640C},
// Sony RMT-AA401U AV Systm - 8            0        1        2       3        4        5        6        7        8        9        10       11       12      13       14
//   20 bit                                Info     BlueT    Media   BD       BT Pair  PureDir  Frt Sur  Back     Options  RW/Tun-  Play/Mem FF/Tun+  Prev    Stop     Next
                                          {0x18110, 0x8E114, 0x2116, 0x68114, 0xEE114, 0x9E114, 0x9C116, 0xBE110, 0xCE110, 0xCC110, 0x5C110, 0x2C110, 0xC110, 0x1C110, 0x8C110},
// Sony RMTDSLR2            - 9            0       1
//   15 bit - From Web                     Tight   Wide
                                          {0x2C9B, 0x6C9B},
// Sony RMTDSLR2            - 10           0        1        2        3        4        5        6       7        8        9        10       11       12       13       14       15       16
//   20 bit - From Web                     Shtr     Shtr 2s  Rec      Disp     Menu     Histogr  Focus   Up       Down     Left     Right    Enter    Rotate   Play     Slidesh  Print    Trash
                                          {0xB4B8F, 0xECB8F, 0x12B8F, 0x28B8F, 0x1CB8F, 0xD8B8F, 0x4B8F, 0x5CB8F, 0xDCB8F, 0x7CB8F, 0xFCB8F, 0x9CB8F, 0x4CB8F, 0x3CB8F, 0xE2B8F, 0x88B8F, 0xBCB8F},
// Sony RMT-845             - 11           0       1
//   15 bit                                Tight   Wide
                                          {0x2C9B, 0x6C9B},
// Sony RMT-845             - 12           0       1        2        3        4        5        6        7        8        9        10       11      12       13       14       15       16
//   20 bit                                Rec     Display  Up       Down     Left     Right    Enter    Mode     Play     Pause    Stop     Prev    Next     Scan R   Scan F   TC Rst   Data Code
                                          {0xCBC0, 0x2AB44, 0x9EB44, 0x5EB44, 0xDEB44, 0x3EB44, 0xD0B44, 0xD8B44, 0x4CB44, 0x9CB44, 0x1CB44, 0xCB44, 0x8CB44, 0x44B44, 0xC4B44, 0xBEBC0, 0xCCBC0},
// Golden Power LED Lights  - 13           0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15
//   32 Bit, used by macro() funcs         On          Off         Dim -       Dim +       M1          M2          M3          M4          M5          M6          M7          M8          6H          8H          6639H       Timer Off
                                          {0x40BF00FF, 0x40BF40BF, 0x40BF28D7, 0x40BF6897, 0x40BF20DF, 0x40BFA05F, 0x40BF10EF, 0x40BF906F, 0x40BF30CF, 0x40BFB04F, 0x40BF08F7, 0x40BF8877, 0x40BF609F, 0x40BF50AF, 0x40BF708F, 0x40BF807F}
};

class espIRRemote {
  public:
    // Create IR Remote on input pin
    espIRRemote(int);
    // Send IR code of coordinates of irCodes[][]
    void txIR(int, int);
  private:
    // Instanciated upon creation of espIRRemote object
    IRsend irLED;
};

#endif
