#include <REGX52.H>
#include <intrins.h>

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

void main()
{
	unsigned char LEDnum = 0;//0000 0000
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
//			//默认1111 1111
//			P2++;//0000 0000溢出
//			P2=~P2;//取反1111 1111,无意义
			LEDnum++;
			P2 = ~LEDnum;
		}			
	}
}