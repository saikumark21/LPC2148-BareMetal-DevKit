#ifndef UART_H
#define UART_H

// Pin definitions
#define TXD_PIN 0 //p0.0
#define RXD_PIN 1 //p0.1

// Baud rate timing (for 9600 bps = ~104us per bit)
#define BIT_TIME_US 104
#define HALF_BIT_TIME_US (BIT_TIME_US / 2)

//Function definitions
void uart_init();
void uart_tx_char(char );
void uart_tx_string(const char *);
char uart_rx_char(void);


#endif