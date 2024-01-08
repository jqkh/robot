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
#include "Role.c"

unsigned int tmp;

sPIO_s sPIO;

int main(){
	int i=0,bt2=0,time=0,a,f;
	int led=1;
    printf("�C���W�h:\n�}���`�@���|��(sw3:0)�q�j��p���O����H���W�U���k���n�A���w���}���ɫ��Ubutton2�Y�i�ϤH���V���w��V�e�i\n");
    printf("��ݭn���ܮɥi�H���Ubutton1�Ȱ��C������ܹC���a��\n�A�����Ubutton1�Y�i��^�C��\n");
    printf("ps:�a�Ϥ��O�ڥΪ��L���F�O���");
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
				printf("\n�C���}�l\n");
			   PIOISRInitial(&sPIO); /* ��l��ISR��� */
			   	tmp = sPIO.uiPressCnt;
			   	srand(time);
			   	f= (rand()%4);
			   	printf("\n�H�H����ܦa��%d\n",f+1);
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
