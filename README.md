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

# LowPassFilter_matlab
Low pass filter created in matlab, ran in code composer studio in c language


<img width="656" alt="Screenshot 2023-01-20 at 8 52 01 PM" src="https://user-images.githubusercontent.com/31228460/213844076-14f5232e-3c33-467f-b162-d6c46fa99c7e.png">
<img width="584" alt="Screenshot 2023-01-20 at 8 52 18 PM" src="https://user-images.githubusercontent.com/31228460/213844077-d4f0ef28-422d-4092-9926-9f8ec144bec5.png">
<img width="584" alt="Screenshot 2023-01-20 at 8 52 27 PM" src="https://user-images.githubusercontent.com/31228460/213844078-aef55cc3-875a-408b-b26f-478a4072e308.png">
