#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 20e6
__CONFIG(0X3F3A);

int count;
	
void main()
{    
	TRISB=0X00;
	PORTB=0X00;
	TMR2=0X00;
	PR2=255;
	T2CON=0X07;
	TMR2IF=0;

	while(1)
	{
		while(TMR2IF==0);
		TMR2IF=0;
		count++;
		if(count==612)
		{
			RB0=~RB0;
			count=0;
		}
	}
}