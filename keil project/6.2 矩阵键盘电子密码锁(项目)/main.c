#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,count;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{
			/*输入密码区 s1~s10 */
			if(KeyNum <= 10)//如果s1~s10按键按下，输入密码
				{
					if(count < 4)
					{
						Password *= 10;				//密码左移一位
						Password += KeyNum % 10;					//获取一位密码
						count++;		//计次加一
					}
					LCD_ShowNum(2,1,Password,4);//更新显示

				}
				
			/*确认按键 s11 */
			if(KeyNum == 11)//如果s11按键按下，确认密码
			{
				if(Password == 3731)
				{
					LCD_ShowString(1,11,"YES!!!");
					LCD_ShowNum(2,1,Password,4);//更新显示
					Password = 0;		//密码清零
					count = 0;			//计次清零
				}
				else
				{
					LCD_ShowString(1,11,"error ");
					Delay1ms(1000);
					LCD_ShowString(1,11,"try...");
					Password = 0;		//密码清零
					count = 0;			//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示
				}
			}
				
			/*取消键 s16 */
				if(KeyNum == 16)//如果s16按键按下，清除输入密码
				{
					Password = 0;		//密码清零
					count = 0;			//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示
				}
				
			/*退格键 s12*/
				if(KeyNum == 12)//如果s12按键按下，退回一位输入密码
				{
					Password /= 10;		//密码退位
					count--;			//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示
				}
					
		}
		
	}
	
}
