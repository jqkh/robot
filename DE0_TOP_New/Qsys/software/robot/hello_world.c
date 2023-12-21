/* ���Ubutton���ͤ��_�A �ö}�l�p�ƫ��s���� */
#include <stdio.h>
#include <system.h> /* �t�μзǨ�ܮw */
#include <io.h>     /* �t��I/O��ܮw*/
#include <unistd.h> /* �ŧiusleep��� */
#include "pio.h" /* �ŧipio��� */
#include "pio.c" /* �ŧipio��� */
void star_display(int i);
extern void PIOISRInitial(sPIO_s *sPIO ); /* decalare external initial PIO ISR function */

int main()/* C �D�{�� */
{
  int i=0;
  while(1)
  {
	  if(i>3)
	  {
	  	i=0;
	  }
	  star_display(i);
	  i++;
	  if(IORD(BUTTON2_BASE,0)==0)
	  {
		  printf("hi");
		  break;
	  }
  }
  unsigned int tmp;
  sPIO_s sPIO; /* �ŧiPIO ���c�ܼ�*/
  printf("PIO interrupt experimental!\n");
  PIOISRInitial(&sPIO); /* ��l��ISR��� */
  tmp = sPIO.uiPressCnt;
  while(1)
  {
      if(tmp != sPIO.uiPressCnt)
      {
    	  printf("Press Counter=%3d.\n", sPIO.uiPressCnt);
    	  tmp = sPIO.uiPressCnt;
      }
  }
  return 0;
}
void star_display(int i)
{
	 int num0,num1,num2,num3;

	 	usleep(200000);
		switch(i)
		{
		case 0:
			num3=0x73;
			num2=0x38;
			num1=0x77;
			num0=0x66;
			break;
		case 1:
			num3=0x38;
			num2=0x77;
			num1=0x66;
			num0=0x73;
			break;
		case 2:
			num3=0x77;
			num2=0x66;
			num1=0x73;
			num0=0x38;
			break;
		case 3:
			num3=0x66;
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
