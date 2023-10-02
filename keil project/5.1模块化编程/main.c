#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
void main()
{
	while(1)
	{
		Nixie(1,3);
		Nixie(2,4);
		Nixie(3,3);
		Nixie(4,7);
		Nixie(5,17);
		Nixie(6,17);
		Nixie(7,2);	
		Nixie(8,11);	
	}
}