#ifndef _HC595_
#define _HC595_
sbit RCK=P3^5; //595����
sbit SCK=P3^6; //595��λ
sbit SER=P3^4; //595д������


void HC595_write(unsigned char byte); //д������
void LCD_Show(unsigned Column,unsigned char Data); //�ڵ�������д�����ݣ�Data���ݣ�ColumnΪ��
void LCD_INIT();
void Code_tran(int x,int y);		//����x��y

#endif