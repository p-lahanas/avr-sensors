#ifndef CLI_LIB_H
#define CLI_LIB_H

// +--------------------------------------------------------------------+//
// | USART BOARD RATE REGISTER VALUES for 16Mhz crystal (Arduino Uno r3)|//
// +--------------------------------------------------------------------+//
#define UBRR_2400_BAUD      416
#define UBRR_4800_BAUD      207
#define UBRR_9600_BAUD      103
#define UBRR_14400_BAUD     68
#define UBRR_192000_BAUD    51


void USART_Init(unsigned int ubrr);
void USART_TransmitPolling(unsigned char data);

// String handling wrappers
void USART_TransmitStrPolling(unsigned char *str, unsigned int strLen);


#endif
