#include "cli_lib.h"

#include <avr/io.h>

void USART_Init(unsigned int ubrr) {

    /* Set the baud rate */
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;

    /* Set frame format: 8data, 1stop bit */ 
    UCSR0C = 0x06;

    /* Enable transmitter */    
    UCSR0B = (1 << TXEN0);

}

void USART_TransmitPolling(unsigned char data) {
    
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}


void USART_TransmitStrPolling(unsigned char *str, unsigned int strLen) {

    for (unsigned int i = 0; i < strLen; i++) {
        
        USART_TransmitPolling(str[i]);
    }

    /* If string is not null terminated, send the null terminator */
    if (str[strLen - 1] != '\0') {
        USART_TransmitPolling('\0');
    }
}