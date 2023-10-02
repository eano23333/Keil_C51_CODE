#include <REGX52.H>

/*T0计时器初始化*/

/**
  * @brief  定时器0初始化 1毫秒@11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init()	//1毫秒@11.0592MHz
{
//	TMOD = 0x01;	//16位T0定时器
	TMOD &= 0xF0;	//高四位不变,低四位清零
	TMOD |= 0x01;	//高四位不变，最低位置1
	
	/*TCON*/
	TF0 = 0;	//TF0清零
	TR0 = 1;	//允许T0开始计数
	
	/*周期设定为1ms需要设定初始值*/
	/*该16位T0计时器由TH0(高位)和TL0(低位)两个8位寄存器构成，需要高低位分别赋值*/
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值

	ET0 = 1;//允许T0中断
	EA = 1;//CPU开放中断
	PT0 = 0;//设定为最低优先级
}


/*定时器中断函数声明*/
/*使用时：需要复制到main.c文件中*/
//void Timer0_Routine()	interrupt 1
//{
//	static unsigned int T0_count;//静态声明 只能在本函数内使用，且函数结束后不清零
//	TL0 = 0x66;	
//	TH0 = 0xFC;
//	T0_count++;
//	if(T0_count >= 1000)
//	{
//		T0_count = 0;
//	}
//}