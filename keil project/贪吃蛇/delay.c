#include <delay.h>

void delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;

	while(xms--){
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}
