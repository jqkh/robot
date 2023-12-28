#include <stdio.h>
#include <system.h>
#include <io.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "star.c"
#include "pio.h"
#include "pio.c"
#include "hex.c"
void location1(int time);

unsigned int tmp;
sPIO_s sPIO;
int maze1[11][11]={
		{1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,2,0,1,1,1,1,1},
		{1,0,1,1,1,0,0,0,0,1,1},
		{1,0,0,0,1,0,0,1,0,0,1},
		{1,1,1,0,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,0,1,0,1,0,1},
		{1,0,0,1,1,1,0,0,0,0,1},
		{1,1,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1}
};
int maze2 [11][11]={
		{1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,0,0,0,0,0,1,1},
		{1,1,1,0,1,1,1,1,0,1,1},
		{1,1,1,1,1,0,1,1,0,1,1},
		{1,0,0,0,1,0,1,1,0,1,1},
		{1,0,1,0,1,1,1,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,1},
		{1,0,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,2,1},
		{1,1,1,1,1,1,1,1,1,1,1}
};
int maze3 [11][11]={
		{1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,1,1,1,1,1,0,1},
		{1,0,1,0,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,1,1,0,1},
		{1,0,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,1,1},
		{1,0,0,0,1,0,0,0,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1}
};
int main(){

	int i=0,bt2=0,time=0;
	printf("遊戲開始\n");
	while(1){
		if(i>4){
			i=0;
		}
		if(time>200){
				i++;
				time=0;
		}
		star_display(i);
		usleep(1000);
		time++;
		bt2=IORD(BUTTON2_BASE,0);
		if(bt2==0)
		  {
			   printf("bt2 %d",bt2);
			   IOWR(HEX0_BASE,0,~0x0);
			   IOWR(HEX1_BASE,0,~0x0);
			   IOWR(HEX2_BASE,0,~0x0);
			   IOWR(HEX3_BASE,0,~0x0);
			   while(IORD(BUTTON2_BASE,0)==bt2);
			   printf("遊戲規則:\n開關總共有四個(sw3:0)從大到小分別控制人物上下左右當撥好，指定的開關時按下button2即可使人物向指定方向前進\n");
			   printf("注意事項:");
			   location1(time);
			   break;
		  }
	}
	printf("you win");
return 0;
}
void location1(int time)
{
	int x,y,a,b,c,d,i,f,sw,bt2,dir=0,led=1,control=0,test=0;
	int maze[11][11];
	PIOISRInitial(&sPIO); /* 初始化ISR函數 */
	tmp = sPIO.uiPressCnt;
	srand(time);
	//f= (rand()%3);
	f=0;
	printf("f=%d\n",f);
	x=5,y=5;
	switch(f){
	case 0:
		maze[11][11]=maze1[11][11];
		break;
	case 1:
		maze[11][11]=maze2[11][11];
		break;
	case 2:
		maze[11][11]=maze3[11][11];
		break;
	default:
		printf("error");
		break;
	}

	while(1){
		bt2=IORD(BUTTON2_BASE,0);
		if(tmp != sPIO.uiPressCnt){
			  printf("pause game \n");
			  printf("%d\n",tmp);
			  tmp = sPIO.uiPressCnt;
			}
		if(bt2==0)
		{
			while(IORD(BUTTON2_BASE,0)==bt2);
			sw=IORD(SW_BASE,0);
			switch(sw)
			{
				case 0X08:
					if(maze[y-1][x]<1)
					{
						test=maze[y-1][x];
						printf("test0x8=%d\n",test);
						y--;
					}
					break;
				case 0X04:
					if(maze[y+1][x]<1)
					{
						y++;
					}
					break;
				case 0X02:
					test=maze[y][x-1];
					printf("test0x2=%d\n",test);
					if(maze[y][x-1]!=1)
					{
						x--;
					}
					break;
				case 0x1:
						test=maze[y][x+1];
						printf("test=%d\n",test);
					if(maze[y][x+1]!=0)
					{
						x++;
					}
					break;
			    case 0x00:
			    	printf("給我動喔!!!!白癡/n");
			    	break;
				default:
					printf("不能走斜的歐");
					break;
				}

			if(maze1[y][x]==2)
				{
				for(i=0;i<=3;)
					{

					if(control==0)
						{
						led = led << 1;
						}
					if(control==1)
						{
						led = led >> 1;;
						}
					if(led >= 0x200){
						control=1;

					}
					if(led <= 0x01){
						control=0;
						i++;
					}
					IOWR(LED_BASE, 0, led);
					usleep(20000);
					}

				printf("break");
				break;
				}

			if(maze1[y-1][x]!=1){
						a=0x0;
							}else{
								a=0x01;
							}
					if(maze1[y+1][x]!=1){
								b=0x0;
							}else{
								b=0x08;
							}
					if(maze1[y][x+1]!=1){
								c=0x0;
							}else{
								c=0x06;
							}
					if(maze1[y][x-1]!=1){
								d=0x0;
							}else{
								d=0x30;
							}
					dir=a+b+c+d+0x40;
					printf("dir=%x,a=%x,b=%x,c=%x,d=%x",dir,a,b,c,d);
					IOWR(HEX3_BASE,0,~dir);

			printf("[x]%d\n",x);
			printf("[y]%d\n",y);
			printf("sw=%d\n",sw);
			IOWR(HEX2_BASE,0,he0(x));
			IOWR(HEX0_BASE,0,he0(y));
			IOWR(HEX1_BASE,0,~0x40);
			}
		usleep(10000);
		}
	printf("back");
}
