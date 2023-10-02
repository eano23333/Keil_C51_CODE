#include <REGX52.H>
#include "Timer0.h"
#include "key.h"
#include <INTRINS.H>
#include "LCD1602.h"

char Sec,Min,Hour;		//可分别赋值55,59,23检验是否成功实现


void main()
{
	LCD_Init();
	Timer0_Init();
	
	
	LCD_ShowString(1,1,"CLOCK:");
	LCD_ShowString(2,1,"  :  :  ");
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
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
	if(T0_count >= 1000)	//周期1s
	{
		T0_count = 0;
				Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{	
				Min=0;
				Hour++;
				if(Hour>=24)
					Hour=0;
				
			}
			
		}
			
	}

///*"倒计时的尽头会是什么?"————汪淼*/
//	if(T0_count >= 1000)
//	{
//		T0_count = 0;
//		Sec--;
//		if(Sec<0)
//		{
//			Sec=59;
//			Min--;
//			if(Min<0)
//			{	
//				Min=59;
//				Hour--;
//				if(Hour<0)
//					Hour=0;
//				
//			}
//			
//		}
//			
//	}
}