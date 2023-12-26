/*
 * pio.c
 *
 *  Created on: 2022/3/29
 *      Author: lishyhan
 */

#include "pio.h"

//Enable pio Interrupt Routine
void DoEnablePIOInterrupt(sPIO_s *spio);  /* enable pio interrupt */
void DoDisablePIOInterrupt(sPIO_s *spio); /* disable pio interrupt */
void PIOISRInitial(sPIO_s *spio ); /* initial pio ISR function */
void PIOISR(sPIO_s *spio, unsigned int id); /* pio ISR */

//Enable pio Interrupt Routine
void DoEnablePIOInterrupt(sPIO_s *spio)
{
    int i;
#ifdef BUTTON1_BASE
    printf("[MSG][pio]Find BUTTON and start initial pio interrupt.\n");

    i = alt_irq_register( spio->uiIRQ,    /* register IRQ number */
                          spio,           /* pointer to any passed context */
                          spio->ISRFun_p);/* register ISR function */
    /* Setting pio interrupt register */
    IOWR(spio->uiBase, 2, 0x07); /* Set buttion[2:0] pio interrupt */
    IOWR(spio->uiBase, 3, 0);  /* Clear edgecapture flag */
    printf("[MSG][pio]pio interrupt is activated.\n");
#else
    printf("[MSG][pio]Can't find BUTTON pio peripheral. \n");
#endif
}

void DoDisablePIOInterrupt(sPIO_s *spio)/* disable pio interrupt */
{
     alt_irq_register(spio->uiIRQ, 0, 0); /* disable pio */
     IOWR(spio->uiBase, 2, 0); /* Stop pio Interrupt */
     printf("[MSG][pio]pio interrupt is disabled.\n");
}


void PIOISRInitial(sPIO_s *spio ){
    // initial pio
    #ifdef BUTTON1_BASE
        printf("[MSG][pio]Find BTTON pio and start initial process.\n");
        spio->uiBase = BUTTON1_BASE;  /* store button base 	 	  */
        spio->uiIRQ  = BUTTON1_IRQ;   /* store button IRQ number   */
        spio->uiData = 0;            /* set Data variable 		  */
        spio->uiDirection= 0;        /* set Direction variable    */
        spio->uiInterrupt = 0;       /* clear interrupt variable  */
        spio->uiEdgeCapture = 0;     /* set edge capture variable */
        spio->uiPressCnt = 0;     	 /* set edge capture variable */
        spio->ISRFun_p = PIOISR;  	 /* set ISR function name 	  */
        DoEnablePIOInterrupt(spio);  /* Enable interrupt 		  */
    #else
        printf("[MSG][pio]Can't find BUTTON pio.\n");
    #endif
}

// adjust Freq base on phase
void PIOISR(sPIO_s *spio, unsigned int id) {
    IOWR(spio->uiBase, 3, 0);  /* Clear edgecapture flag */
    spio->uiPressCnt++;        /* accumulate interrupt times */
}
