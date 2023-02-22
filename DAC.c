#include <stdint.h>

#include "sound.h"

#include "msp432p401r.h"
 //------------------------------------------------------
// DAC_Init initialize P4 switches as inputs
// 4-bit quality DAC_Init below using 32 values
//------------------------------------------------------
void DAC_Init(void) {
  P4SEL0 &= ~0x0F; // GPIO port4 0x0F
  P4SEL1 &= ~0x0F; // GPIO port4 0x0F
  P4DIR |= 0x0F; // using ports P4.0-P4.3 as outputs
  P4OUT &= ~0x0F;
} //P4.0-P4.3 are now outputs
// End DAC_Init here-> Line 14
//------------------------------------------------------
// DAC_Out output for DAC below
//------------------------------------------------------
// Output will be 4-bit quality for this Lab5
// GPIO pins used will be p4.0, p4.1, p4.2, p4.3
// Output value is updated in the DAC_Out function module
void DAC_Out(uint32_t data) {
    P4OUT = (data); //Use
