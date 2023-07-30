# Embedded Projects

>[!IMPORTANT]\
>Embedded C projects completed using [Code Composer Sudio](https://www.ti.com/tool/CCSTUDIO)

---

#### FSM traffic lights 

<img width="591" alt="LCD" src="https://github.com/jge162/450-EmbeddedProjects/assets/31228460/10c9b9b8-688b-41fa-bfdf-d1a9cbefc6a0">

---

### ADC 

<img width="591" alt="LCD" src="https://github.com/jge162/450-EmbeddedProjects/assets/31228460/9f0a2bf4-6e21-4964-93be-4f508d48133f">

---

### DAC

<img width="591" alt="LCD" src="https://github.com/jge162/450-EmbeddedProjects/assets/31228460/cbc5f85d-f038-4146-b3fb-88a805a3f201">

---

>[!NOTE]\
>Objective of this lab is to take three digital input notes from a piano key and convert them into a 4-bit digital output

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

>[!NOTE]\
>Low pass filter created in matlab, ran in code composer studio in c language

<img width="656" alt="Screenshot 2023-01-20 at 8 52 01 PM" src="https://user-images.githubusercontent.com/31228460/213844076-14f5232e-3c33-467f-b162-d6c46fa99c7e.png">
<img width="584" alt="Screenshot 2023-01-20 at 8 52 18 PM" src="https://user-images.githubusercontent.com/31228460/213844077-d4f0ef28-422d-4092-9926-9f8ec144bec5.png">
<img width="584" alt="Screenshot 2023-01-20 at 8 52 27 PM" src="https://user-images.githubusercontent.com/31228460/213844078-aef55cc3-875a-408b-b26f-478a4072e308.png">
