/**
 * \file   systick.c
 *
 * \brief  system timer tick routines
 *
*/

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


#include "systick.h"
#include "soc_AM335x.h"
#include "beaglebone.h"
#include "interrupt.h"
#include "dmtimer.h"

/* The Input clock is selected as 24MHz. So for 1ms set the count to 0x5DC0.
 *If the input clock is changed to different source this value has to be updated
 *accordingly.
*/
#define TIMER_1MS_COUNT         (0x5DC0u)
#define TIMER_OVERFLOW          (0xFFFFFFFFu)

#define TMR_INTRNUM             SYS_INT_TINT4
#define TMR_MDLREG              SOC_DMTIMER_4_REGS
#define TMR_CLKCNFG             DMTimer4ModuleClkConfig

// function pointer for ISR to be executed on Timer Interrupt
void (*pfnTimerTickISR)(void);

void TimerTickISR(void)
{
    /* Disable the DMTimer interrupts */
    DMTimerIntDisable(TMR_MDLREG, DMTIMER_INT_OVF_EN_FLAG);

    /* Clear the status of the interrupt flags */
    DMTimerIntStatusClear(TMR_MDLREG, DMTIMER_INT_OVF_IT_FLAG);

    pfnTimerTickISR();

    /* Enable the DMTimer interrupts */
    DMTimerIntEnable(TMR_MDLREG, DMTIMER_INT_OVF_EN_FLAG);
}

void TimerTickConfigure(void (*pfnHandler)(void))
{    
    pfnTimerTickISR = pfnHandler;

    /* This function will enable clocks for the DMTimer instance */
    TMR_CLKCNFG();

    /* Registering DMTimerIsr */
    IntRegister(TMR_INTRNUM, TimerTickISR);

    /* Set the priority */
    IntPrioritySet(TMR_INTRNUM, 0, AINTC_HOSTINT_ROUTE_IRQ);

    /* Enable the system interrupt */
    IntSystemEnable(TMR_INTRNUM);

    DMTimerCounterSet(TMR_MDLREG, 0);

    /* Configure the DMTimer for Auto-reload and compare mode */
    DMTimerModeConfigure(TMR_MDLREG, DMTIMER_AUTORLD_NOCMP_ENABLE);
}

void TimerTickPeriodSet(unsigned int ulTime)
{
    unsigned int countVal = TIMER_OVERFLOW - (ulTime * TIMER_1MS_COUNT);

    /* Load the counter with the initial count value */
    DMTimerCounterSet(TMR_MDLREG, countVal);

    /* Load the load register with the reload count value */
    DMTimerReloadSet(TMR_MDLREG, countVal);
}

void TimerTickEnable(void)
{	
    if(pfnTimerTickISR == NULL)
    {
        // Do not enable the Timer Interrupt if Timer ISR function pointer is NULL
        return;
    }
    /* Enable the DMTimer interrupts */
    DMTimerIntEnable(TMR_MDLREG, DMTIMER_INT_OVF_EN_FLAG);

    /* Start the DMTimer */
    DMTimerEnable(TMR_MDLREG);
}

void TimerTickDisable(void)
{
    /* Disable the DMTimer interrupts */
    DMTimerIntDisable(TMR_MDLREG, DMTIMER_INT_OVF_EN_FLAG);

    /* Clear the status of the interrupt flags */
    DMTimerIntStatusClear(TMR_MDLREG, DMTIMER_INT_OVF_IT_FLAG);

    /* Start the DMTimer */
    DMTimerDisable(TMR_MDLREG);
}



