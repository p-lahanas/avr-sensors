#include "HCSR04_lib.h"

#include "avr/io.h"
#include "util/delay.h"

void HCSR04_Init(void) {
    
    // Set PD7 as output (trig))
    DDRD |= (1 << DDD7);
    // Set PD6 as input (echo))
    DDRD &= ~(1 << DDD6);

    // Set echo pin as input PD6

    // Set Trig pin as output PD7
}

/* TODO: Implement this with interrupts so no busy waiting */
int HCSR04_GetDist(void) {

    // Send 10us pulse to TRIG 
    PORTD |= (1 << TRIG);
    _delay_us(10)    
    PORTD &= ~(1 << TRIG);
    
    // Wait for echo rising edge
    while (!(PORTD & (1 << ECHO)));

    // Start timer

    // Wait for echo falling edge
    while ((PORTD & (1 << ECHO)));
    
    // End time
    

    // Calculate distance based on time


}
