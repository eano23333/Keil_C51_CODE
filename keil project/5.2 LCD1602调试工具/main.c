#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int Result=3+1;

void main()
{
	
	while(1)
	{
		LCD_Init();
		if(Result--)
		{
			LCD_ShowString(1,1,"Result=     s");
			LCD_ShowNum(1,8,Result,5);
			Delay1ms(1000);
			
		}
		else
		{
			LCD_Init();
			LCD_ShowString(1,1,"waiting......");
			Delay1ms(1000);
			LCD_Init();
			LCD_ShowString(1,1,"BOOM!!!");
			LCD_ShowString(2,1,"LOSER");
			Delay1ms(1000);
		}
	
	}
}