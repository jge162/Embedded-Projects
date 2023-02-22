#include <stdint.h>
#include "SysTickInts.h"
#include "Piano.h"
#include "msp432p401r.h"
#include "Sound.h"
//------------------------------------------
//void Main to use non-conditional while(1)
//------------------------------------------
void main(void) {
  char piano_note;
  Piano_Init(); //Initializing Piano_Init
  Sound_Init(); //Initializing Sound_Init
  while (1) {
    piano_note = Piano_In();
    //Take in input from Piano_in() pass to if statements to verify note requested
    if (piano_note == 1) {
      SysTick -> LOAD = (213);
    }
    // Note A Frequency 440 Hz (3*10^6/440)/32 = 213 SysTick counts/value
    else if (piano_note == 2) {
      SysTick -> LOAD = (284);
    }
    // Note E Frequency 330 Hz (3*10^6/330)/32 = 284 SysTick counts/value
    else if (piano_note == 4) {
      SysTick -> LOAD = (253);
    }
    // Note G_b Frequency 370 Hz (3*10^6/370)/32 = 253 SysTick counts/value
    else if (piano_note == 0) {
      Sound_Off();
    }
    // Sound_Off() by default.
  }
}; //end void main here and while(1)
