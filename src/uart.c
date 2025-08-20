#include"lpc214x.h"
#include"uart.h"
#include"defines.h"
#include"delay.h"

void uart_init() 
{
	SETBIT(IOSET0,TXD_PIN);
	SETBIT(IODIR0,TXD_PIN);
	CLRBIT(IODIR0,RXD_PIN);
}

void uart_tx_char(char c) 
{
    unsigned char i;

	SETBIT(IOCLR0,TXD_PIN);
	delay_us(BIT_TIME_US);

	for(i = 0 ;i < 8; i++)
	{
		WRITEBIT(IOPIN0,TXD_PIN,(c>>i)&1);
		delay_us(BIT_TIME_US);
	}
	
	SETBIT(IOSET0,TXD_PIN);
	delay_us(BIT_TIME_US);
}

void uart_tx_string(const char *str)
{
    while (*str != '\0') 
    {
        uart_tx_char(*str++);
    }
}

char uart_rx_char(void) 
{
    char i,rDat=0; 
	while(READBIT(IOPIN0,RXD_PIN));
	delay_us(HALF_BIT_TIME_US);
	
	for(i = 0 ;i < 8; i++)
	{
		delay_us(BIT_TIME_US);
		if(READBIT(IOPIN0,RXD_PIN) == 1)
			rDat |= (1<<i);		
	}
	delay_us(BIT_TIME_US);
	
	while(READBIT(IOPIN0,RXD_PIN) == 0);

	return rDat;
}


