#include <regx52.h>
#include <main.h>

int food_x,food_y;
int suiji[2]={3,2};
void food_produce()
{
	food_x=suiji[0]%10;if(suiji[0]%10>=8)food_x=5;
	food_y=suiji[1]%10;if(suiji[1]%10>=8)food_y=7;
	suiji[0]=suiji[0]+3;
	suiji[1]=suiji[1]+7;
}

void eat()
{
	if(head_x==food_x){
	if(head_y==food_y)length++;		//当蛇头xy轴与食物坐标重合，长度+1
	}
	food_produce();
}