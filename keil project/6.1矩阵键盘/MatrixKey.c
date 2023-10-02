#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  矩阵键盘 读取键码
  * @param  无
  * @retval Keynum 按下按键的键码值
			消抖：while(P1_7==0);的意思是等待 P1_7 变为非零，然后才执行下一句
  */

unsigned char MatrixKey(unsigned char Keynum)
{
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){Delay1ms(20);while(P1_7==0);Delay1ms(20);Keynum=1;}
	if(P1_6==0){Delay1ms(20);while(P1_6==0);Delay1ms(20);Keynum=5;}
	if(P1_5==0){Delay1ms(20);while(P1_5==0);Delay1ms(20);Keynum=9;}
	if(P1_4==0){Delay1ms(20);while(P1_4==0);Delay1ms(20);Keynum=13;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delay1ms(20);while(P1_7==0);Delay1ms(20);Keynum=2;}
	if(P1_6==0){Delay1ms(20);while(P1_6==0);Delay1ms(20);Keynum=6;}
	if(P1_5==0){Delay1ms(20);while(P1_5==0);Delay1ms(20);Keynum=10;}
	if(P1_4==0){Delay1ms(20);while(P1_4==0);Delay1ms(20);Keynum=14;}
	
	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delay1ms(20);while(P1_7==0);Delay1ms(20);Keynum=3;}
	if(P1_6==0){Delay1ms(20);while(P1_6==0);Delay1ms(20);Keynum=7;}
	if(P1_5==0){Delay1ms(20);while(P1_5==0);Delay1ms(20);Keynum=11;}
	if(P1_4==0){Delay1ms(20);while(P1_4==0);Delay1ms(20);Keynum=15;}
	
	P1=0xFF;
	P1_0=0;
	if(P1_7==0){Delay1ms(20);while(P1_7==0);Delay1ms(20);Keynum=4;}
	if(P1_6==0){Delay1ms(20);while(P1_6==0);Delay1ms(20);Keynum=8;}
	if(P1_5==0){Delay1ms(20);while(P1_5==0);Delay1ms(20);Keynum=12;}
	if(P1_4==0){Delay1ms(20);while(P1_4==0);Delay1ms(20);Keynum=16;}

	return Keynum;
}