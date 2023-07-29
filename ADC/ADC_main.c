// Jeremy Escobar Fall 2022
#include <stdint.h>
#include <stdio.h>
#include "SysTickInts.h"
#include "LCD.h"
#include "msp432p401r.h"
#include  "ADC14.h"

double Slope = 0.12246;
//using 'Double' for ADC_value gives more precision
//(y2-y1/x2-x1)->(2-0)/(16383-52)= 0.00012246647
//(0.00012246647)1000 = 0.12246
double Slope_correction = 6;
//slope correction Y=MX+B -> 0=0.12246(52)+B=6

void main() {
  uint32_t ADC; //Unsigned integer ADC
  ADC0_InitSWTriggerCh0(); //trigger
  SysTick_Init(75000); //SysTick_Init(1) initialize
  LCD_Init(); //LCD_Init initialize here
  LCD_OutString("Lab 6"); //LCD OutString "letters"

  while (1) {
    ADC = (ADC_In() * (Slope) - (Slope_correction));
    //multiple (ADC*Slope-(Correction))
    LCD_OutCmd(0xC0); //Skip a line here to-> Output...
    //the fixed-point number on the LCD.
    LCD_OutUFix(ADC); //Digital output ADC after it has been...
    //multiplied by Slope (mapping) then...
    //convert the sample into a fixed-point
    LCD_OutString(" cm"); //Output string to display ' cm'
    //P1OUT ^= 0x03;    //Toggle a heart beat LED1 each time...
  } //ADC is sampled
}
