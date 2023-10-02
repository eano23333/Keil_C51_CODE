#include <regx52.h>
#include <HC595.h>
#include <KeyNum.h>
#include <delay.h>



unsigned int mode=12;
unsigned int THL=65535-1000; //1000us=1ms
void Timer0_INIT()		//��ʱ��0��ʼ����������ͷ�ĸ��¡�
{
	TMOD=0x01;
	TR0=1;
	ET0=1;
	TH0=THL/256;
	TL0=THL%256;
	TF0=0;
	PT0=0;
	EA=1;
}

int head_x=0,head_y=0;  //��ʼ����ͷλ��
int length=1;
int body_x[14]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},body_y[14]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};		//��body��xyȫ����ֵΪ-1����ֹ����ʾ�ڵ���LCD��ֵ����X��YΪ-1ʱ����ʾ��
int food_x,food_y;
int suiji[2]={3,7};

void food_produce()		//����ʳ�����
{
	food_x=suiji[0]%10;if(suiji[0]%10>=8)food_x=5;
	food_y=suiji[1]%10;if(suiji[1]%10>=8)food_y=7;
	suiji[0]=suiji[0]+3;
	suiji[1]=suiji[1]+7;
}

void eat()			//����Ե�ʳ��
{
	if(head_x==food_x){
	if(head_y==food_y){length++;food_x=8;food_y=8;food_produce();}		//����ͷxy����ʳ�������غϣ�����+1
	}
}


void body_init()		//�����ʼ��
{
int x;
for(x=0;x<15;x++)
{
body_x[x]=-1;body_y[x]=-1;}
}


int dead;
void death()			//forѭ�������ͷhead������body�Ƿ��غϣ�һ���غ�������body��length��ʼ��
{									//21.11.5����BUG����ʱ���иպø�body_[0]��ֵʱǡ��ִ��death���ᵼ��Ī������death
	for(dead=0;dead<12;dead++)			//�����������deathд����ʱ����
	{
	if(head_x==body_x[dead]){if(head_y==body_y[dead]){length=1;body_init();}}
	}
}


	int i;
	unsigned char KEYNUM;
void main()
{
	LCD_INIT();
	Timer0_INIT();
	food_produce();
	while(1){
		if(mode!=10){if(KEYNUM==10)mode=10;}		//�������ɨ�裬ʹ�ñ���mode�����ߵ���������
		if(mode!=12){if(KEYNUM==12)mode=12;}
		if(mode!=15){if(KEYNUM==15)mode=15;}
		if(mode!=7){if(KEYNUM==7)mode=7;}
		Code_tran(head_x,head_y);
		Code_tran(food_x,food_y);
		eat();										//�ж��Ƿ��ʳ��
		switch(length){						//���������ȣ�ȥ��ʾLCD����
			case 1:Code_tran(body_x[0],body_y[0]);break;
			case 2:Code_tran(body_x[0],body_y[0]);
						 Code_tran(body_x[1],body_y[1]);break;
			case 3:Code_tran(body_x[0],body_y[0]);
						 Code_tran(body_x[1],body_y[1]);
						 Code_tran(body_x[2],body_y[2]);break;
			case 4:for(i=0;i<5;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 5:for(i=0;i<6;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 6:for(i=0;i<7;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 7:for(i=0;i<8;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 8:for(i=0;i<9;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 9:for(i=0;i<10;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 10:for(i=0;i<11;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 11:for(i=0;i<12;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 12:for(i=0;i<13;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 13:for(i=0;i<14;i++){Code_tran(body_x[i],body_y[i]);}break;
			case 14:for(i=0;i<15;i++){Code_tran(body_x[i],body_y[i]);}break;
	  }
	 }
	}




void snake_head()
{
	switch(mode)
	{
		case 10:head_x--;if(head_x<=-1)head_x=7;break;
		case 12:head_x++;if(head_x>=8)head_x=0;break;
		case 7:head_y++;if(head_y>=8)head_y=0;break;
		case 15:head_y--;if(head_y<=-1)head_y=7;break;
		default:break;
	}
}



int o,p;							//o���ڼ���ѭ����p=o+1����body_xy[p]=body_xy[o]
void snake_body()			//�������ԭ������һλ����д����һλ�������һλ����ͷ��ֵ��
{											//���Ըĳ�forѭ����䣬191602020107ZG��2021.11.4
	switch(length){
		case 1:body_x[0]=head_x;body_y[0]=head_y;break;
		case 2:body_x[1]=body_x[0];body_y[1]=body_y[0];		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 3:for(o=2;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 4:for(o=3;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 5:for(o=4;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 6:for(o=5;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;	
		case 7:for(o=6;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 8:for(o=7;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
    case 9:for(o=8;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 10:for(o=9;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 11:for(o=10;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 12:for(o=11;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 13:for(o=12;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		case 14:for(o=13;o>-1;o--){p=o+1;body_x[p]=body_x[o];body_y[p]=body_y[o];}		
					 body_x[0]=head_x;body_y[0]=head_y;break;
		default: length=1;
	}
}






unsigned int clock=0,clock2=0;
void Timer0() interrupt 1
{
	clock++;
	clock2++;
	TH0=THL/256;
	TL0=THL%256;
	if(clock2>=150){KEYNUM=KeyNumGet();clock2=0;}		//�趨15ms��ȡһ�μ�ֵ����ֹLCD�������Ƶ��
	if(clock>=400)			//0.4s����һ��head
	{
	clock=0;
	P2_0=!P2_0;
	snake_body();		//��������
	snake_head();		//����ͷ��
	death();				//�ж��Ƿ�ͷ���������غϣ��غϼ�ִ��death
	}
}