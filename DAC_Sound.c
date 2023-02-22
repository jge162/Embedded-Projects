#include <stdint.h>
#include "Piano.h"
#include "DAC.h"
#include "SysTickInts.h"
#include "msp432p401r.h"

const uint32_t wave[32] = {//using 32 samples
8,9,11,12,13,14,14,15,15,15,
14,14,13,12,11,9,8,7,5,4,3,
2,2,1,1,1,2,2,3,4,5,7};
extern uint32_t index;
extern uint32_t index;
uint32_t index = 0; //initialize at zero
// Initialize SysTick_Init interrupts
// Also uses DAC_Init() to utilize the DAC in Sound_Init
// Input is not done here in Init or Output either
// Using piano_Piano_notes - A,B,C
//------------------------------------------------------------
void Sound_Init(void) { //Initializes here
  DAC_Init(); //DAC_Init here (p4 output, 4-bit quality
  SysTick_Init(1);
};
// Init of DAC done here
// I have chosen. Also will enable SysTick_Init here
//------------------------------------------------------------
void Sound_Play(void) { //Piano_notes ABC here
  // index++
  // Check if wrapped, if so reset to 0
  DAC_Out(wave[index]);
  index++;
  if (index > 31) {
    index = 0;
  }
} //------------------------------------------------------------
// Sound_Play_Off()
//------------------------------------------------------------
void Sound_Off(void) {
  SysTick -> LOAD = (0);. //Turn off here
} // End Sound_Play_Off() here-> Line 70
