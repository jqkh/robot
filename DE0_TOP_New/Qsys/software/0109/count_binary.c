#include <stdio.h> /* 系統標準輸出入函式庫 */
#include <system.h>/* 系統函式庫 */
#include <io.h>    /* 系統I/O函式庫*/
#include <unistd.h>/* 宣告 usleep 函數 */
#include <stdlib.h>/* 系統標準控制函式庫 */
#include "star.c"  /*開始關卡跟完成關卡動畫*/
#include "pio.h"   /*宣告pio函數*/
#include "pio.c"   /*宣告pio函數*/
#include "hex.c"   /*七段顯示器解碼函數*/
#include "Role.c"  /*人物周圍、移動判斷與程式中斷執行主要程式執行*/

unsigned int tmp;

sPIO_s sPIO;

int main(){
	int i=0,bt2=0,time=0,a,f;
	int led=1;
    printf("遊戲規則:\n開關總共有四個(sw3:0)從大到小分別控制人物上下左右當撥好，指定的開關時按下button2即可使人物向指定方向前進\n");
    printf("當需要提示時可以按下button1暫停遊戲並顯示遊戲地圖\n再次按下button1即可返回遊戲\n");
    printf("ps:地圖不是我用的過不了別找我\n");
    printf("按下button開始遊戲");
	IOWR(HEX0_BASE,0,~0x0);
	IOWR(HEX1_BASE,0,~0x0);
	IOWR(HEX2_BASE,0,~0x0);
	IOWR(HEX3_BASE,0,~0x0);
	IOWR(LED_BASE,0,0x0);
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
			   IOWR(HEX0_BASE,0,~0x0);
			   IOWR(HEX1_BASE,0,~0x0);
			   IOWR(HEX2_BASE,0,~0x0);
			   IOWR(HEX3_BASE,0,~0x0);
			   while(IORD(BUTTON2_BASE,0)==bt2);
				printf("\n遊戲開始\n");
			   PIOISRInitial(&sPIO); /* 初始化ISR函數 */
			   	tmp = sPIO.uiPressCnt;
			   	srand(time);
			   	f= (rand()%4);
			   	printf("\n以隨機選擇地圖%d\n",f+1);
			   	IOWR(HEX0_BASE,0,he0(f+1));
			   	usleep(300000);
				IOWR(HEX0_BASE,0,~0x0);
			   	switch(f){
			   	case 0:
			   		role_map1(tmp);
			   		break;
			   	case 1:
			   		role_map2(tmp);
			   		break;
			   	case 2:
			   		role_map3(tmp);
			   		break;
			   	case 3:
			   		role_map4(tmp);
			   		break;
			   	default:
			   		printf("error");
			   		break;
			   	}
			   break;
		  }
	}
	i=0;
	printf("you win");
	while(1){
		if( a==0){
		led=led<<1;
		}else if(a==1){
		led=led>>1;
		}
		if(led>=0x200){
			a=1;
		}else if(led==1){
			a=0;
		}
		if(i>=22){
			i=0;
		}
		end_display(i);
		i++;
		IOWR(LED_BASE,0,led);
		usleep(50000);
	}
return 0;
}
