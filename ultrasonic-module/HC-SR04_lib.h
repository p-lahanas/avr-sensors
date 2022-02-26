#ifndef HC_SR04_LIB_H
#define HC_SR04_LIB_H


// PINOUT CONFIGURATION a
#define TRIG 7
#define ECHO 6


void hc_sr04_init(void);
int hc_sr04_calc_dist(void);


#endif
