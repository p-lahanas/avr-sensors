#include "main.h"
#include "cli_lib.h"

#include <util/delay.h>


int main() {
    
    USART_Init(UBRR_9600_BAUD);

    unsigned char hello[14] = "Hello World!\n\r";

    while (1) {

        USART_TransmitStrPolling(hello, 14);
        _delay_ms(100);

    }
    
    return 0;
}
