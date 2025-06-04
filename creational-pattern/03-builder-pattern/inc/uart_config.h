#ifndef UART_CONFIG_H
#define UART_CONFIG_H

typedef enum {
    UART_PARITY_NONE,
    UART_PARITY_EVEN,
    UART_PARITY_ODD
} UartParity;

typedef struct {
    int baud_rate;
    int data_bits;
    int stop_bits;
    UartParity parity;
} UartConfig;

typedef struct {
    UartConfig config;
} UartBuilder;

void uart_builder_init(UartBuilder* builder);
UartBuilder* uart_builder_set_baud_rate(UartBuilder* builder, int baud);
UartBuilder* uart_builder_set_data_bits(UartBuilder* builder, int bits);
UartBuilder* uart_builder_set_stop_bits(UartBuilder* builder, int bits);
UartBuilder* uart_builder_set_parity(UartBuilder* builder, UartParity parity);
UartConfig uart_builder_build(UartBuilder* builder);

void uart_print_config(const UartConfig* config);

#endif
