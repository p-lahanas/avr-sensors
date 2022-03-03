#include "main.h"
#include "cli_lib.h"
#include "sys_clock.h"

#include <util/delay.h>


int main() {
    
    USART_Init(UBRR_9600_BAUD);

    sys_time_init();

    unsigned long time, err;
    unsigned char buff[20], buff2[20];
    unsigned int strlen;
    unsigned int strlen2;

    while (1) {
        
        time = sys_time_elapsed();
        err = sys_time_err();
        strlen = itos(time, buff, 20);
        strlen2 = itos(err, buff2, 20);
        USART_TransmitStrPolling(buff, strlen);
        USART_TransmitPolling(' ');
        USART_TransmitPolling(' ');
        USART_TransmitStrPolling(buff2, strlen2);
        USART_TransmitPolling('\n');
        
        _delay_ms(100);
    }
    
    return 0;
}
