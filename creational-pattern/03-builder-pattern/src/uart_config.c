#include <stdio.h>
#include "uart_config.h"

void uart_builder_init(UartBuilder* builder) {
    builder->config.baud_rate = 9600;
    builder->config.data_bits = 8;
    builder->config.stop_bits = 1;
    builder->config.parity = UART_PARITY_NONE;
}

UartBuilder* uart_builder_set_baud_rate(UartBuilder* builder, int baud) {
    builder->config.baud_rate = baud;
    return builder;
}

UartBuilder* uart_builder_set_data_bits(UartBuilder* builder, int bits) {
    builder->config.data_bits = bits;
    return builder;
}

UartBuilder* uart_builder_set_stop_bits(UartBuilder* builder, int bits) {
    builder->config.stop_bits = bits;
    return builder;
}

UartBuilder* uart_builder_set_parity(UartBuilder* builder, UartParity parity) {
    builder->config.parity = parity;
    return builder;
}

UartConfig uart_builder_build(UartBuilder* builder) {
    return builder->config;
}

void uart_print_config(const UartConfig* config) {
    printf("UART Config:\n");
    printf("  Baud rate: %d\n", config->baud_rate);
    printf("  Data bits: %d\n", config->data_bits);
    printf("  Stop bits: %d\n", config->stop_bits);
    printf("  Parity: %s\n",
           config->parity == UART_PARITY_NONE ? "None" :
           config->parity == UART_PARITY_EVEN ? "Even" : "Odd");
}
