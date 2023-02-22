# Embedded_Projects
Embedded projects in c


# FSM traffic lights 

Code was completed during fall 2022 
code was skeleton code and needed to be
completed. 

![IMG_8507](https://user-images.githubusercontent.com/31228460/214196102-c94d1ddc-b9cd-44d2-8565-9186ade348f1.jpg)

# DAC
Objective of this lab is to take three digital input notes from a piano key and convert them into a 4-bit digital output

Using Code Composer Studio & MSP432 microcontroller, left out systic file since was not my code.
```c
void main(void) {
  char piano_note;
  Piano_Init(); //Initializing Piano_Init
  Sound_Init(); //Initializing Sound_Init
  while (1) {
    piano_note = Piano_In();
 ```
