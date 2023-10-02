#include <REGX52.H>

void Delay100ms()		//@11.0592MHz
{
	unsigned char data i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
	 P2 = 0xFE;//1111 1110
	 Delay100ms();
	 P2 =0xFD;//1111 1101
	 Delay100ms();
	 P2 =0xFB;//1111 1011
	 Delay100ms();
	 P2 =0xF7;//1111 0111
	 Delay100ms();
	 P2 =0xEF;//1110 1111
	 Delay100ms();
	 P2 =0xDF;//1101 1111
	 Delay100ms();
	 P2 =0xBF;//1011 1111
	 Delay100ms();
	 P2 =0x7F;//0111 1111
	 Delay100ms();
	}
	
}
