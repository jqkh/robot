#include <system.h>
void star_display(int i)
{
	 int num0,num1,num2,num3;

		switch(i)
		{
		case 0:
			num3=0x73;
			num2=0x38;
			num1=0x77;
			num0=0x6E;
			break;
		case 1:
			num3=0x38;
			num2=0x77;
			num1=0x6E;
			num0=0x0;
			break;
		case 2:
			num3=0x77;
			num2=0x6E;
			num1=0x0;
			num0=0x73;
			break;
		case 3:
			num3=0x6E;
			num2=0x0;
			num1=0x73;
			num0=0x38;
			break;
		case 4:
			num3=0x0;
			num2=0x73;
			num1=0x38;
			num0=0x77;
			break;
		}
		IOWR(HEX0_BASE,0,~num0);
		IOWR(HEX1_BASE,0,~num1);
		IOWR(HEX2_BASE,0,~num2);
		IOWR(HEX3_BASE,0,~num3);

}
void end_display(int i)
{
	 int num0,num1,num2,num3,a;

		switch(i)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			num0=1;
			for(a=0;a<i;a++){
				num0=num0<<1;
			}
			num1=0x0;
			num2=0x0;
			num3=0x0;
			break;
		case 4:
			num0=0x0;
			num1=0x8;
			num2=0x0;
			num3=0x0;
			break;
		case 5:
			num0=0x0;
			num1=0x0;
			num2=0x8;
			num3=0x0;
			break;
		case 6:
		case 7:
		case 8:
			num3=4;
			for(a=0;a<i-5;a++){
				num3=num3<<1;
			}
			num1=0x0;
			num2=0x0;
			num0=0x0;
			break;
		case 9:
			num0=0x0;
			num1=0x0;
			num2=0x0;
			num3=0x1;
			break;
		case 10:
			num0=0x0;
			num1=0x0;
			num2=0x1;
			num3=0x0;
			break;
		case 11:
			num0=0x0;
			num1=0x1;
			num2=0x0;
			num3=0x0;
			break;
		case 12:
			num0=0x1;
			num1=0x0;
			num2=0x0;
			num3=0x0;
			break;
		case 13:
			num0=0x2;
			num1=0x0;
			num2=0x0;
			num3=0x0;
			break;
		case 14:
			num0=0x40;
			num1=0x0;
			num2=0x0;
			num3=0x0;
			break;
		case 15:
			num0=0x0;
			num1=0x40;
			num2=0x0;
			num3=0x0;
			break;
		case 16:
			num0=0x0;
			num1=0x0;
			num2=0x40;
			num3=0x0;
			break;
		case 17:
			num0=0x0;
			num1=0x0;
			num2=0x0;
			num3=0x40;
			break;
		case 18:
			num0=0x0;
			num1=0x0;
			num2=0x0;
			num3=0x20;
			break;
		case 19:
			num0=0x0;
			num1=0x0;
			num2=0x0;
			num3=0x1;
			break;
		case 20:
			num0=0x0;
			num1=0x0;
			num2=0x1;
			num3=0x0;
			break;
		case 21:
			num0=0x0;
			num1=0x1;
			num2=0x0;
			num3=0x0;
			break;
		default:
			num0=0x0;
			num1=0x0;
			num2=0x0;
			num3=0x0;
			break;
		}
		IOWR(HEX0_BASE,0,~num0);
		IOWR(HEX1_BASE,0,~num1);
		IOWR(HEX2_BASE,0,~num2);
		IOWR(HEX3_BASE,0,~num3);

}



