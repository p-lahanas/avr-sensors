#include "HCSR04_lib.h"
#include "sys_clock.h"
#include "cli_lib.h"

#include <avr/io.h>
#include <util/delay.h>

#define SPEED_OF_SOUND 34UL // cm/ms

void HCSR04_Init(void) {
    
    // Set PD7 as output (trig))
    DDRD |= (1 << DDD7);
    // Set PD6 as input (echo) and turn off pull-up)
    DDRD &= ~(1 << DDD6);
    PORTD &= ~(1 << ECHO);

}

/* TODO: Implement this with interrupts so no busy waiting */
unsigned long HCSR04_GetDist(void) {

    unsigned long startTime, endTime, elapsed, distance;
    
    // Send 10us pulse to TRIG 
    PORTD |= (1 << TRIG);
    _delay_us(10);
    PORTD &= ~(1 << TRIG);
    
    // Wait for echo rising edge
    while (!(PIND & (1 << ECHO)));

    // Start timer
    startTime = sys_time_elapsed();

    // Wait for echo falling edge
    while ((PIND & (1 << ECHO)));
    endTime = sys_time_elapsed(); 
    
    // End time
    elapsed = endTime - startTime;

  
    distance = (SPEED_OF_SOUND * elapsed) / 2;

    return distance;
}
