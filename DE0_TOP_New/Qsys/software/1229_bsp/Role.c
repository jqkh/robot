#include <stdio.h>
#include <system.h>

void role_map1(int tmp);
void role_map2(int tmp);
void role_map3(int tmp);
sPIO_s sPIO;

int x=5,y=5,a,b,c,d,i,sw,bt2,j,dir=0,led=1,control=0,role=0;
int up=0,down=0,lift=0,right=0;//人物上下左右判斷
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
		{1,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,0,1,1,1,1},
		{1,0,1,1,1,1,0,0,0,0,1},
		{1,0,1,1,0,0,1,0,1,0,1},
		{1,0,0,1,1,0,1,0,0,0,1},
		{1,1,0,1,0,0,1,1,1,0,1},
		{1,0,0,0,0,1,2,1,0,0,1},
		{1,0,1,1,0,1,0,0,1,0,1},
		{1,0,0,1,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1}
};
int maze3 [11][11]={
		{1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,0,0,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,1},
		{1,1,0,0,1,0,1,1,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,1},
		{1,0,1,2,1,1,0,0,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,1},
		{1,0,1,1,0,1,1,0,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1}
};
int maze4 [21][21]={
<<<<<<< HEAD
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
=======
		{﻿1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
>>>>>>> 0312b55270f3c0724b421f5397351fd51e7646c1
		{1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1},
		{1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,1,0,1,1},
		{1,0,0,0,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,0,1},
		{1,0,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1},
		{1,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1},
		{1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1},
		{1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,1},
		{1,1,0,1,1,1,0,0,1,1,0,1,0,1,1,1,0,1,0,1,1},
		{1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1},
		{1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1},
		{1,0,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,0,0,0,1,0,1},
		{1,1,1,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1,0,0,1},
		{1,1,1,0,0,1,0,1,1,0,0,0,1,1,0,0,1,1,0,1,1},
		{1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,2,1,0,0,1},
		{1,1,0,0,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1},
		{1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void role_map3(tmp){
	tmp = sPIO.uiPressCnt;
	while(1){
		bt2=IORD(BUTTON2_BASE,0);
		role=maze3[y][x];
		up=maze3[y-1][x];
		down=maze3[y+1][x];
		lift=maze3[y][x-1];
		right=maze3[y][x+1];
		if(tmp != sPIO.uiPressCnt){
			  tmp = sPIO.uiPressCnt;
			if(tmp==0){
			  printf("start game \n");
			}else if(tmp==1){
			  printf("pause game \n");
			  printf("show the map \n");
			  for(i=0;i<11;i++){
				  printf("(%d)、 ",i);
				  for(j=0;j<11;j++){
					  printf("%d ",maze3[i][j]);
				  }
				  printf("\n");
			}

			  }
			}
		if(bt2==0)
		{

			while(IORD(BUTTON2_BASE,0)==bt2);
			sw=IORD(SW_BASE,0);
			switch(sw)
			{
				case 0X08:
					if(up!=1)
					{
						y--;
					}
					break;

				case 0X04:
					if(down!=1)
					{
						y++;
					}
					break;

				case 0X02:
					if(lift!=1)
					{
						x--;
					}
					break;

				case 0x1:
					if(right!=1)
					{
						x++;
					}
					break;

			    case 0x00:
			    	printf("給我動喔!!!!白癡\n");
			    	break;
				default:
					printf("不能走斜的歐\n");
					break;
				}
			}
		if(up!=1){
			a=0x0;
			}else{
				a=0x01;
				}
		if(down!=1){
					b=0x0;
				}else{
					b=0x08;
				}
		if(right!=1){
					c=0x0;
				}else{
					c=0x06;
				}
		if(lift!=1){
					d=0x0;
				}else{
					d=0x30;
				}
		dir=a+b+c+d+0x40;
		IOWR(HEX3_BASE,0,~dir);
		IOWR(HEX2_BASE,0,he0(x));
		IOWR(HEX1_BASE,0,~0x40);
		IOWR(HEX0_BASE,0,he0(y));
//		printf("up=%d\n",up);
//		printf("down=%d\n",down);
//		printf("lift=%d\n",lift);
//		printf("right=%d\n",right);
//		printf("role=%d\n",role);
//		printf("x=%d\n",x);
//		printf("y=%d\n",y);
		if(role==2)
		{
		break;
		}
		usleep(10000);
		}
}


void role_map2(tmp){
	tmp = sPIO.uiPressCnt;
	while(1){
		bt2=IORD(BUTTON2_BASE,0);
		role=maze2[y][x];
		up=maze2[y-1][x];
		down=maze2[y+1][x];
		lift=maze2[y][x-1];
		right=maze2[y][x+1];
		if(tmp != sPIO.uiPressCnt){
			  tmp = sPIO.uiPressCnt;
			if(tmp==0){
			  printf("start game \n");
			}else if(tmp==1){
			  printf("pause game \n");
			  printf("show the map \n");
			  for(i=0;i<11;i++){
				  printf("(%d)、 ",i);
				  for(j=0;j<11;j++){
					  printf("%d ",maze2[i][j]);
				  }
			}
				  printf("\n");
			  }
			}
		if(bt2==0)
		{

			while(IORD(BUTTON2_BASE,0)==bt2);
			sw=IORD(SW_BASE,0);
			switch(sw)
			{
				case 0X08:
					if(up!=1)
					{
						y--;
					}
					break;

				case 0X04:
					if(down!=1)
					{
						y++;
					}
					break;

				case 0X02:
					if(lift!=1)
					{
						x--;
					}
					break;

				case 0x1:
					if(right!=1)
					{
						x++;
					}
					break;

			    case 0x00:
			    	printf("給我動喔!!!!白癡\n");
			    	break;
				default:
					printf("不能走斜的歐\n");
					break;
				}
			}
		if(up!=1){
			a=0x0;
			}else{
				a=0x01;
				}
		if(down!=1){
					b=0x0;
				}else{
					b=0x08;
				}
		if(right!=1){
					c=0x0;
				}else{
					c=0x06;
				}
		if(lift!=1){
					d=0x0;
				}else{
					d=0x30;
				}
		dir=a+b+c+d+0x40;
		IOWR(HEX3_BASE,0,~dir);
		IOWR(HEX2_BASE,0,he0(x));
		IOWR(HEX1_BASE,0,~0x40);
		IOWR(HEX0_BASE,0,he0(y));
//		printf("up=%d\n",up);
//		printf("down=%d\n",down);
//		printf("lift=%d\n",lift);
//		printf("right=%d\n",right);
//		printf("role=%d\n",role);
//		printf("x=%d\n",x);
//		printf("y=%d\n",y);
		if(role==2)
		{
		break;
		}
		usleep(10000);
		}
}


void role_map1(tmp){
	tmp = sPIO.uiPressCnt;
	while(1){
		bt2=IORD(BUTTON2_BASE,0);
		role=maze1[y][x];
		up=maze1[y-1][x];
		down=maze1[y+1][x];
		lift=maze1[y][x-1];
		right=maze1[y][x+1];
		if(tmp != sPIO.uiPressCnt){
			  tmp = sPIO.uiPressCnt;
			if(tmp==0){
			  printf("start game \n");
			}else if(tmp==1){
			  printf("pause game \n");
			  printf("show the map \n");
			  for(i=0;i<11;i++){
				  printf("(%d)、 ",i);
				  for(j=0;j<11;j++){
					  printf("%d ",maze1[i][j]);
				  }
				  printf("\n");
				}
			}
			}
		if(bt2==0)
		{

			while(IORD(BUTTON2_BASE,0)==bt2);
			sw=IORD(SW_BASE,0);
			switch(sw)
			{
				case 0X08:
					if(up!=1)
					{
						y--;
					}
					break;

				case 0X04:
					if(down!=1)
					{
						y++;
					}
					break;

				case 0X02:
					if(lift!=1)
					{
						x--;
					}
					break;

				case 0x1:
					if(right!=1)
					{
						x++;
					}
					break;

			    case 0x00:
			    	printf("給我動喔!!!!白癡\n");
			    	break;
				default:
					printf("不能走斜的歐\n");
					break;
				}
			if(role==2)
			{
			break;
			}
			}
		if(up!=1){
			a=0x0;
			}else{
				a=0x01;
				}
		if(down!=1){
					b=0x0;
				}else{
					b=0x08;
				}
		if(right!=1){
					c=0x0;
				}else{
					c=0x06;
				}
		if(lift!=1){
					d=0x0;
				}else{
					d=0x30;
				}
		dir=a+b+c+d+0x40;
		IOWR(HEX3_BASE,0,~dir);
		IOWR(HEX2_BASE,0,he0(x));
		IOWR(HEX1_BASE,0,~0x40);
		IOWR(HEX0_BASE,0,he0(y));
//		printf("up=%d\n",up);
//		printf("down=%d\n",down);
//		printf("lift=%d\n",lift);
//		printf("right=%d\n",right);
//		printf("role=%d\n",role);
//		printf("x=%d\n",x);
//		printf("y=%d\n",y);

		usleep(10000);
		}
}

