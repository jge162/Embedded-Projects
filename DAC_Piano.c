#include <stdint.h>

#include "msp432p401r.h"
 //-------------------------------------------------
//"GPIO Pianot_Note Ports 5 initialized here"
//(Pianot_Note from 3 breadboard switches are as follows)
//Piano note A (Frequency 440 Hz)-pin P5.0
//Piano note E (Frequency 494 Hz)-pin P5.1
//Piano note G_b (Frequency 523 Hz)-pin P5.2
//-------------------------------------------------
// Piano_Init() below
//---------------------------- ---------------------
void Piano_Init(void) {
  P5SEL0 &= ~0x07; //GPIOs P5
  P5SEL1 &= ~0x07; //GPIOs P5
  P5DIR &= ~0x07; //make P5.0 - P5.2 Pianot_Notes
} // End Piano_Init here-> Line 30
//-------------------------------------------------
// Piano_Note from pianos keys p5.0, p5.1 and p5.2
// p5.0 is 0x01 is breadboard Piano_key A
// p5.1 is 0x02 is breadboard Piano_key E
// p5.2 is 0x04 is breadboard Piano_key G_b
//-------------------------------------------------
// Piano_In() below
//-------------------------------------------------
char Piano_In(void) {
  char input = P5IN & 0x07;
  return input;
}
