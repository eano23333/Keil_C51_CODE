#include <REGX52.H>
#include "Timer0.h"
#include "key.h"
#include <INTRINS.H>

unsigned char KeyNum,LEDMode;

void main()
{
	P2=0xFE;
	
	Timer0_Init();
	
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2)
					LEDMode=0;
					
			}
			
		}

	}

}

/*中断函数声明*/
void Timer0_Routine()	interrupt 1
{
	static unsigned int T0_count;//静态声明 只能在本函数内使用，且函数结束后不清零
	TL0 = 0x66;	//设置定时初始值
	TH0 = 0xFC;	//设置定时初始值
	T0_count++;
	if(T0_count >= 20)
	{
		T0_count = 0;
		if(LEDMode==0)
			P2=_cror_(P2,1);	//右移
		else
			P2=_crol_(P2,1);	//左移
	}
}