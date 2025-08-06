//program to turn on the LED, until the switch is in on state
#include"lpc214x.h"
#include"defines.h"
#include"enables_gpio.h"
#include"delay.h"

#ifdef PROG2 //PROG2
#define LED_AL 5
#define SW_AH 9
int main()
{
    //Configuring pins as input and output
    SETBIT(IO0DIR,LED_AL);
    CLRBIT(IO0DIR,SW_AH);

    //Condition to change the state of LED
    while(1)    
    {
        if(READBIT(IO0PIN,SW_AH) == 1){
            SETBIT(IO0CLR,LED_AL);      //turn ON the LED
        }
        else{
            SETBIT(IO0SET,LED_AL);      //Turn OFF the LED
        }
    }
}
#endif //PROG2


#ifdef PROG1
void delay() {
    for (volatile int i = 0; i < 500000; i++);
}

int main() {
    IO0DIR |= (1 << 10);  // Set P0.10 as output

    while (1) {
        IO0SET = (1 << 10);  // LED ON
        delay();
        IO0CLR = (1 << 10);  // LED OFF
        delay();
    }
}
#endif //PROG2

#ifdef PROG3
void SerialOut(char sData,char order,unsigned short bitrate);

#define OPIN 7
#define CHAR 'A'


int main()
{
	SETBIT(IO0DIR,OPIN);
	while(1)
	{
		SerialOut(CHAR,'m',100);
	}
}
void SerialOut(char sData,char order,unsigned short bitrate)
{
	unsigned char i;
	if(order=='m')
	{
		for(i=7;i>=0;i--)
		{
			WRITEBIT(IO0PIN,OPIN,((sData>>i)&1));
			delay_ms(bitrate);
		}
		return;
	}
	else
	{
		for(i=0;i<=7;i++)
		{
			WRITEBIT(IO0PIN,OPIN,((sData>>i)&1));
			delay_ms(bitrate);
		}
		return;
	}
}

#endif	//PROG3

#ifdef PROG4

#define IPINS_4No 0	//PORT 0 PIN 0 (P0.0) TO PORT 0 PIN 3 (P0.3)

#define OPINS_4No 16	//PORT 0 PIN 4 (P0.4) TO PORT 0 PIN 7 (P0.7)

int main()
{
	unsigned int t;
	//CONFIG P0.4 TO P0.7 AS OUTPUT PINS
	WRITENIBBLE(IO0DIR,OPINS_4No,0XFF);
	while(1)
	{
		t=READNIBBLE(IO0PIN,IPINS_4No);
		WRITENIBBLE(IO0PIN,OPINS_4No,t);
	}
}

#endif	//PROG4