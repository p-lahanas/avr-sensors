#include "HC_SR04_lib.h"

#include "avr/io.h"

void HCSR04_Init(void) {
    
    // Set PD7 as output (trig))
    DDRD |= (1 << DDD7);
    // Set PD6 as input (echo))
    DDRD &= ~(1 << DDD6);

    //TODO remove this just to test at this stage
    PORTD |= (1 << PD7);
    // Set echo pin as input PD6

    // Set Trig pin as output PD7
}
