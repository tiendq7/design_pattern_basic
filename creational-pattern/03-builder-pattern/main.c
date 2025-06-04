#include <stdio.h>
#include "uart_config.h"

int main(void) {
    UartBuilder builder;
    uart_builder_init(&builder);

    uart_builder_set_baud_rate(&builder, 115200);
    uart_builder_set_data_bits(&builder, 8);
    uart_builder_set_stop_bits(&builder, 1);
    uart_builder_set_parity(&builder, UART_PARITY_NONE);

    UartConfig config = uart_builder_build(&builder);

    uart_print_config(&config);
    return 0;
}
