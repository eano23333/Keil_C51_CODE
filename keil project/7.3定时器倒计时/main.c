#include <REGX52.H>
#include "Timer0.h"
#include <INTRINS.H>
#include "LCD1602.h"

int Sec,Min,Hour=2334;


void main()
{
	LCD_Init();
	Timer0_Init();
	
	
	LCD_ShowString(1,1,"\"    :  :  \"");
	while(1)
	{
		LCD_ShowNum(1,2,Hour,4);
		LCD_ShowNum(1,7,Min,2);
		LCD_ShowNum(1,10,Sec,2);
	}
}


/*定时器中断函数声明*/
/*使用时：需要复制到main.c文件中*/
void Timer0_Routine()	interrupt 1
{
	static unsigned int T0_count;//静态声明 只能在本函数内使用，且函数结束后不清零
	TL0 = 0x66;	
	TH0 = 0xFC;
	T0_count++;

/*"倒计时的尽头会是什么?"————汪淼*/
	if(T0_count >= 1000)
	{
		T0_count = 0;
		Sec--;
		if(Sec<0)
		{
			Sec=59;
			Min--;
			if(Min<0)
			{	
				Min=59;
				Hour--;
				if(Hour<0)
					Hour=0;
				
			}
			
		}
			
	}
}