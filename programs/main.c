#include "main.h"
#include "cli_lib.h"
#include "sys_clock.h"

#include <util/delay.h>


int main() {
    
    USART_Init(UBRR_9600_BAUD);

    unsigned char hello[14] = "Hello World!\n\r";
    sys_time_init();

    unsigned long time;

    while (1) {
        time = sys_time_elapsed();
        USART_TransmitPolling(time + 'a');
        _delay_ms(100);
    }
    
    return 0;
}
