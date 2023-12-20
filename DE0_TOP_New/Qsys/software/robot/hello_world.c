/* button玻ネい耞 秨﹍璸计秙Ω计 */
#include <stdio.h>
#include <system.h> /* ╰参夹非ㄧボ畐 */
#include <io.h>     /* ╰参I/Oㄧボ畐*/
#include <unistd.h> /* usleepㄧ计 */
#include "pio.h" /* pioㄧ计 */
#include "pio.c" /* pioㄧ计 */

extern void PIOISRInitial(sPIO_s *sPIO ); /* decalare external initial PIO ISR function */

int main()/* C 祘Α */
{
  unsigned int tmp;
  sPIO_s sPIO; /* PIO 挡篶跑计*/
  printf("PIO interrupt experimental!\n");
  PIOISRInitial(&sPIO); /* ﹍てISRㄧ计 */
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
