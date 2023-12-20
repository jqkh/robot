/* ���Ubutton���ͤ��_�A �ö}�l�p�ƫ��s���� */
#include <stdio.h>
#include <system.h> /* �t�μзǨ�ܮw */
#include <io.h>     /* �t��I/O��ܮw*/
#include <unistd.h> /* �ŧiusleep��� */
#include "pio.h" /* �ŧipio��� */
#include "pio.c" /* �ŧipio��� */

extern void PIOISRInitial(sPIO_s *sPIO ); /* decalare external initial PIO ISR function */

int main()/* C �D�{�� */
{
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
