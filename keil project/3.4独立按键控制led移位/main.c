#include <REGX52.H>
#include <intrins.h>

void Delay(unsigned int xms);
unsigned char LEDnum;
void main()
{
	P2=~0x01;
	while(1)
	{
		if(P3_1==0)//left
		{
			Delay(20);
			while(P3_1==0)
			Delay(20);
			
			if(LEDnum==0)
				LEDnum==7;
			else
				LEDnum--;
			P2=~(0x01 << LEDnum);

		}
		
		if(P3_0==0)//right
		{
			Delay(20);
			while(P3_0==0)
			Delay(20);
			
			LEDnum++;
			if(LEDnum>=8)
				LEDnum=0;
			
			P2=~(0x01 << LEDnum);
		}
		
	}
}

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char data i, j;
	while(xms--)
	{
	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}
