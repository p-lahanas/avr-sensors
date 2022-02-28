#include "main.h"
#include "cli_lib.h"

#include <util/delay.h>


int main() {
    
    USART_Init(MYUBRR);

    char hello[14] = "Hello World!\n\r";

    while (1) {

        int i = 0;

        while (i < 14) {
            USART_Transmit(hello[i]);
            i++;
        }

        _delay_ms(100);

   }
    
    return 0;
}
