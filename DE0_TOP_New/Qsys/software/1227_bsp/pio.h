#ifndef PIO_H_
#define PIO_H_
/* nios2 system library */
#include <system.h> /* declare nios Ii peripheral function */
#include <sys/alt_irq.h>
#include <priv/alt_legacy_irq.h> /* define alt_irq_register() */
#include <stdio.h> /* declare standard I/O function */
#include <io.h>    /* declare I/O function */

/* PIO structure variable */
typedef struct {

    // for PIO parameters
    unsigned int  uiBase;        /* PIO address base */
    unsigned int  uiIRQ;         /* PIO irq */
    unsigned int  uiData;        /* PIO Data register */
    unsigned int  uiDirection;   /* PIO direction register */
    unsigned int  uiInterrupt;   /* PIO Interrupt mask register */
    unsigned int  uiEdgeCapture; /* PIO edge capture register */
    unsigned int  uiPressCnt;    /* press counter */
    void          *ISRFun_p;     /* ISR function pointer for PIO */
    void          *sNios_p;      /* store sNios_p pointer, declare (void) only for store address  */

} sPIO_s;


#endif /* PIO_H_ */
