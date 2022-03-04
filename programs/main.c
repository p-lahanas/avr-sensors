#include "main.h"
#include "cli_lib.h"
#include "sys_clock.h"
#include "HCSR04_lib.h"

#include <util/delay.h>


int main() {
    
    USART_Init(UBRR_9600_BAUD);

    sys_time_init();
    HCSR04_Init();
    unsigned long dist;
    unsigned char buff[20];
    unsigned int len;

    while (1) {

        dist = HCSR04_GetDist();
        len = itos(dist, buff, 20);
        USART_TransmitStrPolling(buff, len);
        USART_TransmitPolling('\n');
        _delay_ms(100);
    }
    
    return 0;
}
