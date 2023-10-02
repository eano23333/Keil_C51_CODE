#include <regx52.h>
#include <HC595.h>
#include <delay.h>

void HC595_write(unsigned char byte)
{
unsigned char i;
for(i=0;i<8;i++)
	{
	SER=byte&(0x80>>i);			//写入数据,从第高位（1000 0000）开始写入，for循环将8位全部写入
	SCK=1;									//移位
	SCK=0;									//移位寄存器置零
	}
RCK=1;										//锁存8位数据，for循环结束后，全部输出
RCK=0;
}

unsigned char Column;
unsigned char Data;
void LCD_Show(Column,Data)		//Column列，Data数据
{
	HC595_write(Data);
	P0=~(0x80>>Column);
	delay(1);
	P0=0xFF;
}

void LCD_INIT()
{
	RCK=0;
	SCK=0;
}

void Code_tran(int x,int y)		//将x，y解码为具体的列与数据，以便于批量写入
{
	Column=x;											//列
	switch(y)
	{
		case 0:Data=0x01;break;
		case 1:Data=0x02;break;
		case 2:Data=0x04;break;
		case 3:Data=0x08;break;
		case 4:Data=0x10;break;
		case 5:Data=0x20;break;
		case 6:Data=0x40;break;
		case 7:Data=0x80;break;			
	}
	LCD_Show(Column,Data);
}


