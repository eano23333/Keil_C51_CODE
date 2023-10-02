#include <regx52.h>
#include <HC595.h>
#include <delay.h>

void HC595_write(unsigned char byte)
{
unsigned char i;
for(i=0;i<8;i++)
	{
	SER=byte&(0x80>>i);			//д������,�ӵڸ�λ��1000 0000����ʼд�룬forѭ����8λȫ��д��
	SCK=1;									//��λ
	SCK=0;									//��λ�Ĵ�������
	}
RCK=1;										//����8λ���ݣ�forѭ��������ȫ�����
RCK=0;
}

unsigned char Column;
unsigned char Data;
void LCD_Show(Column,Data)		//Column�У�Data����
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

void Code_tran(int x,int y)		//��x��y����Ϊ������������ݣ��Ա�������д��
{
	Column=x;											//��
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


