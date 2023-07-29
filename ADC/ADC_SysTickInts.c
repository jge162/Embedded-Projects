// SysTickInts.c
// Runs on MSP432
// Use the SysTick timer to request interrupts at a particular period.
// Daniel Valvano, Jonathan Valvano
// June 1, 2015

/* This example accompanies the books
   "Embedded Systems: Introduction to MSP432 Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015
   Volume 1 Program 9.7

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include <stdint.h>
#include "ADC14.h"
#include "msp432p401r.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

volatile uint32_t ADCvalue;

// **************SysTick_Init*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//        Units of period are 333ns (assuming 3 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
volatile uint32_t Counts;
uint32_t wait_per;

void SysTick_Init(uint32_t period) {
    long sr = StartCritical();
    wait_per = period;

    ADC0_InitSWTriggerCh0();            // initialize ADC sample P5.5/A0

    Counts = 0;

    SysTick->CTRL = 0;                  // disable SysTick during setup
    SysTick->LOAD = period - 1;         // maximum reload value
    SysTick->VAL = 0;                   // any write to current clears it
    SCB->SHP[3] = (SCB->SHP[3]&0x00FFFFFF)|0x40000000;  // priority 2
    SysTick->CTRL = 0x00000007;         // enable SysTick with interrupts

    EnableInterrupts();

    EndCritical(sr);
}

void SysTick_Handler() {
    ADCvalue = ADC_In();
}

uint32_t SysTick_Mailbox() {
    return ADCvalue;
}

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 333 nsec for 3 MHz clock)
void SysTick_Wait(uint32_t delay) {
    long sr = StartCritical();
    // method #1: set Reload Value Register, clear Current Value Register, poll COUNTFLAG in Control and Status Register
    if(delay <= 1) {
        // without this step:
        // if delay == 0, this function will wait 0x00FFFFFF cycles
        // if delay == 1, this function will never return (because COUNTFLAG is set on 1->0 transition)
        return;                             // do nothing; at least 1 cycle has already passed anyway
    }

    SysTick->LOAD = (delay - 1);            // count down to zero
    SysTick->VAL = 0;                       // any write to CVR clears it and COUNTFLAG in CSR

    while((SysTick->CTRL&0x00010000) == 0);

    SysTick->LOAD = wait_per - 1;           // maximum reload value
    EndCritical(sr);
}

// Time delay using busy wait.
// This assumes 3 MHz system clock.
void SysTick_Wait10ms(uint32_t delay) {
    long sr = StartCritical();
    uint32_t i;
    for(i=0; i<delay; i++){
        SysTick_Wait(30000);                // wait 10ms (assumes 3 MHz clock)
    }
    EndCritical(sr);
}
