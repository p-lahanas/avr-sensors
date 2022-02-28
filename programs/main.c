#include "main.h"
#include "cli_lib.h"

#include <util/delay.h>


int main() {
    
    USART_Init(UBRR_9600_BAUD);

    char hello[14] = "Hello World!\n\r";

    while (1) {

        int i = 0;

        while (i < 14) {
            USART_TransmitPolling(hello[i]);
            i++;
        }

        _delay_ms(100);

   }
    
    return 0;
}
