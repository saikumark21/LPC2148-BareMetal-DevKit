void delay() //general delay
{
	unsigned int i,j;
	for(i=0;i<2000;i++)
		for(j=0;j<2000;j++);
}

void delay_us(unsigned int dlyUs)
{
	dlyUs*=12;//@CPU Clock 60MHZ
	while(dlyUs--);
}

void delay_ms(unsigned int dlyMs)
{
	dlyMs*=12000;//@CPU Clock 60MHZ
	while(dlyMs--);
}

void delay_s(unsigned int dlyS)
{
	dlyS*=12000000;//@CPU Clock 60MHZ
	while(dlyS--);
}