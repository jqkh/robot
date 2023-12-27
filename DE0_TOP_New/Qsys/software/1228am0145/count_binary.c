#include <stdio.h>
#include <system.h> /* ╰参夹非ㄧボ畐 */
#include <io.h>     /* ╰参I/Oㄧボ畐*/
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "star.c"
#include "pio.h" /* pioㄧ计 */
#include "pio.c" /* pioㄧ计 */
#include "hex.c"
void location1(void);

unsigned int tmp;
sPIO_s sPIO; /* PIO 挡篶跑计*/
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
	printf("Game start");
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
			   location1();
			   break;
		  }
	}
	printf("you win");
return 0;
}
void location1(void)
{
	int x,y,a,b,c,d,i,f,sw,bt2,dir,led;
	int maze[11][11];
	PIOISRInitial(&sPIO); /* ﹍てISRㄧ计 */
	tmp = sPIO.uiPressCnt;
    srand(time);
	f= (rand()%2);
	printf("f=%d\n",f);
	x=5,y=5;
//	switch(f){
//	case 0:
//		maze=&maze1;
//		break;
//	case 1:
//		maze=&maze2;
//		break;
//	case 2:
//		maze=&maze3;
//		break;
//	default:
//		printf("error");
//		break;
//	}

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
		if(maze1[y][x]==2)
			{
			for(i=0;i<2;i++)
				{
				led = led << 1;
				if(led > 0x100)
					{
						  led = 0x01;
					}
				IOWR(LED_BASE, 0, led);
				usleep(11000);
				}
			printf("break");
			break;
			}else if(maze1[y--][x]!=1){
			a=0x0;
		}else{
			a=0x40;
		}
		if(maze1[y++][x]!=1){
					b=0x0;
				}else{
					b=0x08;
				}
		if(maze1[y][x--]!=1){
					c=0x0;
				}else{
					c=0x30;
				}
		if(maze1[y][x--]!=1){
					d=0x0;
				}else{
					d=0x06;
				}
		dir=a+b+c+d;
		IOWR(HEX3_BASE,0,~dir);
			sw=IORD(SW_BASE,0);
			switch(sw)
			{
				case 0x1:
					if(maze1[y--][x]!=1)
					{
						y--;
					}
					break;
				case 0X02:
					if(maze1[y++][x]!=1)
					{
						y++;
					}
					break;
				case 0X04:
					if(maze1[y][x++]!=1)
					{
						x++;
					}
					break;
				case 0X08:
					if(maze1[y][x--]!=1)
					{
						x--;
					}
					break;
				default:
					printf("ぃǐ弊稼");
					break;
				}

			printf("%d\n",x);
			printf("%d\n",sw);
			IOWR(HEX2_BASE,0,he0(x));
			IOWR(HEX0_BASE,0,he0(y));
			IOWR(HEX1_BASE,0,~0x40);
			}
			usleep(100000);
		}
	printf("back");
}

