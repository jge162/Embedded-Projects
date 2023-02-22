#include <stdint.h>
#include "SysTick.h"
#include "LEDinit.h"
#include "Switchinputs.h"
#include "msp432p401r.h"
//----------------------------
// Struct declaration here
//----------------------------
struct State {
 uint32_t Out[2]; // Out ->unsigned 32 bit integers
 uint32_t Time; // 10 ms unsigned 32 bit integers
 const struct State *Next[15]; // 3 inputs and 8 outputs total of 11 FSM
states
};
//----------------------------------------------------------------------------
// Tydef declaration here
//----------------------------------------------------------------------------
typedef const struct State State_t;
#define goN &FSM[0] // Go North
#define waitN &FSM[1] // Wait North
#define goE &FSM[2] // Go East
#define waitE &FSM[3] // Wait on East
#define walk &FSM[4] // Someone pushing the Walk button
#define walk0 &FSM[5] // Do not Walk Solid red LED
#define walk1 &FSM[6] // Do not Walk Solid red LED
#define walk2 &FSM[7] // Do not Walk Solid red LED
#define walk3 &FSM[8] // Do not Walk Solid red LED
#define walk4 &FSM[9] // Do not Walk Solid red LED
#define walk5 &FSM[10] // Go North/Go East red LED
#define walk6 &FSM[11] // Go North/Go East red LED
#define walk7 &FSM[12] // Do not Walk Solid red LED
//----------------------------------------------------------------------------
// State FSM declaration here
//----------------------------------------------------------------------------
State_t FSM[15] = { // Need to use specific bits per operation, so take note
//----------------------------------------------------------------------------
// 4 states here; "000" 3-bit inputs MSB is walk, second is goN, last goE.
//----------------------------------------------------------------------------
{{0x0C,0x01},180, {goN,waitN,goN,waitN, walk,walk,walk,walk}},//100
{{0x14,0x01},50, {goE,goE,goE,goE, walk,walk,walk,walk}},//010
{{0x21,0x01},180, {goE,goE,waitE,waitE, walk,walk,walk,walk}},//001
{{0x22,0x01},50, {goN,goN,goN,goN, walk,walk,walk,goN}}, //010
//----------------------------------------------------------------------------
// Next 11 states here
//----------------------------------------------------------------------------
{{0x24,0x01},120, {walk0,walk0,walk0,walk0,walk0,walk0,walk0,walk0}},//red LED
{{0x24,0x01},120, {walk1,walk1,walk1,walk1,walk1,walk1,walk1,walk1}},//red LED
{{0x24,0x02},150, {walk2,walk2,walk2,walk2,walk2,walk2,walk2,walk2}},//green
{{0x24,0x00},80, {walk3,walk3,walk3,walk3,walk3,walk3,walk3,walk3}},//no LED
7
{{0x24,0x01},80, {walk4,walk4,walk4,walk4,walk4,walk4,walk4,walk4}},//red led
{{0x24,0x00},80, {walk5,walk5,walk5,walk5,walk5,walk5,walk5,walk5}},//no LED
{{0x24,0x01},80, {walk6,walk6,walk6,walk6,walk6,walk6,walk6,walk6}},//red LED
{{0x24,0x00},80, {walk7,walk7,walk7,walk7,walk7,walk7,walk7,walk7}},//no LED
{{0x24,0x01},80, {goE,goE,goN,goN,goE,goE,goN,goE}},//red LED
{{0x24,0x00},80, {goE,goE,goN,goN,goE,goE,goN,goE}},//no LED
{{0x24,0x02},80, {walk0,walk0,walk0,walk0,walk0,walk0,walk0,walk0}}//Green
};
//----------------------------------------------------------------------------
// void main below used to execute While(1) loop, not conditional While loop.
//----------------------------------------------------------------------------
void main(void) {
State_t *Pt; // Pointer
Switch_Inputs(); // INPUTS for bread board and
micro-controller ORR together here and LSL for p1.1
GPIO_Init_p1_p2(); // Call into main Inits for GPIOs
SysTick_Init(); // Call into main SysTick
GPIO_Init_p4(); // Call into main GPIO Outputs
GPIO_Init_p6(); // Call into main GPIO Inputs
Pt = goE; //Initial state goN
while(1){ // not conditional
P4->OUT = (P4->OUT&~0x3F)|(Pt->Out[0]); // Set LEDs on Bread board
P2->OUT = (P2->OUT&~0x3F)|(Pt->Out[1]); // Set LEDs Micro-controller
SysTick_Wait10ms(Pt->Time); //SysTic is 10 ms
Pt = Pt->Next[Input]; // Input here, generates next state based on switch
pressed (p6.0, p6.1 or p1.1)
 }
}
