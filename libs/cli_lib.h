#ifndef CLI_LIB_H
#define CLI_LIB_H

#define MYUBRR 103

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);

#endif
