#include <stdio.h>
#include <system.h> /* 系統標準函示庫 */
#include <io.h>     /* 系統I/O函示庫*/
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <star.c>

void location1(int maze[11][11]);
int he0(int x);
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
	int bt,f,i;
	while(1){
		if(i>4){
			i=0;
		}
		star_display(i);
		i++;
		if(IORD(BUTTON2_BASE,0)==0)
		  {
			   break;
		  }
	}
	 srand(2);
	f= rand();
	bt=IORD(BUTTON2_BASE,0);
	if(bt==1)
	{
	switch(f){
	case 0:
		location1(maze1[11][11]);
		break;
	case 1:
		location1(maze2[11][11]);
		break;
	case 2:
		location1(maze3[11][11]);
		break;
	}
	}
return 0;
}
void location1(int maze[11][11])
{
	int x,y,a,b,c,d,i,sw,bt2,dir,led;
	x=6,y=6;
	while(i==1){

			if(maze[y][x]==2)
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
				break;
				}
			if(maze[y--][x]!=1){
				a=0x0;
			}else{
				a=0x40;
			}
			if(maze[y++][x]!=1){
						b=0x0;
					}else{
						b=0x08;
					}
			if(maze[y][x--]!=1){
						c=0x0;
					}else{
						c=0x30;
					}
			if(maze[y][x--]!=1){
						d=0x0;
					}else{
						d=0x06;
					}
			dir=a+b+c+d;
			IOWR(HEX3_BASE,0,~dir);
			bt2=IORD(BUTTON2_BASE,0);
				if(bt2==1)
				{
				sw=IORD(SW_BASE,0);
				if(sw&0X01)
					{
					if(maze1[y--][x]!=1)
						{
							y--;
						}
					}
				if(sw&0X02)
					{
					if(maze1[y++][x]!=1)
						{
							y++;
						}
					}
				if(sw&0X04)
					{
					if(maze1[y][x++]!=1)
						{
							x++;
						}
					}
				if(sw&0X08)
					{
					if(maze1[y][x--]!=1)
						{
							x--;
						}
					}
				}
				IOWR(HEX0_BASE,0,he0(x));
				IOWR(HEX2_BASE,0,he0(y));
			}
}
int he0(int x)
{
	int hex=0;
	switch(x)
	{
		case 2:
			hex=0x5B;
			break;
		case 3:
			hex=0x4F;
			break;
		case 4:
			hex=0x66;
			break;
		case 5:
			hex=0x6D;
			break;
		case 6:
			hex=0x7D;
			break;
		case 7:
			hex=0x07;
			break;
		case 8:
			hex=0x7F;
			break;
		case 9:
			hex=0x6F;
			break;
		case 10:
			hex=0x77;
			break;
	}
	return ~hex;
}

