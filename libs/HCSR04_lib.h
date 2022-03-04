#ifndef HCSR04_LIB_H
#define HCSR04_LIB_H


// PINOUT CONFIGURATION a
#define TRIG    7
#define ECHO    6


void HCSR04_Init(void);
unsigned long HCSR04_GetDist(void);


#endif
