Main.c
#include "msp432p401r.h"
#include "Fir_cof.h"
#include <stdint.h>
//****************************************
// Sine values f=375kHz @ fs=3MHZ
//****************************************
short sine_table_ind = 0;
short sine_table_gain = 1;
//****************************************
// Sine tables
//****************************************
short sine_table_375[8] = { 0, 707, 1000, 707, 0, -707, -1000, -707 }; //375k
mhz sample
short sine_table_1[3] = { 0, 866, -866 }; //1 mhz sample
short sine_table_375_ind = 0;
short sine_table_1_ind = 0;
short sine_table_1_gain = 2;
//****************************************
// FIR Filter
//****************************************
int yn; 
multiply adds
short dly[N]; // delay samples (129 from header)
void fir_filt(short *buffer_ptr, short buffer_n)
{
 short ind1, ind2;
 for (ind1 = 0; ind1 < buffer_n; ind1++)
 {
 dly[0] = *(buffer_ptr + ind1);
 yn = 0;
 for (ind2 = 0; ind2 < N; ind2++)
 yn += (h[ind2] * dly[ind2]);
 for (ind2 = N - 1; ind2 > 0; ind2--)
 dly[ind2] = dly[ind2 - 1];
 *(buffer_ptr + ind1) = yn >> 15;
 }
}
//****************************************
// Main
6
//****************************************
void main()
{
 //I removed code from main, but look at readme for proof of completion.
 //****************************************
 // Main while(1) loop
 //****************************************
 while (1){
 fir_filt(sine_table, sample_len); 
}
